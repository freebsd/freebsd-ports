diff -urN bidwatcher-1.3.16/netstuff.cpp bidwatcher-1.3.16-SSL-2/netstuff.cpp
--- netstuff.cpp.orig	2004-08-21 13:45:12.000000000 +0200
+++ netstuff.cpp	2004-12-14 17:09:44.000000000 +0100
@@ -23,189 +23,73 @@
 // GNU General Public License for more details.
 //
 
-#include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <errno.h>
-#include <fcntl.h>
-#include <unistd.h>
-#include <sys/time.h>
-#include <time.h>
-#include <netinet/in.h>
-#include <sys/socket.h>
-#include <sys/utsname.h>
-#include <netdb.h>
 #include <gtk/gtk.h>
+#include <curl/curl.h>
+#include <curl/types.h>
+#include <curl/easy.h>
 #include "bidwatcher.h"
 
-bool cancelPressed;
-double avg_load_time = INITIAL_LOAD_TIME;
+// The next two functions are essentially taken from the examples
+// that come with the curl library.  For speed we don't want to
+// start with an empty buffer, so memsize should be larger than size.
+
+struct MemoryBufferStruct {
+  char *memory;            // This is the character array
+  size_t size;             // This is the length of the string
+  size_t memsize;          // This is the actual length of the array
+};
 
