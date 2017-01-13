--- utils/variant-impl.hpp.orig	2017-01-02 19:30:30 UTC
+++ utils/variant-impl.hpp
@@ -306,12 +306,12 @@ struct get_index<From, Checker, T, Rest.
 
     static const bool is_exact_match = is_same_upto_cv<T, From>();
     static const bool is_relaxed_match = relaxed_same<T, From>();
-    static const bool is_variant = is_variant<T>::value;
+    static const bool is_variant_match = is_variant<T>::value;
     static const bool is_ud_match = Checker<T, From>::value;
-    static const bool is_strict_ud_match = is_ud_match && !is_variant;
+    static const bool is_strict_ud_match = is_ud_match && !is_variant_match;
 
     typedef typename get_index_of_variant<From, T>::type variant_indices;
-    static const int var_quality = is_variant ? variant_indices::quality - 2 : 0;
+    static const int var_quality = is_variant_match ? variant_indices::quality - 2 : 0;
 
     // Match quality:
     //   exact > su > rel > strict_ud > ud
@@ -335,7 +335,7 @@ struct get_index<From, Checker, T, Rest.
             sizeof...(Rest)+1, typeid(From).name(), typeid(T).name(),
             local_quality, var_quality, Tail::quality, quality, index, ambiguous);
 
-        if (is_variant)
+        if (is_variant_match)
         {
             printf("<< var <<\n");
             variant_indices::debug();
