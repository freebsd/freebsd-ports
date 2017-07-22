--- code/MMDPmdParser.h.orig	2017-07-18 17:03:26 UTC
+++ code/MMDPmdParser.h
@@ -158,7 +158,7 @@ namespace pmd
 				sphere_filename.clear();
 			}
 			else {
-				*pstar = (char)NULL;
+				*pstar = 0;
 				texture_filename = std::string(buffer);
 				sphere_filename = std::string(pstar+1);
 			}
