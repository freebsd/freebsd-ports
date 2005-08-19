--- src/parsetpl.cpp.orig	Fri Aug 19 17:49:03 2005
+++ src/parsetpl.cpp	Fri Aug 19 17:50:18 2005
@@ -880,7 +880,7 @@
 
 // First - replace all \r to \n
 
-   while ((tmt = strchr(Body,'\r')) != NULL) {
+   while ((tmt = strchr((char *) Body,'\r')) != NULL) {
       *tmt = '\n';
    }
 
