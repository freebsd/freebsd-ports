--- identify.c.orig	Tue Feb  2 01:51:57 1993
+++ identify.c	Sun Oct 20 17:53:44 2002
@@ -11,7 +11,7 @@
 #include <stdio.h>
 #include <signal.h>
 #include <syslog.h>
-#include <authuser.h>
+#include <ident.h>
 #include <netdb.h>
 #include <sys/types.h>
 #include <netinet/in.h>
@@ -33,57 +33,43 @@
 int noidentify = 0;
 int bits = 0;
 int reject_flag = 0;
-unsigned long inlocal;
-unsigned long inremote;
+struct in_addr inlocal;
+struct in_addr inremote;
 int timeout = 120;
-int rtimeout = 30;
-
-static char *host_address(ad)
-  unsigned long ad;
-{
-  int a, b, c, d;
-  static char addr[20];
-  
-  d = ad % 256;
-  ad /= 256;
-  c = ad % 256;
-  ad /= 256;
-  b = ad % 256;
-  a = ad / 256;
-  sprintf(addr, "%d.%d.%d.%d", a, b, c, d);
-  
-  return addr;
-}
-
 
 char *ident_get_identifier(fd, host, len)
   int fd;
   char *host;
   int len;
 {
-  unsigned short local;
-  unsigned short remote;
-
+  struct sockaddr_in sa;
+  int l;
 
-  if (auth_fd2(fd, &inlocal, &inremote,
-	       &local, &remote) == -1)
+  l=sizeof(sa);
+  if (getsockname(fd,(struct sockaddr *)&sa,&l)<0)
   {
     if (debug)
-      perror("auth_fd2");
-    
+      perror("getsockname()");
     return NULL;
   }
+  inlocal=sa.sin_addr;
+  if (getpeername(fd,(struct sockaddr *)&sa,&l)<0)
+  {
+    if (debug)
+      perror("getpeername()");
+    return NULL;
+  }
+  inremote=sa.sin_addr;
 
   if (host)
   {
     struct hostent *hp;
 
-  
-    hp = gethostbyaddr(&inremote,sizeof(struct in_addr),AF_INET);
+    hp = gethostbyaddr((const char *)&inremote,sizeof(struct in_addr),AF_INET);
     if (hp)
       strncpy(host, hp->h_name, len);
     else
-      strncpy(host, host_address(inremote), len);
+      strncpy(host, inet_ntoa(inremote), len);
     
     host[len] = '\0';
   }
@@ -91,16 +77,7 @@
   if (noidentify)
     return NULL;
   else
-    if (timeout)
-    {
-	if (rtimeout)
-	    return auth_tcpuser4(inlocal, inremote, local, remote, timeout,
-				 rtimeout);
-	else
-	    return auth_tcpuser3(inlocal, inremote, local, remote, timeout);
-    }
-    else
-      return auth_tcpuser2(inlocal, inremote, local, remote);
+    return ident_id(fd,timeout);
 }
 
 
@@ -128,10 +105,6 @@
 	timeout = atoi(argv[i]+2);
 	break;
 	
-      case 'T':
-	rtimeout = atoi(argv[i]+2);
-	break;
-	
       case 'R':
 	if (!argv[i][2])
 	  reject_flag = 1;
@@ -200,7 +173,7 @@
     {
       /* In child, let's fork again so we can forget about this child */
       if (fork())
-	_exit();
+	_exit(0);
     }
     else
     {
@@ -241,13 +214,13 @@
     }
   }
 
-  if ((bits && (inremote >> bits != inlocal >> bits)) ||
+  if ((bits && (htonl(inremote.s_addr) >> bits != htonl(inlocal.s_addr) >> bits)) ||
       (reject_flag && !id))
   {
     if (id)
-      syslog(priority, "Rejecting from %s@%s", id, host_address(inremote));
+      syslog(priority, "Rejecting from %s@%s", id, inet_ntoa(inremote));
     else
-      syslog(priority, "Rejecting from %s", host_address(inremote));
+      syslog(priority, "Rejecting from %s", inet_ntoa(inremote));
     exit(1);
   }
   
