--- nanoftp.c.orig	Wed Nov 10 15:17:07 2004
+++ nanoftp.c	Wed Nov 10 15:19:56 2004
@@ -65,6 +65,8 @@
 #define FTP_GET_PASSWD		331
 #define FTP_BUF_SIZE		512
 
+#define XML_NANO_MAX_URLBUF	4096
+
 typedef struct xmlNanoFTPCtxt {
     char *protocol;	/* the protocol name */
     char *hostname;	/* the host name */
@@ -203,7 +205,7 @@
 xmlNanoFTPScanURL(void *ctx, const char *URL) {
     xmlNanoFTPCtxtPtr ctxt = (xmlNanoFTPCtxtPtr) ctx;
     const char *cur = URL;
-    char buf[4096];
+    char buf[XML_NANO_MAX_URLBUF];
     int index = 0;
     int port = 0;
 
@@ -221,7 +223,7 @@
     }
     if (URL == NULL) return;
     buf[index] = 0;
-    while (*cur != 0) {
+    while ((*cur != 0) && (index < XML_NANO_MAX_URLBUF - 1)) {
         if ((cur[0] == ':') && (cur[1] == '/') && (cur[2] == '/')) {
 	    buf[index] = 0;
 	    ctxt->protocol = xmlMemStrdup(buf);
@@ -234,7 +236,7 @@
     if (*cur == 0) return;
 
     buf[index] = 0;
-    while (1) {
+    while (index < XML_NANO_MAX_URLBUF - 1) {
         if (cur[0] == ':') {
 	    buf[index] = 0;
 	    ctxt->hostname = xmlMemStrdup(buf);
@@ -263,7 +265,7 @@
     else {
         index = 0;
         buf[index] = 0;
-	while (*cur != 0)
+	while ((*cur != 0) && (index < XML_NANO_MAX_URLBUF-1))
 	    buf[index++] = *cur++;
 	buf[index] = 0;
 	ctxt->path = xmlMemStrdup(buf);
@@ -288,7 +290,7 @@
 xmlNanoFTPUpdateURL(void *ctx, const char *URL) {
     xmlNanoFTPCtxtPtr ctxt = (xmlNanoFTPCtxtPtr) ctx;
     const char *cur = URL;
-    char buf[4096];
+    char buf[XML_NANO_MAX_URLBUF];
     int index = 0;
     int port = 0;
 
@@ -301,7 +303,7 @@
     if (ctxt->hostname == NULL)
 	return(-1);
     buf[index] = 0;
-    while (*cur != 0) {
+    while ((*cur != 0) && (index < XML_NANO_MAX_URLBUF-1)) {
         if ((cur[0] == ':') && (cur[1] == '/') && (cur[2] == '/')) {
 	    buf[index] = 0;
 	    if (strcmp(ctxt->protocol, buf))
@@ -353,7 +355,7 @@
     else {
         index = 0;
         buf[index] = 0;
-	while (*cur != 0)
+	while ((*cur != 0) && (index < XML_NANO_MAX_URLBUF-1))
 	    buf[index++] = *cur++;
 	buf[index] = 0;
 	ctxt->path = xmlMemStrdup(buf);
@@ -374,7 +376,7 @@
 void
 xmlNanoFTPScanProxy(const char *URL) {
     const char *cur = URL;
-    char buf[4096];
+    char buf[XML_NANO_MAX_URLBUF];
     int index = 0;
     int port = 0;
 
@@ -393,7 +395,7 @@
 #endif
     if (URL == NULL) return;
     buf[index] = 0;
-    while (*cur != 0) {
+    while ((*cur != 0) && (index < XML_NANO_MAX_URLBUF-1)) {
         if ((cur[0] == ':') && (cur[1] == '/') && (cur[2] == '/')) {
 	    buf[index] = 0;
 	    index = 0;
@@ -827,6 +829,11 @@
 	hp = gethostbyname(ctxt->hostname);
     if (hp == NULL)
         return(-1);
+
+    if ((unsigned int) hp->h_length >
+	sizeof(((struct sockaddr_in *)&ctxt->ftpAddr)->sin_addr)) {
+	return (-1);
+    }
 
     /*
      * Prepare the socket
