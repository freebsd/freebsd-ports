--- mimetype.cpp.orig	2004-12-11 19:45:05 UTC
+++ mimetype.cpp
@@ -170,7 +170,8 @@ void Quit_MIMEtypes(void)
 /* Given a filename, return an appropriate MIME type */
 char * MIME_Type(const char *filename)
 {
-	char *extension, **type;
+	const char *extension;
+	char **type;
 
 	/* Grab the extension */
 	if ( (extension=strrchr(filename, '.')) == NULL )
