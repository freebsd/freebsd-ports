--- src/database.cpp.old	Fri Dec 12 03:18:26 2003
+++ src/database.cpp	Fri Dec 12 03:18:39 2003
@@ -106,7 +106,7 @@
 // Open data file and set some variables
 // Return true if success, false if failed
 //========================================================================
-bool Database::createDictionary(const char *fileName, const long fixedLastWordPointer = 0) {
+bool Database::createDictionary(const char *fileName, const long fixedLastWordPointer) {
 	// Ensure against invoking twice
 	if (dataFile != NULL) {
 		return false;
