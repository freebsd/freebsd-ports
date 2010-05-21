--- buffy.c.orig	2009-06-02 19:16:26.000000000 +0200
+++ buffy.c	2010-05-18 07:41:47.000000000 +0200
@@ -236,7 +236,6 @@
     {
       if(*tmp)
       {
-        FREE (&((*tmp)->path));
         tmp1=(*tmp)->next;
         FREE (tmp);		/* __FREE_CHECKED__ */
         *tmp=tmp1;
