--- vendor/ocaml_intrinsics-0.16.1/src/int_stubs.c.orig	2024-11-19 16:18:24 UTC
+++ vendor/ocaml_intrinsics-0.16.1/src/int_stubs.c
@@ -115,7 +115,7 @@ intnat naive_int32_popcnt (uint32_t x)
 #define int64_ctz naive_int64_ctz
 #define int32_popcnt naive_int32_popcnt
 #define int64_popcnt naive_int64_popcnt
-#elseif /* _MSC_VER */
+#elif /* _MSC_VER */
 #error "Target not supported"
 #endif /* _MSC_VER */
 #endif /* defined(__GNUC__) */
