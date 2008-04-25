--- mstorage_add.c.orig	2008-04-25 13:09:34.000000000 +0200
+++ mstorage_add.c	2008-04-25 21:46:42.000000000 +0200
@@ -19,7 +19,7 @@
 /* Sadly, mremap is only available on Linux */
 /* Please petition your congressman^Woperating system vendor to include it! */
 
-long mstorage_add(mstorage_t* p,const char* s,unsigned long n) {
+long mstorage_add(mstorage_t* p,const char* s,size_t n) {
   if (p->mapped-p->used<n) {
     if (!p->root) {
       /* nothing allocated.  mmap /dev/zero */
