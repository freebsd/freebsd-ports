--- drivers/libdha/libdha.h.orig	Sat Apr  5 19:39:46 2003
+++ drivers/libdha/libdha.h	Sat Apr  5 19:44:20 2003
@@ -16,7 +16,11 @@
 #ifndef LIBDHA_H
 #define LIBDHA_H
 
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#else
+#include <inttypes.h>	/* for int64_t */
+#endif
 
 #ifdef __cplusplus
 extern "C" {
