--- lily/font-config.cc.orig	2018-03-17 05:17:54 UTC
+++ lily/font-config.cc
@@ -19,7 +19,7 @@
 
 #include "config.hh"
 
-#if HAVE_FONTCONFIG
+#if HAVE_FONTCONFIG && 0 // fontconfig shouldn't be run during build: it causes fs violation
 
 #include <cstdio>
 #include <fontconfig/fontconfig.h>
