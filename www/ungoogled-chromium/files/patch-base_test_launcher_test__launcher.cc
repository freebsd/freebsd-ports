--- base/test/launcher/test_launcher.cc.orig	2023-01-13 08:56:02 UTC
+++ base/test/launcher/test_launcher.cc
@@ -67,6 +67,7 @@
 #include "third_party/libxml/chromium/libxml_utils.h"
 
 #if BUILDFLAG(IS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
