Index: perl/imap/IMAP.xs
diff -u perl/imap/IMAP.xs.orig perl/imap/IMAP.xs
--- perl/imap/IMAP.xs.orig	Sun May 26 04:57:49 2002
+++ perl/imap/IMAP.xs	Sat Aug 17 03:47:36 2002
@@ -194,6 +194,7 @@
   if(!text->password) {
 	char *ptr;
 	printf("Password: ");
+	fflush(stdout);
 	ptr = getpass("");
 	text->password = safemalloc(sizeof(sasl_secret_t) + strlen(ptr));
 	text->password->len = strlen(ptr);
