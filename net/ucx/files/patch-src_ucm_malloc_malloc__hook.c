--- src/ucm/malloc/malloc_hook.c.orig	2026-02-04 09:52:46 UTC
+++ src/ucm/malloc/malloc_hook.c
@@ -35,6 +35,12 @@
 #include <ucs/sys/sys.h>
 #include <ucs/type/spinlock.h>
 
+#if defined(__FreeBSD__)
+#include <limits.h>
+#include <sys/param.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 
 #include <netdb.h>
 
@@ -45,7 +51,6 @@
 #define UCM_MALLOC_INSTALLED_OPT_SYMS   UCS_BIT(2)  /* Installed optional symbols */
 #define UCM_MALLOC_INSTALLED_MALL_SYMS  UCS_BIT(3)  /* Installed malloc symbols */
 
-
 /* Mangled symbols of C++ allocators */
 #define UCM_OPERATOR_NEW_SYMBOL        "_Znwm"
 #define UCM_OPERATOR_DELETE_SYMBOL     "_ZdlPv"
@@ -659,7 +664,11 @@ static void ucm_malloc_populate_glibc_cache()
 
 static void ucm_malloc_populate_glibc_cache()
 {
+#if defined(__FreeBSD__)
+    static char hostname[UCS_HOST_NAME_MAX] = {0};
+#else
     char hostname[HOST_NAME_MAX];
+#endif
 
     /* Trigger NSS initialization before we install malloc hooks.
      * This is needed because NSS could allocate strings with our malloc(), but
