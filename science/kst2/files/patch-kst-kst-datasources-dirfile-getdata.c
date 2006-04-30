--- kst/kst/datasources/dirfile/getdata.c.orig	Sun Apr 30 01:25:45 2006
+++ kst/kst/datasources/dirfile/getdata.c	Sun Apr 30 01:45:10 2006
@@ -1012,8 +1012,8 @@
 /*                                                                         */
 /***************************************************************************/
 static void *AllocTmpbuff(char type, int n) {
-  assert(n > 0);
   void *buff=NULL;
+  assert(n > 0);
   switch(type) {
     case 'n':
       buff = NULL;
