--- sigscheme/src/alloc.c.orig	2007-01-07 01:46:46.000000000 +0900
+++ sigscheme/src/alloc.c	2007-11-04 18:01:05.000000000 +0900
@@ -181,7 +181,6 @@
     return copied;
 }
 
-#if 0
 /* For 'name' slot of symbol object on storage-compact. If your malloc(3) does
  * not ensure 8-bytes alignment, Complete this function and hook this into
  * symbol object creation and modification.  -- YamaKen 2006-05-30 */
@@ -192,17 +191,16 @@
     size_t size;
 
     /* Use ScmCell-alignment to ensure at least 8-bytes aligned. */
-    if ((uintptr_t)ptr % sizeof(ScmCell)) {
+    if ((uintptr_t)str % sizeof(ScmCell)) {
         size = strlen(str) + sizeof("");
-        copied = scm_malloc_aligned8(size);
+        copied = scm_malloc_aligned(size);
         strcpy(copied, str);
         free(str);
         return copied;
     } else {
-        return ptr;
+        return str;
     }
 }
-#endif
 
 /*=======================================
    Extendable Local Buffer
