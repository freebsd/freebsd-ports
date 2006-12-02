--- FileTypeState.cpp.orig	Tue Apr 18 21:22:46 2000
+++ FileTypeState.cpp	Fri Dec  1 22:45:01 2006
@@ -21,6 +21,11 @@
 #include <fstream>
 #include <stdlib.h>	// need getenv()
 
+using std::ofstream;
+using std::ifstream;
+using std::ios;
+using std::flush;
+
 // Implemented as a Singleton to simplify access from both filetype dialog and
 // newsscanner without having to maintain references to each other
 
