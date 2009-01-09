--- I2Ohash/src/util.c.orig	2008-12-27 21:44:52.000000000 -0500
+++ I2Ohash/src/util.c	2008-12-27 21:52:46.000000000 -0500
@@ -39,7 +39,8 @@
 */
 loc1 = (key1 + 1) % hashtable->nlist ;
 loc2 = (key2 + 1) % hashtable->nlist ;
-loc  = (loc1*loc2) % hashtable->nlist ;
+long int loc3 = (long int)loc1*(long int)loc2 % hashtable->nlist ;
+loc =(int) loc3;
 #if MYDEBUG > 0
 fprintf(stdout, "\n loc1 = %d, loc2 = %d, loc3 = %d", loc1, loc2, loc) ;
 fflush(stdout) ;
@@ -50,7 +51,7 @@
    --------------------------------------------------------
 */
 #if MYDEBUG > 0
-fprintf(stdout, "\n hashtable->freeI2OP = %p", hashtable->freeI2OP) ;
+fprintf(stdout, "\n loc1 = %d, loc2 = %d, loc3 = %ld, loc = %d", loc1, loc2, loc3, loc) ;
 fflush(stdout) ;
 #endif
 if ( (i2op = hashtable->freeI2OP) == NULL ) {
@@ -158,9 +159,10 @@
 #endif
 loc1 = (key1 + 1) % hashtable->nlist ;
 loc2 = (key2 + 1) % hashtable->nlist ;
-loc  = (loc1*loc2) % hashtable->nlist ;
+long int loc3 = (long int)loc1*(long int)loc2 % hashtable->nlist ;
+loc =(int) loc3;
 #if MYDEBUG > 0
-fprintf(stdout, "\n loc1 = %d, loc2 = %d, loc3 = %d", loc1, loc2, loc) ;
+fprintf(stdout, "\n loc1 = %d, loc2 = %d, loc3 = %ld, loc = %d", loc1, loc2, loc3, loc) ;
 fflush(stdout) ;
 #endif
 /*
