--- nanohttp.c.orig	Wed Nov 10 15:15:05 2004
+++ nanohttp.c	Wed Nov 10 15:16:44 2004
@@ -161,6 +161,7 @@
     const char *cur = URL;
     char buf[4096];
     int index = 0;
+    const int indexMax = 4096 - 1;
     int port = 0;
 
     if (ctxt->protocol != NULL) { 
@@ -177,7 +178,7 @@
     }
     if (URL == NULL) return;
     buf[index] = 0;
-    while (*cur != 0) {
+    while ((*cur != 0) && (index < indexMax)) {
         if ((cur[0] == ':') && (cur[1] == '/') && (cur[2] == '/')) {
 	    buf[index] = 0;
 	    ctxt->protocol = xmlMemStrdup(buf);
@@ -219,7 +220,7 @@
     else {
         index = 0;
         buf[index] = 0;
-	while (*cur != 0)
+	while ((*cur != 0) && (index < indexMax))
 	    buf[index++] = *cur++;
 	buf[index] = 0;
 	ctxt->path = xmlMemStrdup(buf);
@@ -241,6 +242,7 @@
     const char *cur = URL;
     char buf[4096];
     int index = 0;
+    const int indexMax = 4096 - 1;
     int port = 0;
 
     if (proxy != NULL) { 
@@ -258,7 +260,7 @@
 #endif
     if (URL == NULL) return;
     buf[index] = 0;
-    while (*cur != 0) {
+    while ((*cur != 0) && (index < indexMax)) {
         if ((cur[0] == ':') && (cur[1] == '/') && (cur[2] == '/')) {
 	    buf[index] = 0;
 	    index = 0;
