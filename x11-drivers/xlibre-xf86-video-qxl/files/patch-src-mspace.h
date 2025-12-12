--- src/mspace.h.orig	2023-01-07 19:53:51 UTC
+++ src/mspace.h
@@ -9,7 +9,7 @@ extern "C" {
 
 //typedef unsigned long size_t;
 typedef void (*mspace_abort_t)(void *user_data);
-typedef void (*mspace_print_t)(void *user_data, const char *format, ...)  __attribute__((format(gnu_printf, 2, 3)));
+typedef void (*mspace_print_t)(void *user_data, const char *format, ...)  __attribute__((__format__(__printf__, 2, 3)));
 
 void mspace_set_abort_func(mspace_abort_t f);
 void mspace_set_print_func(mspace_print_t f);
