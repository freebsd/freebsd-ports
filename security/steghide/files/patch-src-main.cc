--- src/main.cc.orig	Thu Sep 26 21:33:15 2002
+++ src/main.cc	Thu Sep 26 21:36:48 2002
@@ -84,8 +84,8 @@
 static void version (void) ;
 static void usage (void) ;
 static void license (void) ;
-static void embedfile (string cvrfilename, string stgfilename, string plnfilename) ;
-static void extractfile (string stgfilename, string plnfilename) ;
+static void embedfile (std::string cvrfilename, std::string stgfilename, std::string plnfilename) ;
+static void extractfile (std::string stgfilename, std::string plnfilename) ;
 static void cleanup (void) ;
 
 int main (int argc, char *argv[])
@@ -334,7 +334,7 @@
 }
 
 /* calls functions to embed plain data in cover data and save as stego data */
-static void embedfile (string cvrfilename, string stgfilename, string plnfilename)
+static void embedfile (std::string cvrfilename, std::string stgfilename, std::string plnfilename)
 {
 	CvrStgFile *cvrstgfile = NULL ;
 	PLNFILE *plnfile = NULL ;
@@ -372,7 +372,7 @@
 }
 
 /* calls functions to extract (and save) plain data from stego data */
-static void extractfile (string stgfilename, string plnfilename)
+static void extractfile (std::string stgfilename, std::string plnfilename)
 {
 	PLNFILE *plnfile = NULL ;
 	unsigned long firstplnpos = 0 ;
