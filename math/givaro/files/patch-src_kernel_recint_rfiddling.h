--- src/kernel/recint/rfiddling.h.orig	2021-12-14 10:00:03 UTC
+++ src/kernel/recint/rfiddling.h
@@ -167,7 +167,7 @@ namespace RecInt
     template <size_t K>
     inline rint<K> rint<K>::maxFFLAS() {
         rint<K> max;
-        set_highest_bit(max.Low.Value);
+        set_highest_bit(max.Value.Low);
         return max;
     }
 
