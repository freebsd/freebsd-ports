--- src/ucm/util/replace.c.orig	2026-09-09 00:53:37 UTC
+++ src/ucm/util/replace.c
@@ -176,9 +176,13 @@ void *ucm_get_current_brk()
 
 void *ucm_get_current_brk()
 {
+#if HAVE_BRK
 #if HAVE___CURBRK
     return __curbrk;
 #else
     return ucm_brk_syscall(0);
+#endif
+#else
+    return NULL;
 #endif
 }
