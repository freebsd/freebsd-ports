--- src/controller.cpp.orig	2007-07-29 14:51:45.000000000 +0200
+++ src/controller.cpp	2007-07-29 14:51:29.000000000 +0200
@@ -419,13 +419,13 @@
 
 	ret = nxml_new (&data);
 	if (ret != NXML_OK) {
-		puts (nxml_strerror (ret));
+		puts (nxml_strerror (data, ret));
 		return;
 	}
 
 	ret = nxml_parse_file (data, const_cast<char *>(filename));
 	if (ret != NXML_OK) {
-		puts (nxml_strerror (ret));
+		puts (nxml_strerror (data, ret));
 		return;
 	}
 
