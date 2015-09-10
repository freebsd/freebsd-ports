--- include/httpd.h.orig	2014-08-21 17:33:48 UTC
+++ include/httpd.h
@@ -1905,12 +1905,6 @@ AP_DECLARE(char *) ap_get_exec_line(apr_
                                     const char *cmd,
                                     const char * const *argv);
 
-/** strtoul does not exist on sunos4. */
-#ifdef strtoul
-#undef strtoul
-#endif
-#define strtoul strtoul_is_not_a_portable_function_use_strtol_instead
-
   /* The C library has functions that allow const to be silently dropped ...
      these macros detect the drop in maintainer mode, but use the native
      methods for normal builds
