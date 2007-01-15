--- dl.c.orig	Sat Jan 13 15:30:02 2007
+++ dl.c	Sat Jan 13 15:36:34 2007
@@ -188,7 +188,7 @@ static inline int issafe(unsigned char c
   return (c!='"' && c>=' ' && c!='+');
 }
 
-unsigned long fmt_urlencoded(char* dest,const char* src,unsigned long len) {
+size_t fmt_urlencoded(char* dest,const char* src,size_t len) {
   register const unsigned char* s=(const unsigned char*) src;
   unsigned long written=0,i;
   for (i=0; i<len; ++i) {
