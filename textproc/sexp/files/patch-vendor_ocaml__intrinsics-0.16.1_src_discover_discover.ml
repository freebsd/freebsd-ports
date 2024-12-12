--- vendor/ocaml_intrinsics-0.16.1/src/discover/discover.ml.orig	2024-12-12 18:43:16 UTC
+++ vendor/ocaml_intrinsics-0.16.1/src/discover/discover.ml
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
@@ -73,6 +76,9 @@ int main(int argc, char ** argv)
   {|
 int main(int argc, char ** argv)
 {
+#if !defined(__x86_64__) && !defined(__i386__)
+#error "-mprfchw not supported"
+#endif
   __builtin_prefetch(argv, 1, 3);
   return 0;
 }
@@ -83,6 +89,9 @@ int main(int argc, char ** argv)
   {|
 int main(int argc, char ** argv)
 {
+#if !defined(__x86_64__) && !defined(__i386__)
+#error "-mprefetchwt1 not supported"
+#endif
   __builtin_prefetch(argv, 1, 2);
   return 0;
 }
