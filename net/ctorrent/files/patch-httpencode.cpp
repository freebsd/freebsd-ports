diff -u -r CTorrent-1.3r1/httpencode.cpp CTorrent-1.3r1.new/httpencode.cpp
--- httpencode.cpp	Sat Jan 10 20:51:45 2004
+++ httpencode.cpp.new	Fri Jan 23 17:22:28 2004
@@ -10,6 +10,8 @@
 /* NOTE: */
 /* LINUX/WINDOWS IMPLEMENT's STANDARD C LIBRARY NO strnstr FOUND */
 /* FUNCTION PROGRAMER: Siberiaic Sang */
+
+#if defined(__win32__) || defined(__linux__)
 static char* strnstr(const char *haystack,const char *needle,size_t haystacklen)
 {
    char *p;
@@ -30,6 +32,7 @@
   }
   return (char*) 0;
 }
+#endif
 /* ************************************************** */
 
 static void url_encode_char(char *b,char c)
