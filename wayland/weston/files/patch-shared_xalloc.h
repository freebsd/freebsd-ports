--- shared/xalloc.h.orig	2016-05-19 21:36:04 UTC
+++ shared/xalloc.h
@@ -35,6 +35,8 @@ extern "C" {
 
 #include "zalloc.h"
 
+typedef __int32_t int32_t;
+
 void *
 fail_on_null(void *p, size_t size, char *file, int32_t line);
 
