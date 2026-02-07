--- cs/util/neo_err.h.orig	2013-12-31 23:09:45.821123833 +0900
+++ cs/util/neo_err.h	2013-12-31 23:16:18.810123255 +0900
@@ -85,7 +85,7 @@
  */
 #if defined(USE_C99_VARARG_MACROS)
 #define nerr_raise(e,f,...) \
-   nerr_raisef(__PRETTY_FUNCTION__,__FILE__,__LINE__,e,f,__VA_ARGS__)
+   nerr_raisef(__PRETTY_FUNCTION__,__FILE__,__LINE__,e,f,## __VA_ARGS__)
 #elif defined(USE_GNUC_VARARG_MACROS)
 #define nerr_raise(e,f,a...) \
    nerr_raisef(__PRETTY_FUNCTION__,__FILE__,__LINE__,e,f,##a)
@@ -99,7 +99,7 @@
 
 #if defined(USE_C99_VARARG_MACROS)
 #define nerr_raise_errno(e,f,...) \
-   nerr_raise_errnof(__PRETTY_FUNCTION__,__FILE__,__LINE__,e,f,__VA_ARGS__)
+   nerr_raise_errnof(__PRETTY_FUNCTION__,__FILE__,__LINE__,e,f,## __VA_ARGS__)
 #elif defined(USE_GNUC_VARARG_MACROS)
 #define nerr_raise_errno(e,f,a...) \
    nerr_raise_errnof(__PRETTY_FUNCTION__,__FILE__,__LINE__,e,f,##a)
@@ -139,7 +139,7 @@
  */
 #if defined(USE_C99_VARARG_MACROS)
 #define nerr_pass_ctx(e,f,...) \
-   nerr_pass_ctxf(__PRETTY_FUNCTION__,__FILE__,__LINE__,e,f,__VA_ARGS__)
+   nerr_pass_ctxf(__PRETTY_FUNCTION__,__FILE__,__LINE__,e,f,## __VA_ARGS__)
 #elif defined(USE_GNUC_VARARG_MACROS)
 #define nerr_pass_ctx(e,f,a...) \
    nerr_pass_ctxf(__PRETTY_FUNCTION__,__FILE__,__LINE__,e,f,##a)
