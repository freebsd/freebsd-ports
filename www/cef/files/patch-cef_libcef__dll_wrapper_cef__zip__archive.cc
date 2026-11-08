--- cef/libcef_dll/wrapper/cef_zip_archive.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef_dll/wrapper/cef_zip_archive.cc
@@ -12,7 +12,7 @@
 #include "include/cef_zip_reader.h"
 #include "include/wrapper/cef_byte_read_handler.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <wctype.h>
 #endif
 
