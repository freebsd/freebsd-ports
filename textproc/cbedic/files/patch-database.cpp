--- src/database.cpp.orig	Sat Aug  9 19:23:43 2003
+++ src/database.cpp	Sat Aug  9 19:24:03 2003
@@ -106,7 +106,7 @@
 // Open data file and set some variables
 // Return true if success, false if failed
 //========================================================================
-bool Database::createDictionary(const char *fileName, const long fixedLastWordPointer = 0) {
+bool Database::createDictionary(const char *fileName, const long fixedLastWordPointer) {
 	// Ensure against invoking twice
 	if (dataFile != NULL) {
 		return false;
