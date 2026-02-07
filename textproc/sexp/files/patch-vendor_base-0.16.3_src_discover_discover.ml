--- vendor/base-0.16.3/src/discover/discover.ml.orig	2024-12-12 18:54:02 UTC
+++ vendor/base-0.16.3/src/discover/discover.ml
@@ -4,6 +4,9 @@ int main(int argc, char ** argv)
   {|
 int main(int argc, char ** argv)
 {
+#if !defined(__x86_64__) && !defined(__i386__)
+#error "-mpopcnt not supported"
+#endif
   return __builtin_popcount(argc);
 }
 |}
