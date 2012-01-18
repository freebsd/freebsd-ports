--- ./xbmc/system.h.orig	2011-12-23 04:12:21.000000000 +0100
+++ ./xbmc/system.h	2012-01-02 10:14:38.000000000 +0100
@@ -23,7 +23,7 @@
 
 #if defined(HAVE_CONFIG_H) && !defined(TARGET_WINDOWS)
 #include "config.h"
-#define DECLARE_UNUSED(a,b) a __attribute__(unused) b;
+#define DECLARE_UNUSED(a,b) a __attribute__((unused)) b;
 #endif
 
 /*****************
