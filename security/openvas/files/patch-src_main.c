--- src/main.c	2023-08-31 14:23:03.000000000 -0500
+++ src/main.c	2023-09-20 23:54:36.721716000 -0500
@@ -21,7 +21,13 @@
  * @return EXIT_SUCCESS on success, EXIT_FAILURE on failure.
  */
 int
+#if defined(__FreeBSD__)
+main (int argc, char **argv)
+{
+  return openvas (argc, argv);
+#else
 main (int argc, char **argv, char *env[])
 {
   return openvas (argc, argv, env);
+#endif
 }
