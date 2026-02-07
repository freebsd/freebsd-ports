--- spunk/unixsrc/filesys.cc.orig	1996-11-07 17:06:58 UTC
+++ spunk/unixsrc/filesys.cc
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
 
 
 
