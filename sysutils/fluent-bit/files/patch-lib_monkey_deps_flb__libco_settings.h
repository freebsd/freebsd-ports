--- lib/monkey/deps/flb_libco/settings.h.orig	2020-11-16 20:40:21 UTC
+++ lib/monkey/deps/flb_libco/settings.h
@@ -42,6 +42,8 @@
   #define text_section __declspec(allocate(".text"))
 #elif defined(__APPLE__) && defined(__MACH__)
   #define text_section __attribute__((section("__TEXT,__text")))
+#elif defined(__clang__)
+  #define text_section __attribute__((section(".text")))
 #else
   #define text_section __attribute__((section(".text#")))
 #endif
