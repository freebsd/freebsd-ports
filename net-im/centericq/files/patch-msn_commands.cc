--- libmsn-0.1/msn_commands.cc.orig	Wed Oct 16 18:20:59 2002
+++ libmsn-0.1/msn_commands.cc	Wed Oct 30 16:44:55 2002
@@ -30,7 +30,10 @@
 #include <sys/socket.h>
 #include <errno.h>
 #include <netdb.h>
-
+#define HAVE_ICONV_H 1
+#if HAVE_ICONV_H
+#include <iconv.h>
+#endif
 #include "libmsn.h"
 #include "msn_commands.h"
 #include "parse_utils.h"
@@ -426,6 +429,128 @@
     return 0;
 }
 
+#if HAVE_ICONV_H
+/* 
+** Name:    safe_iconv
+** Purpose: 'Fault-tolerant' version if iconv. Replaces invalid seq with '?'
+** Input:   see iconv manpage
+*/
+static int safe_iconv( iconv_t handle,
+	     const char **inbuf, size_t *inbytesleft,
+	     char **outbuf, size_t *outbytesleft)
+{
+    int ret;
+    while (*inbytesleft) {
+	 ret = iconv( handle, inbuf, inbytesleft,
+		outbuf, outbytesleft);
+	if (!*inbytesleft || !*outbytesleft)
+	    return ret;
+	/*got invalid seq - so replace it with '?' */
+	**outbuf = '?'; (*outbuf)++; (*outbytesleft)--;
+	(*inbuf)++; (*inbytesleft)--;
+    }
+    return ret;
+}
+
+/* charset name cache buffer */
+char loc_charset[32];
+
+#define DEFAULT_CHARSET "ISO-8859-1"
+
+/*
+** Name:    guess_current_locale_charset
+** Purpose: Try to guess default charset for the current locale
+** Output:  charset name
+** FIXME:   is there more right method for guessing charset
+	    than scanning $LANG ?
+*/
+static char* guess_current_locale_charset()
+{
+    char *lang, *ch;
+    /* Return previously learned charset */
+    return "big5";
+    if (loc_charset[0])
+	return loc_charset;
+
+    lang = getenv("LANG");
+    ch = strrchr( lang, '.' ) + 1;
+    if (!ch)
+	strcpy( loc_charset, DEFAULT_CHARSET );
+    else {
+	iconv_t pt;
+	strncpy( loc_charset, ch, sizeof(loc_charset) );
+	/* try to open iconv handle using guessed charset */
+	if ( (pt = iconv_open( loc_charset, loc_charset )) == (iconv_t)(-1) )
+	{
+	    strcpy( loc_charset, DEFAULT_CHARSET );
+	} else {
+	    iconv_close(pt);
+	};
+	
+    }
+
+    return loc_charset;
+}
+#endif /* HAVE_ICONV_H */
+
+/*
+** Name:    Str2Utf8
+** Purpose: convert a string in UTF-8 format
+** Input:   inbuf     - the string to convert
+** Output:  a new string in UTF-8 format
+*/
+static char *StrToUtf8( const char *inbuf )
+{
+#if HAVE_ICONV_H
+    size_t length = strlen( inbuf );
+    size_t outmaxlength = length * 4; /* FIXME: Is x4 multiplier enoght? */
+    char *outbuf = (char*) malloc( outmaxlength + 1 );
+    char *outbuf_save = outbuf;
+    int ret;
+
+    iconv_t handle = iconv_open( "utf-8", guess_current_locale_charset() );
+    ret = safe_iconv( handle, (const char **) &inbuf, &length, &outbuf, &outmaxlength );
+    
+    iconv_close( handle );
+
+    return outbuf_save;
+#else
+    char *outbuf = strdup( inbuf );
+    char *outbuf_save = outbuf;
+    /* Clear eight bit */
+    for (; *outbuf; ++outbuf)
+        *outbuf &= 0x7F;
+    return outbuf_save;
+#endif
+}
+ 
+/*
+** Name:    Utf8ToStr
+** Purpose: revert UTF-8 string conversion
+** Input:   inbuf  - the string to decode
+** Output:  a new decoded string
+*/
+static char *Utf8ToStr( char *inbuf )
+{
+#if HAVE_ICONV_H
+    size_t length = strlen( inbuf );
+    size_t outmaxlength = length;
+    char *outbuf = (char*) malloc( outmaxlength + 1 );
+    char *outbuf_save = outbuf;
+    int ret;
+
+    iconv_t handle = iconv_open( guess_current_locale_charset(), "utf-8" );
+
+    ret = safe_iconv( handle, (const char **) &inbuf, &length, &outbuf, &outmaxlength );
+    
+    iconv_close( handle );
+
+    return outbuf_save;
+#else
+    return strdup( inbuf );
+#endif
+}
+
 /*
 ** Name:    HandleMessage
 ** Purpose: This function handles an instant message from either the server
@@ -440,6 +565,7 @@
 {
     MSN_InstantMessage newIm;
     char *message;
+    char *decodedIm;
     char *mimeInfo, *im;
     int  length, nread; 
     struct timeval t;
@@ -448,6 +574,8 @@
     message = NULL;
     mimeInfo = NULL;
     im = NULL; 
+    decodedIm = NULL;
+
 	
     if (numOfArgs != 4)
 	return -1;
@@ -470,13 +598,15 @@
  
     if (mimeInfo != NULL) {
 	if (strstr(mimeInfo, "text/plain") != NULL) {
+
+	    decodedIm = Utf8ToStr( im );
 	    newIm.year = 0;
 	    newIm.month = 0;
 	    newIm.day = 0;
 	    newIm.hour = 0;
 	    newIm.minute = 0;
 	    newIm.sec = 0;
-	    newIm.msg = im;
+	    newIm.msg = decodedIm;
 	    RemoveHotmail(args[1], &newIm.sender);
 	    newIm.friendlyhandle = args[2];
 	    newIm.fd = conn->fd;
@@ -571,15 +701,18 @@
 int SendMessage(MSN_Conn *conn, const char *message)
 {
     char   *commandLine;
+    char   *UTFmessage;
     int    length;
 
     if (!message)
 	return -1;
+    UTFmessage = NULL;
 
-    commandLine = (char *)malloc(strlen(MIME_HEADER)+strlen(message)+25);
+    UTFmessage = StrToUtf8( message );
+    commandLine = (char *)malloc(strlen(MIME_HEADER)+strlen(UTFmessage)+25);
     length = sprintf(commandLine, "%s %lu N %d\r\n%s%s", CommandString[MSG],
-		     TrID++, strlen(message)+strlen(MIME_HEADER), MIME_HEADER, 
-		     message);
+		     TrID++, strlen(UTFmessage)+strlen(MIME_HEADER), MIME_HEADER, 
+		     UTFmessage);
 
     write(conn->fd, commandLine, length);
     free(commandLine);
