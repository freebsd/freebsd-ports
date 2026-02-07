--- image/window.c.orig	2004-07-28 15:47:31 UTC
+++ image/window.c
@@ -32,7 +32,7 @@
 #if HAVE_SYS_SELECT_H
 # include <sys/select.h>
 #endif
-#ifdef __APPLE__
+#if 1
 #include <unistd.h>
 #endif
 
