--- src/0d1n.c.orig	2023-02-20 12:38:21 UTC
+++ src/0d1n.c
@@ -62,8 +62,7 @@ main (int argc, char ** argv)
 /* remove comment to test the patch
 */
 #ifdef __GNUC__
-#  if __GNUC_PREREQ(10,0)
-
+#  if __GNUC__ >= 10
 	scan_gcc_new();
 #  else
 	scan_gcc_old();
