--- spunk/unixsrc/filesys.cc.orig	Sat Feb 26 17:57:13 2000
+++ spunk/unixsrc/filesys.cc	Sat Feb 26 17:57:39 2000
@@ -42,10 +42,10 @@
 
 extern const char FileSysPathSep	= '/';	// Path separator
 extern const char FileSysListSep	= ':';	// Path list separator
-extern const FileSysMaxPath		= 255;	// Maximum path length
-extern const FileSysMaxDir		= 255;	// Maximum directory length
-extern const FileSysMaxName		= 255;	// Maximum file name length
-extern const FileSysMaxExt		= 255;	// Maximum extension length (including the dot)
+extern const int FileSysMaxPath		= 255;	// Maximum path length
+extern const int FileSysMaxDir		= 255;	// Maximum directory length
+extern const int FileSysMaxName		= 255;	// Maximum file name length
+extern const int FileSysMaxExt		= 255;	// Maximum extension length (including the dot)
 
 
 
