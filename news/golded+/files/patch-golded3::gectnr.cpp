--- ./golded3/gectnr.cpp.orig	Wed Mar 22 23:59:18 2000
+++ ./golded3/gectnr.cpp	Mon Oct 20 02:40:51 2003
@@ -34,7 +34,7 @@
 void Container::StyleCodeHighlight(const char* text, int row, int col, bool dohide, int color) {
 
   uint sclen = 0;
-  char* txptr = text;
+  const char* txptr = text;
   char buf[200];
   const char* ptr = text;
   const char* stylemargins = " -|\\";    // we probably have to make a keyword for it
@@ -60,14 +60,14 @@
           if((bb <= 1) and (bi <= 1) and (br <= 1) and (bu <= 1) and *ptr) {
             const char* beginword = ptr;                       //  _/*>another*/_
             char endchar = NUL;
-            char* end = ptr;
+            char* end = const_cast<char *>(ptr);
             do {
               end = strpbrk(++end, punctchars);
             } while ((end) and not isstylechar(*(end-1)));
             if(end)
               endchar = *end;
             else
-              end = ptr+strlen(ptr);
+              end = const_cast<char *>(ptr+strlen(ptr));
             *end = NUL;
             char* endstyle = end-1;                      //  _/*another*/>_
             if(isstylechar(*endstyle) and not strchr(stylemargins, *beginword)) {
