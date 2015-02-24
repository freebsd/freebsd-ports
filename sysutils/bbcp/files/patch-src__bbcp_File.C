--- src/bbcp_File.C.orig	2015-01-15 18:41:10.000000000 -0800
+++ src/bbcp_File.C	2015-01-15 18:43:04.000000000 -0800
@@ -44,7 +44,7 @@
 
 #ifdef FREEBSD
 #undef ENODATA
-#define ENODATA ENOATTRR
+#define ENODATA ENOATTR
 #endif
 
 /******************************************************************************/
@@ -153,7 +153,7 @@
 
 // Find a buffer
 //
-   if (bp = nextbuff)
+   if ((bp = nextbuff))
       while(bp && bp->boff != offset) {pp = bp; bp = bp->next;}
 
 // If we found a buffer, unchain it
