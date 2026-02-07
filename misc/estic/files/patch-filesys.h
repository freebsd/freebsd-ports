--- spunk/filesys.h.orig	1996-11-07 17:06:48 UTC
+++ spunk/filesys.h
@@ -44,10 +44,10 @@
 
 extern const char FileSysPathSep;	// Path separator
 extern const char FileSysListSep;	// Path list separator
-extern const FileSysMaxPath;		// Maximum path length
-extern const FileSysMaxDir;		// Maximum directory length
-extern const FileSysMaxName;		// Maximum file name length
-extern const FileSysMaxExt;		// Maximum extension length (including the dot)
+extern const int FileSysMaxPath;	// Maximum path length
+extern const int FileSysMaxDir;		// Maximum directory length
+extern const int FileSysMaxName;	// Maximum file name length
+extern const int FileSysMaxExt;		// Maximum extension length (including the dot)
 
 
 
