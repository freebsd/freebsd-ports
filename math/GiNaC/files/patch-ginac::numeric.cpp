--- ginac/numeric.cpp.orig	Mon Nov 26 20:59:49 2001
+++ ginac/numeric.cpp	Mon Nov 26 21:00:12 2001
@@ -249,7 +249,7 @@
 	// Read number as string
 	std::string str;
 	if (n.find_string("number", str)) {
-		std::istringstream s(str);
+		std::istringstream s(str.c_str());
 		cln::cl_idecoded_float re, im;
 		char c;
 		s.get(c);
