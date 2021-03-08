--- lib/monkey/deps/flb_libco/ppc.c.orig	2021-03-08 11:12:53 UTC
+++ lib/monkey/deps/flb_libco/ppc.c
@@ -279,7 +279,9 @@ static uint32_t* co_create_(unsigned size, uintptr_t e
   return t;
 }
 
-cothread_t co_create(unsigned int size, void (*entry_)(void)) {
+cothread_t co_create(unsigned int size, void (*entry_)(void),
+                     size_t *out_size) {
+
   uintptr_t entry = (uintptr_t)entry_;
   uint32_t* t = 0;
 
@@ -325,7 +327,7 @@ cothread_t co_create(unsigned int size, void (*entry_)
     t[10] = (uint32_t)(sp >> shift >> shift);
     t[11] = (uint32_t)sp;
   }
-
+  *out_size = size;
   return t;
 }
 
