--- cpp2latex/main.cpp.orig	Mon Jun 11 14:14:19 2001
+++ cpp2latex/main.cpp	Tue Nov 26 19:32:41 2002
@@ -25,6 +25,14 @@
 #include <fstream>
 #include <vector>
 
+using std::cerr;
+using std::cout;
+using std::endl;
+using std::getline;
+using std::ifstream;
+using std::string;
+using std::vector;
+
 struct replace{
 	string voraus;
 	string ersetzt;
@@ -87,8 +95,8 @@
 	cerr<<"  Skipping "<<skip<<" lines."<<endl;
 	for(int i=0; i<skip; i++)
 	{
-	char* tmp;
-		file.gets( &tmp );
+	string line;
+		getline( file, line );
 	}
 
 	// Tabspace setzen
