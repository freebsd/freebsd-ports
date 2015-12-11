--- libev-4.19/ev.c.orig	2015-12-10 10:12:15.511854000 +0800
+++ libev-4.19/ev.c	2015-12-10 10:13:19.665492000 +0800
@@ -1022,12 +1022,12 @@ ecb_inline uint64_t ecb_rotr64 (uint64_t
   }
 #endif
 
-#if ECB_GCC_VERSION(4,5)
+#if ECB_GCC_VERSION(4,5) || defined __clang__
   #define ecb_unreachable() __builtin_unreachable ()
 #else
   /* this seems to work fine, but gcc always emits a warning for it :/ */
-  ecb_inline void ecb_unreachable (void) ecb_noreturn;
-  ecb_inline void ecb_unreachable (void) { }
+  ecb_inline ecb_noreturn ecb_unreachable (void);
+  ecb_inline ecb_noreturn ecb_unreachable (void) { }
 #endif
 
 /* try to tell the compiler that some condition is definitely true */
