man 3 basename

--- Source/WebKit2/PluginProcess/unix/PluginProcessMainUnix.cpp.orig	2013-06-11 20:02:23.000000000 +0000
+++ Source/WebKit2/PluginProcess/unix/PluginProcessMainUnix.cpp	2013-06-11 20:04:31.000000000 +0000
@@ -48,6 +48,8 @@
 
 #ifdef XP_UNIX
 
+#include <libgen.h>
+
 #if !LOG_DISABLED
 static const char xErrorString[] = "The program '%s' received an X Window System error.\n"
     "This probably reflects a bug in a browser plugin.\n"
