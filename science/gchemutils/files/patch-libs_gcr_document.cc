--- libs/gcr/document.cc.orig	2013-12-03 21:16:21.000000000 +0100
+++ libs/gcr/document.cc	2013-12-03 21:22:51.000000000 +0100
@@ -1521,7 +1521,6 @@
 		if (error) {
 			cerr << "gio error: " << error->message << endl;
 			g_error_free (error);
-			g_object_unref (file);
 			throw (int) 1;
 		}
 		std::map<std::string, sAtom>AtomsMap;
