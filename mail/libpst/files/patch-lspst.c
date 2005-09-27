--- lspst.c.orig	Sun Sep 25 13:39:52 2005
+++ lspst.c	Sun Sep 25 14:24:31 2005
@@ -37,7 +37,9 @@
 char *rfc2426_escape(char *str);
 char *rfc2445_datetime_format(FILETIME *ft);
 // }}}1
+#ifndef DEBUG_MAIN
 #define DEBUG_MAIN(x) debug_print x;
+#endif // DEBUG_MAIN
 // int main(int argc, char** argv) {{{1
 int main(int argc, char** argv) {
 
@@ -47,7 +49,7 @@
 	pst_desc_ll *d_ptr;
 	char *temp = NULL; //temporary char pointer
 	int skip_child = 0;
-	struct file_ll  *f, *head;
+	struct file_ll  *f = NULL, *head;
 	// }}}2
 
 	if (argc <= 1)
