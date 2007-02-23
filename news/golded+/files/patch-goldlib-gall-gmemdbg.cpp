--- goldlib/gall/gmemdbg.cpp.orig	Fri Feb 23 05:34:31 2007
+++ goldlib/gall/gmemdbg.cpp	Fri Feb 23 05:35:12 2007
@@ -193,7 +193,7 @@
   long last_diff = LONG_MAX;
   Throw** i = throw_index;
   for(int n=0; n<throw_index_size; n++,i++) {
-    long diff = (uint32_t)*i - (uint32_t)pointer;
+    long diff = (long)*i - (long)pointer;
     if((diff > 0) and (diff < last_diff)) {
       last_candidate = *i;
       last_diff = diff;
@@ -211,7 +211,7 @@
   long last_diff = LONG_MAX;
   Throw** i = throw_index;
   for(int n=0; n<throw_index_size; n++,i++) {
-    long diff = (uint32_t)pointer - (uint32_t)*i;
+    long diff = (long)pointer - (long)*i;
     if((diff > 0) and (diff < last_diff)) {
       last_candidate = *i;
       last_diff = diff;
