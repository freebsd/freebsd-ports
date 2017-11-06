--- iridium/trknotify.cpp.orig	2017-04-24 14:40:27 UTC
+++ iridium/trknotify.cpp
@@ -5,7 +5,7 @@
  * found in the LICENSE file.
  */
 #include <cstdio>
-#ifdef __linux__
+#ifdef __FreeBSD__
 #	include <unistd.h>
 #endif
 #include "chrome/browser/infobars/infobar_service.h"
@@ -21,7 +21,7 @@ namespace iridium {
 
 void log_url_request(const std::string &caller, const GURL &url)
 {
-#ifdef __linux__
+#ifdef __FreeBSD__
 	bool tty = isatty(fileno(stderr));
 #else
 	bool tty = false;
