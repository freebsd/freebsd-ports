--- src/main.c	2022-07-18 04:07:38.000000000 -0500
+++ src/main.c	2022-07-31 21:37:38.265241000 -0500
@@ -35,7 +35,13 @@
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
