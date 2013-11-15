--- default_plugin/defaultplugin.cpp.orig	2013-11-15 21:38:08.000000000 +0800
+++ default_plugin/defaultplugin.cpp	2013-11-15 21:38:26.000000000 +0800
@@ -16,6 +16,7 @@
  ***************************************************************************/
 
 #include <config.h>
+#include <unistd.h>
 #include <lineak/lconfig.h>
 #include <lineak/lkbd.h>
 #include <lineak/lkey.h>
