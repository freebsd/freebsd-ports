--- mstorage_add_bin.c.orig	2008-04-25 13:09:34.000000000 +0200
+++ mstorage_add_bin.c	2008-04-25 21:47:27.000000000 +0200
@@ -6,7 +6,7 @@
  *   char 0;
  *   uint32 len;
  *   char data[len] */
-long mstorage_add_bin(mstorage_t* p,const char* s,unsigned long n) {
+long mstorage_add_bin(mstorage_t* p,const char* s,size_t n) {
   unsigned int i;
   static char zero;
   long x;
