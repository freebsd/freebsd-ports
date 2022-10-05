--- base/test/launcher/test_launcher.cc.orig	2022-10-05 07:34:01 UTC
+++ base/test/launcher/test_launcher.cc
@@ -65,6 +65,7 @@
 #include "third_party/libxml/chromium/libxml_utils.h"
 
 #if BUILDFLAG(IS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
