--- httpencode.cpp.orig	Sun Jan 11 05:51:45 2004
+++ httpencode.cpp	Sun Jan 18 02:43:16 2004
@@ -10,6 +10,7 @@
 /* NOTE: */
 /* LINUX/WINDOWS IMPLEMENT's STANDARD C LIBRARY NO strnstr FOUND */
 /* FUNCTION PROGRAMER: Siberiaic Sang */
+#if 0
 static char* strnstr(const char *haystack,const char *needle,size_t haystacklen)
 {
    char *p;
@@ -30,6 +31,7 @@ static char* strnstr(const char *haystac
   }
   return (char*) 0;
 }
+#endif
 /* ************************************************** */
 
 static void url_encode_char(char *b,char c)
