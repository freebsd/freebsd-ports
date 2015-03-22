--- libev-4.15/ev.c.orig	2014-05-20 06:54:23.272151000 +0200
+++ libev-4.15/ev.c	2015-03-02 21:52:59.621578000 +0100
@@ -963,12 +963,12 @@
   }
 #endif
 
-#if ECB_GCC_VERSION(4,5)
+#if ECB_GCC_VERSION(4,5) || defined __clang__
   #define ecb_unreachable() __builtin_unreachable ()
 #else
   /* this seems to work fine, but gcc always emits a warning for it :/ */
-  ecb_inline void ecb_unreachable (void) ecb_noreturn;
-  ecb_inline void ecb_unreachable (void) { }
+  ecb_inline ecb_noreturn void ecb_unreachable (void);
+  ecb_inline ecb_noreturn void ecb_unreachable (void) { }
 #endif
 
 /* try to tell the compiler that some condition is definitely true */
