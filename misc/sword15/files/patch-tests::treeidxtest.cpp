diff -ruN sword-1.5.3.orig/tests/treeidxtest.cpp sword-1.5.3/tests/treeidxtest.cpp
--- tests/treeidxtest.cpp	Thu Jan 24 09:55:27 2002
+++ tests/treeidxtest.cpp	Wed Jun 19 14:03:37 2002
@@ -85,7 +85,7 @@
 	}
 	TreeKeyIdx root = *treeKey;
 
-	string input;
+	std::string input;
 	char line[1024];
 
 	do {
