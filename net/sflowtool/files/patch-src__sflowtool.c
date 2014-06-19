--- ./src/sflowtool.c.orig	2014-05-27 21:09:17.000000000 +0200
+++ ./src/sflowtool.c	2014-05-31 09:15:00.000000000 +0200
@@ -442,7 +442,7 @@
 void *my_calloc(size_t bytes) {
   void *mem = calloc(1, bytes);
   if(mem == NULL) {
-    fprintf(ERROUT, "calloc(%u) failed: %s\n", bytes, strerror(errno));
+    fprintf(ERROUT, "calloc(%zu) failed: %s\n", bytes, strerror(errno));
     exit(-1);
   }
   return mem;
@@ -554,7 +554,7 @@
   register char c, *r = in, *w = out;
   int maxlen = (strlen(in) * 3) + 1;
   if(outlen < maxlen) return "URLEncode: not enough space";
-  while (c = *r++) {
+  while ((c = *r++)) {
     if(isalnum(c)) *w++ = c;
     else if(isspace(c)) *w++ = '+';
     else {
@@ -3075,7 +3075,7 @@
   uint8_t *uuid;
   char hostname[SFL_MAX_HOSTNAME_LEN+1];
   char os_release[SFL_MAX_OSRELEASE_LEN+1];
-  char uuidStr[100];
+  u_char uuidStr[100];
   if(getString(sample, hostname, SFL_MAX_HOSTNAME_LEN) > 0) {
     sf_log(sample,"hostname %s\n", hostname);
   }
@@ -3921,7 +3921,8 @@
 static void readPacket(int soc)
 {
   struct sockaddr_in6 peer;
-  int alen, cc;
+  int cc;
+  u_int alen;
 #define MAX_PKT_SIZ 65536
   char buf[MAX_PKT_SIZ];
   alen = sizeof(peer);