-char cookie[512];
-
-void getAdultCookie(char * username, char * password) {
-  char *ustring = g_strdup_printf("http://cgi.ebay.com/aw-cgi/eBayISAPI.dll"
-				  "?MfcISAPICommand=AdultLogin&userid=%s&"
-				  "password=%s", username, password);
-  URL *url = new URL(ustring, proxyurl);
-  g_free(ustring);
-
-  char *HtmlBuff;
-  fetchURL(url, 0, &HtmlBuff, TIMEOUT, 0);
-  char *adultcookie=strstr(HtmlBuff,"Set-Cookie");
-  if (adultcookie==NULL) {
-    fprintf(stderr, "adult cookie not found:\n");
-    fprintf(stderr, HtmlBuff);
-    free(HtmlBuff);
-    return;
+size_t WriteMemoryBuffer(void *ptr, size_t size, size_t nmemb, void *data)
+{
+  register int realsize = size * nmemb;
+  struct MemoryBufferStruct *mem = (struct MemoryBufferStruct *)data;
+  if( (size_t) (realsize) > (mem->memsize - mem->size) ) {
+    mem->memory = (char *)realloc(mem->memory, mem->size + realsize + 1);
+    mem->memsize = mem->size + realsize + 1;
   }
-  int len=strcspn(adultcookie,";");
-  adultcookie[len]='\0';
-  printf("Adult cookie: %s\n",adultcookie+4); // strip "Set-"
-  strcpy(cookie,adultcookie+4);
-  free(HtmlBuff);
-}
-
-/* necessary because otherwise, all hostents are identical, and overwritten
-   every time gethostbyname is called! :( */
-int copyhostent(struct hostent *in, struct hostent *out,
-		int *numaliases, int *numaddrs) {
-
-  if (in==NULL) return 0;
-
-  //  struct hostent *out = (struct hostent *) malloc(sizeof(struct hostent));
-  out->h_name = g_strdup(in->h_name);
-  int i;
-
-  /* Count number of aliases */
-  for(i=0; in->h_aliases[i] != 0; i++);
-
-  if (i > 0)
-    out->h_aliases = (char **) malloc(sizeof(char *) * i);
-
-  *numaliases = i;
-
-  for(i=0; in->h_aliases[i] != 0; i++)
-    out->h_aliases[i] = g_strdup(in->h_aliases[i]);
-
-  out->h_addrtype = in->h_addrtype;
-  out->h_length = in->h_length;
-
-  /* Count number of addresses */
-  for(i=0; in->h_addr_list[i] != 0; i++);
-
-  if (i > 0)
-    out->h_addr_list = (char **) malloc(sizeof(char *) * i);
-
-  *numaddrs = i;
-
-  for(i=0; in->h_addr_list[i] != 0; i++) {  // thanks Rodd Snook
-    out->h_addr_list[i] = (char *) malloc(sizeof(char) * in->h_length);
-    memcpy(out->h_addr_list[i], in->h_addr_list[i], in->h_length);
+  if (mem->memory) {
+    memcpy(&(mem->memory[mem->size]), ptr, realsize);
+    mem->size += realsize;       // Update the string length 
+    mem->memory[mem->size] = 0;  // Terminate the string with a NULL
   }
-
-  return 1;
+  return realsize;
 }
 
+struct MemoryBufferStruct curl_memory_chunk;
 
-URL::URL(char *newurl, URL *proxy) {
+bool cancelPressed;
+double avg_load_time = INITIAL_LOAD_TIME;
+
+URL::URL(char *newurl, char *postval, URL *proxy) {
     DPRINTF(DMED, ("New URL(%s).\n", newurl));
-    hostinfo = (struct hostent *) malloc(sizeof(struct hostent));
-    memset(hostinfo, 0, sizeof(struct hostent));
-    numaddrs = 0;
-    numaliases = 0;
     proxyuser = NULL;
     proxypass = NULL;
-    create(newurl, proxy);
+    create(newurl, postval, proxy);
 }
 
-URL::URL(char *newurl, URL *proxy, char *user, char *pass) {
+URL::URL(char *newurl, char *postval, URL *proxy, char *user, char *pass) {
     DPRINTF(DMED, ("New URL(%s).\n", newurl));
-    hostinfo = (struct hostent *) malloc(sizeof(struct hostent));
-    memset(hostinfo, 0, sizeof(struct hostent));
-    numaddrs = 0;
-    numaliases = 0;
     proxyuser = strdup(user);
     proxypass = strdup(pass);
-    create(newurl, proxy);
+    create(newurl, postval, proxy);
 }
 
 URL::~URL() {
-  // Clean this memory waster up.
-  int i;
-  DPRINTF(DMED, ("Destroying URL(%s)\n", url));
-
-  // If we are using a proxy, don't kill this.
-  if (!useproxy && hostinfo) {
-    if (hostinfo->h_name)
-      free(hostinfo->h_name);
-
-    for(i=0; i < numaliases; i++)
-      free(hostinfo->h_aliases[i]);
-
-    if (i > 0)
-      free(hostinfo->h_aliases);
-
-    for(i=0; i < numaddrs; i++)
-      free(hostinfo->h_addr_list[i]);
-
-    if (i > 0)
-      free(hostinfo->h_addr_list);
-
-    free(hostinfo);
-  }
-
+  DPRINTF(DMED, ("Destroying URL(%s)\n", fullurl));
   if(proxyuser != NULL) free(proxyuser);
   if(proxypass != NULL) free(proxypass);
 }
 
-void URL::create(char *newurl,URL *proxy) {
-  char *hostoff = strstr(newurl, "://") + 3;
+void URL::create(char *newurl, char *postval, URL *proxy) {
 
-  // Hmm, size_t isn't really an int, but this shouldn't affect us.
-  sprintf(hoststring, "%.*s", (int)strcspn(hostoff, "/"), hostoff);
+  sprintf(fullurl,"%s",newurl);
+  sprintf(fullurlpost,"%s",postval);
 
   if (proxy == NULL) {
-    char tmpstr[256];
-
     useproxy = FALSE;
-
-    strcpy(tmpstr, hoststring);
-    if (strlen(tmpstr) < strlen(hostoff)) {
-      strcpy(url, hostoff + strlen(tmpstr));
-    } else url[0] = '\0';
-
-    char *portoff = strstr(tmpstr, ":");
-    if (portoff != NULL) {
-      port = atoi(portoff + 1);
-      portoff[0] = '\0';
-    } else port = 80;
-
-
-    if (hostinfo) {
-      // Destroy it before we malloc more.
-      int i;
-
-      if (hostinfo->h_name)
-	      g_free(hostinfo->h_name);
-
-      for(i=0; i < numaliases; i++)
-	  g_free(hostinfo->h_aliases[i]);
-
-      if (numaliases > 0)
-	  free(hostinfo->h_aliases);
-
-      for(i=0; i < numaddrs; i++)
-	  free(hostinfo->h_addr_list[i]);
-
-      if (numaddrs > 0)
-	  free(hostinfo->h_addr_list);
-
-      //free(hostinfo);
-    }
-    copyhostent(gethostbyname(tmpstr), hostinfo, &numaliases, &numaddrs);
-
   } else {
 #ifdef DEBUG_NETWORK
     printf("Configured for proxy - host: %s, port: %d\n",
@@ -213,317 +97,149 @@
 	   proxy->port);
 #endif
     useproxy = TRUE;
-    hostinfo = proxy->hostinfo;
-    port = proxy->port;
     proxyuser = strdup(proxy->proxyuser);
     proxypass = strdup(proxy->proxypass);
-    strcpy(url, newurl);
   }
 }
 
-void CloseSocket(int sockIT)
-{
-   close(sockIT);
-}
-
-int set_nonblock(int fd)
-{
-    int flags = fcntl(fd, F_GETFL, 0);
-    if (flags == -1)
-        return -1;
-    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
-}
-
 bool checkredir(URL *url, char *buff) {
-  if (strstr(buff,"HTTP/1.0 30")!=NULL || strstr(buff,"HTTP/1.1 30")!=NULL) {
-    char *loc = stristr(buff,"Location:");
-
-    if (loc == NULL) {
-      showError("Redirection without Location header!\n");
-      return FALSE;
-    }
-    else
-      loc += 10;  // strlen("Location: ");
 
-    loc[strcspn(loc,"\r\n ")]='\0';
+  // We are extracting the URL from a string of the form
+  // location: http://...
+  if (strstr(buff,"location: http") != NULL) {
+    char *loc = stristr(buff,"location: http");
+    loc = loc + 10;
+    loc[strcspn(loc,"\r\n")] = '\0';
+    sprintf(url->fullurl,"%s\n",loc);
+    return TRUE;
+  }
 
-    if (strstr(loc,"AdultLoginShow")) {
-#ifdef DEBUG_NETWORK
-      printf("Getting adult cookie\n");
-#endif
-      getAdultCookie(authID,authPASS);
-      if (strlen(cookie)<5) showError("Could not get adult cookie.");
-    } else url->create(loc,proxyurl);
-#ifdef DEBUG_NETWORK
-    printf("Relocated to %s\n",loc);
-#endif
+  // We are extracting the URL from a string of the form
+  // Location: http://...
+  if (strstr(buff,"Location: http") != NULL) {
+    char *loc = stristr(buff,"Location: http");
+    loc = loc + 10;
+    loc[strcspn(loc,"\r\n")] = '\0';
+    sprintf(url->fullurl,"%s\n",loc);
     return TRUE;
   }
-  else return FALSE;
-}
 
-int fetchURL(URL *url, int Post, char **Buff, double timeOut, int redir)
-{
-  int    buffLength,recerr;
-  int    socketID;
-  char   UserAgent[256];
-  char   lineBuff[1024];
-  char   htmlBuff[HUGEBUFF];
 
-  struct    utsname     utsbuf;
+  // We are extracting the URL from a string of the form
+  // <meta http-equiv="Refresh" content="0; url = http://...">
+  // First we seek to the end of the "url =" part, then start
+  // counting until we hit the ending " mark.  Could we just
+  // link to a regular expression library instead?
 
-  struct    sockaddr_in soc_in;
-  int	  err;
-  fd_set fds;
-  struct timeval tm;
+  if (strstr(buff,"<meta http-equiv=\"Refresh\" content=") != NULL) {
+    char *loc = stristr(buff,"<meta http-equiv=\"Refresh\" content=");
+    loc = loc + 35;
+    while ( (*loc != '\0') && (*loc != '"' ) ){
+      loc++;
+    }
 
-  *Buff = NULL;
+    if( *loc != '\0' ) loc++;
 
-  GTimer * time_since_start=g_timer_new();
-  g_timer_start(time_since_start);
+    while ( (*loc != '\0') && (*loc != '=' ) && (*loc != '"' ) ){
+      loc++;
+    }
 
-  memset(htmlBuff, 0, sizeof(htmlBuff));
+    if( *loc == '=' ) loc++;
 
-  memset((char*) &soc_in, 0, sizeof(soc_in));
-  soc_in.sin_family = AF_INET;
+    while (*loc == ' ' ){
+      loc++;
+    }
 
-  struct hostent * hostinfo;
+    int substring_len = 0;
 
-  hostinfo=url->hostinfo;
-  if ((hostinfo == NULL) || (hostinfo->h_length == 0)
-      || (hostinfo->h_addr == NULL)) {
-    // DNS error
-    g_free(time_since_start);
-    return NET_NETERROR;
-  }
-  soc_in.sin_addr=*(struct in_addr*)hostinfo->h_addr;
-  soc_in.sin_port = htons(url->port);
+    while ( loc[substring_len] != '\0' &&  (loc[substring_len]) != '"' ) {
+      substring_len++;
+    }
+
+    sprintf(url->fullurl,"%.*s\n",substring_len,loc);
+
+    return TRUE;
 
-  socketID = socket(AF_INET, SOCK_STREAM, 0);
-  if (socketID < 0) {
-    g_free(time_since_start);
-    return NET_NETERROR;
   }
 
-  set_nonblock(socketID);
-  err = connect(socketID, (struct sockaddr *)&soc_in, sizeof (soc_in));
+  return FALSE;
+}
 
-  if (err < 0) {
-    if (errno == EINPROGRESS) {
-      FD_ZERO(&fds);
-      FD_SET(socketID,&fds);
-      tm.tv_sec = int(timeOut / 2);
-      tm.tv_usec=0;
-      err = select(socketID+1,NULL,&fds,NULL,&tm);
+int fetchURL(URL *url, int Post, char **Buff, char *cookiejar, int redir)
+{
+  size_t avebuffsize = 1 << 15;   // 2 to the 15th power
+  CURL *curl_handle;
 
-      if (err == 0) {
-#ifdef DEBUG_NETWORK
-	fprintf(stderr, "connection timed out\n");
-#endif
-	CloseSocket(socketID);
-	g_free(time_since_start);
-	return NET_TIMEOUT;
-      }
-    }
-    else {
-#ifdef DEBUG_NETWORK
-      fprintf(stderr,
-	      "connection failed immediately:  err=%d  errno=%d (%s)\n",
-	      err, errno, strerror( errno ) );
-#endif
-      CloseSocket(socketID);
-      g_free(time_since_start);
-      return NET_NETERROR;
-    }
-  }
+  curl_memory_chunk.memory = (char *) malloc(avebuffsize*sizeof(char));
+  curl_memory_chunk.size = 0;
+  curl_memory_chunk.memsize = avebuffsize;
 
-  // did we connect, or not?
-  err = 0;
+  // Initialize the curl session
+  curl_handle = curl_easy_init();
 
-  {
-    socklen_t arglen = sizeof(int);
+  // Return both the headers and the body
+  curl_easy_setopt(curl_handle, CURLOPT_HEADER, 1);
+  curl_easy_setopt(curl_handle, CURLOPT_NOBODY, 0);
 
-    /* this is slightly grotty to avoid problems with SysV, where    */
-    /* apparently getsockopt() will fail with an async error, rather */
-    /* that return it like it's supposed to.                         */
+  // Automatically handle all the cookies
+  curl_easy_setopt(curl_handle, CURLOPT_COOKIEJAR, cookiejar);
+  curl_easy_setopt(curl_handle, CURLOPT_COOKIEFILE, cookiejar);
 
-    if (getsockopt(socketID,SOL_SOCKET,SO_ERROR,(void *)&err,&arglen) < 0)
-      err = errno;
-  }
+  // Act like we are the mozilla browser
+  curl_easy_setopt(curl_handle, CURLOPT_USERAGENT,
+      "Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.6) Gecko/20040113");
 
-  if (err != 0) {
-#ifdef DEBUG_NETWORK
-    fprintf(stderr,
-	    "connection failed:  err=%d  errno=%d (%s)\n",
-	    err, errno, strerror(errno));
-#endif
-    CloseSocket(socketID);
-    g_free(time_since_start);
-    return NET_NETERROR;
+  // This next feature doesn't appear to work properly so we follow by hand
+  curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1);
+
+  // Someone should make the proxy feature work properly
+  // This is only a guess of how it might work
+  if( url->useproxy ) {
+    char proxyuserpwd[200];
+    sprintf(proxyuserpwd,"%s:%s",url->proxyuser,url->proxypass);
+    curl_easy_setopt(curl_handle,CURLOPT_PROXYUSERPWD,proxyuserpwd);
   }
 
-  if (uname(&utsbuf) < 0)
-    UserAgent[0] = '\0';
-  else
-    sprintf(UserAgent, "User-Agent: Mozilla/5.0 (X11; U; %s %s; en-US; rv:1.5) Gecko/20031115 Firebird/0.7\r\n", utsbuf.sysname, utsbuf.machine);
+  // Set the URL we wish to fetch
+  curl_easy_setopt(curl_handle, CURLOPT_URL,  url->fullurl);
 
-  // send our request for the web page.
-  // XXX: Took out the cookie for now cuz we're not yet using it.
+  // If we are posting, set the post fields
   if (Post) {
-    int URLLen;
-    char *Args;
-
-    URLLen = strcspn(url->url, "?");
-    Args = &url->url[URLLen];
-    if (*Args != '\0')
-      Args++;
-
-    // do we need to authenticate through the proxy?
-    // check both user and password because I am not sure if it is possible
-    // that one or the other could be blank...we'll be safe
-    if(url->proxyuser == NULL && url->proxypass == NULL) {
-      // no.
-      sprintf(lineBuff, "POST %.*s HTTP/1.1\r\nHost: %s\r\n%sConnection: close\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n\r\n%s",
-	      URLLen,
-	      url->url,
-	      url->hoststring,
-	      UserAgent,
-	      strlen(Args),
-	      Args);
-    } else {
-      // yes, encode the proxy's username and password and insert it into the header
-      char *encstr = NULL;
-      basic_authentication_encode(url->proxyuser, url->proxypass, &encstr);
-      sprintf(lineBuff, "POST %.*s HTTP/1.1\r\nConnection: close\r\nHost: %s\r\nPragma: no-cache\r\nCache-control: no-cache\r\nProxy-Authorization: %s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: %i\r\n%s\r\n%s",
-	      URLLen,
-	      url->url,
-	      url->hoststring,
-	      encstr,
-	      strlen(Args),
-	      UserAgent,
-	      Args);
-      free(encstr);
-    }
-  } else if(url->proxyuser == NULL && url->proxypass == NULL) {
-    // do we need to authenticate through the proxy? no.
-    sprintf(lineBuff, "GET %s HTTP/1.1\r\nConnection: close\r\nHost: %s\r\nPragma: no-cache\r\nCache-control: no-cache\r\n%s\r\n",
-	    url->url,
-	    url->hoststring,
-	    UserAgent);
-  } else {
-    // yes, encode the proxy's username and password and insert it into the header
-    char *encstr = NULL;
-    basic_authentication_encode(url->proxyuser, url->proxypass, &encstr);
-    sprintf(lineBuff, "GET %s HTTP/1.1\r\nConnection: close\r\nHost: %s\r\nPragma: no-cache\r\nCache-control: no-cache\r\nProxy-Authorization: %s\r\n%s\r\n",
-	    url->url,
-	    url->hoststring,
-	    encstr,
-	    UserAgent);
-    free(encstr);
+    curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, url->fullurlpost);
   }
 
-#ifdef DEBUG_NETWORK
-  printf("HTTP request header:\r\n%s", lineBuff);
-#endif
+  // All the data will be sent to this function by curl
+  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryBuffer);
 
-  if (send(socketID, lineBuff, strlen(lineBuff), 0) < 0) {
+  // We will need our memory buffer to be pass to the write function
+  curl_easy_setopt(curl_handle, CURLOPT_FILE, (void *)&curl_memory_chunk);
 
-#ifdef DEBUG_NETWORK
-    fprintf(stderr,
-	    "could not send URL:  errno=%d (%s)\n",
-	    errno, strerror(errno));
-#endif
-    CloseSocket(socketID);
-    g_free(time_since_start);
-    return NET_NETERROR;
-  }
+  // Now get that URL
+  if (CURLE_OK == curl_easy_perform(curl_handle)) {
 
-  buffLength = 0;
-
-  int counter = 0;
-  bool goodcall = TRUE;
-  GTimer * time_since_pkt=g_timer_new();
-  g_timer_start(time_since_pkt);
-
-  while (goodcall) {
-    if (cancelPressed) {
-      g_free(time_since_pkt);
-      g_free(time_since_start);
-      return NET_USERCANCEL;
-    }
-    if (counter == 5) {
-      counter = 0;
-      gtk_main_iteration_do(FALSE);
-      if (g_timer_elapsed(time_since_start,NULL) > timeOut) {
-	CloseSocket(socketID);
-	g_free(time_since_pkt);
-	g_free(time_since_start);
-	return NET_TIMEOUT;
-      }
-
-      if (g_timer_elapsed(time_since_pkt,NULL) > timeOut/2) {
-	CloseSocket(socketID);
-	g_free(time_since_pkt);
-	g_free(time_since_start);
-	return NET_TIMEOUT;
-      }
-    }
-    recerr = recv(socketID, lineBuff, 256, 0);
-    if (recerr < 0) {
-      if (errno != EWOULDBLOCK) {
-	goodcall = FALSE;
-	break;
-      }
-      goodcall = TRUE;
-      gtk_main_iteration_do(FALSE);
-      usleep(10000);
-      counter++;
+    // If we haven't hit redirect limit, follow any redirects
+    if ( redir && checkredir(url,curl_memory_chunk.memory) ) {
+      /* cleanup curl stuff */
+      curl_easy_cleanup(curl_handle);
+      return fetchURL(url, 0, Buff, cookiejar, redir - 1);
     }
-    else if (recerr == 0)
-      break;
-    else {
-      if ((buffLength + recerr) < HUGEBUFF) {
-	g_timer_reset(time_since_pkt);
-	counter = 0;
-	buffLength = buffLength + recerr;
-	lineBuff[recerr] = '\0';
-	strncat(htmlBuff, lineBuff, recerr);
-	goodcall = TRUE;
-      }
-      else break;
-    }
-  }
-  CloseSocket(socketID);
 
-  if (checkredir(url, htmlBuff)) {
-    g_free(time_since_pkt);
-    g_free(time_since_start);
-
-    DPRINTF(DLOW, ("Redirection detected: %s%s\n", url->hoststring, url->url));
-
-    /* Terminal point for recursion. */
-    if (redir > MAX_REDIR) {
-      DPRINTF(DLOW, ("Maximum redirection reached.\n"));
-      showError("Maximum redirection reached!");
-      return NET_MAXREDIR;
-    }
-    else
-      return fetchURL(url, 0, Buff, timeOut, redir+1);
+    // Set the buffer pointer to the curl memory buffer
+    *Buff= curl_memory_chunk.memory;
 
-  } else {
-    if (!goodcall) {
-      g_free(time_since_pkt);
-      g_free(time_since_start);
-      return NET_NETERROR;
-    }
-    /* make and copy buffer */
-    *Buff=(char *)malloc(buffLength+1);
-    strnzcpy(*Buff,htmlBuff,buffLength);
+    /* cleanup curl stuff */
+    curl_easy_cleanup(curl_handle);
 
-    g_free(time_since_start);
-    g_free(time_since_pkt);
     return NET_SUCCESS;
+
+  } else {
+
+    /* cleanup curl stuff */
+    curl_easy_cleanup(curl_handle);
+    
+    return NET_NETERROR;
   }
+    
 }
 
 
