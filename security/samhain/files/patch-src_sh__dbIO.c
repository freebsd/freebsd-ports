--- src/sh_dbIO.c.orig	2021-10-22 01:34:14 UTC
+++ src/sh_dbIO.c
@@ -226,7 +226,8 @@ static unsigned short *  swap_short (unsigned short * 
   else
     {
       /* alignment problem */
-      static unsigned short ooop = *iptr;
+      static unsigned short ooop;
+      ooop = *iptr;
       unsigned short hi   = (ooop & 0xff00);
       unsigned short lo   = (ooop & 0xff);
       ooop = (lo << 8) | (hi >> 8);
