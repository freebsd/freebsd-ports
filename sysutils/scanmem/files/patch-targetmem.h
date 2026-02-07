--- targetmem.h.orig	2017-10-13 21:53:16 UTC
+++ targetmem.h
@@ -257,7 +257,7 @@ static inline value_t
 data_to_val_aux (const matches_and_old_values_swath *swath,
                  size_t index, size_t swath_length)
 {
-    uint i;
+    unsigned int i;
     value_t val;
     size_t max_bytes = swath_length - index;
 
