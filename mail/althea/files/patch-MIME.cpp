--- MIME.cpp.orig	Wed Jan 23 02:30:15 2002
+++ MIME.cpp	Fri Dec 27 03:56:30 2002
@@ -91,7 +91,7 @@
 }
 
 void check(unsigned int convertedVal, ifstream &fileIn, int loc, int counter)  {
-   unsigned char c;
+   char c;
 
    fileIn.get(c);
    if ((unsigned int)c!=convertedVal)  {
