--- mozilla/TOCProtocolHandler.cpp.orig	Sat Jun 14 11:42:57 2003
+++ mozilla/TOCProtocolHandler.cpp	Mon Jul 21 11:30:04 2003
@@ -83,8 +83,8 @@
 	oStream->Write (str.c_str(), str.size(), &bytesWriten);
 
 static void ParseEnvPath(const nsCString &path, list<string> &dirs);
-static int gHelpSelect (const struct dirent *dirEntry);
-static int gnomeHelpSelect (const struct dirent *dirEntry);
+static int gHelpSelect (struct dirent *dirEntry);
+static int gnomeHelpSelect (struct dirent *dirEntry);
 static void RenderContentType (nsIOutputStream *oStream, PRUint32 &bytesWriten);
 
 /* Implementation file */
@@ -362,7 +362,7 @@
 }
 
 NS_METHOD GTOCProtocolHandler::CreateHelpPage (const char *type,
-					       int (*select)(const struct dirent *))
+					       int (*select)(struct dirent *))
 {
 	nsresult rv;
 
@@ -445,7 +445,7 @@
 	}
 }
 
-int gHelpSelect (const struct dirent *dirEntry)
+int gHelpSelect (struct dirent *dirEntry)
 {
 #ifdef NOT_PORTED
 	char *helpPath = gnome_help_file_find_file (
@@ -461,7 +461,7 @@
 #endif
 }
 
-int gnomeHelpSelect (const struct dirent *dirEntry)
+int gnomeHelpSelect (struct dirent *dirEntry)
 {
 #ifdef NOT_PORTED
 	nsCString fileName = dirEntry->d_name;
