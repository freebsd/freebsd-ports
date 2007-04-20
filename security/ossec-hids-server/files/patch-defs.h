diff -ruN src/headers/defs.h.orig src/headers/defs.h
--- src/headers/defs.h.orig	Thu Feb 22 01:44:26 2007
+++ src/headers/defs.h	Mon Apr  2 10:54:45 2007
@@ -86,7 +86,7 @@
 #endif    
                     
 #ifndef DEFAULTDIR		
-	#define DEFAULTDIR	"/var/ossec"
+	#define DEFAULTDIR	"PREFIX"
 #endif
 
 
