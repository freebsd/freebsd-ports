--- lib/message/cslib/src/cslib_wrap.h.orig	2020-05-02 07:55:51 UTC
+++ lib/message/cslib/src/cslib_wrap.h
@@ -16,6 +16,8 @@
    ifdefs allow this file to be included in a C program
 */
 
+#include <cstdint>
+
 #ifdef __cplusplus
 extern "C" {
 #endif
