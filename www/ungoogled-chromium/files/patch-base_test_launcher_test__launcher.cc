--- base/test/launcher/test_launcher.cc.orig	2023-02-11 09:11:04 UTC
+++ base/test/launcher/test_launcher.cc
@@ -66,6 +66,7 @@
 #include "third_party/libxml/chromium/libxml_utils.h"
 
 #if BUILDFLAG(IS_POSIX)
+#include <signal.h>
 #include <fcntl.h>
 
 #include "base/files/file_descriptor_watcher_posix.h"
