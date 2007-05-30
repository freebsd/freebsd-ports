--- getrealfn.c (revision 384)
+++ getrealfn.c (working copy)
@@ -27,7 +27,7 @@

 static char *my_get_current_dir_name()
 {
-#ifdef __CYGWIN__
+#if defined __CYGWIN__ || defined __FreeBSD__ || defined __OpenBSD__ || defined __NetBSD__
 	char *r = malloc(1024);
 	if (!getcwd(r, 1024))
 		strcpy(r, "/__PATH_TO_LONG__");
