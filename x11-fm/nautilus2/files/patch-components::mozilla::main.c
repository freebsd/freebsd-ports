
$FreeBSD$

--- components/mozilla/main.c	2002/02/26 22:24:25	1.1
+++ components/mozilla/main.c	2002/02/26 22:25:27
@@ -141,7 +141,7 @@
 	char *file_name;
 	gboolean good;
 
-	file_name = g_strconcat (path, "/chrome/embed.jar", NULL);
+	file_name = g_strconcat (path, "/libgtkembedmoz.so", NULL);
 	good = g_file_exists (file_name);
 	g_free (file_name);
 	return good;
@@ -155,6 +155,7 @@
 	 */
 	guint i;
 	const char * const paths[] = {
+		MOZILLA_LIB_PLACE,
 		PREFIX "/lib/mozilla",
 		"/usr/lib/mozilla",
 		"/usr/local/mozilla",
