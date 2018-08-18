--- third_party/blink/renderer/platform/wtf/compiler.h.orig	2018-08-13 22:36:40.462317000 +0200
+++ third_party/blink/renderer/platform/wtf/compiler.h	2018-08-13 22:38:32.823279000 +0200
@@ -74,8 +74,10 @@
 #if defined(__clang__)
 #define NO_SANITIZE_UNRELATED_CAST \
   __attribute__((no_sanitize("cfi-unrelated-cast", "vptr")))
+#define NO_SANITIZE_CFI_ICALL __attribute__((no_sanitize("cfi-icall")))
 #else
 #define NO_SANITIZE_UNRELATED_CAST
+#define NO_SANITIZE_CFI_ICALL
 #endif
 
 #endif /* WTF_Compiler_h */
