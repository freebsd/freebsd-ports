--- routines/graphics/periGtk.c.orig	Tue Mar 21 18:51:59 2006
+++ routines/graphics/periGtk.c	Tue Mar 21 18:52:33 2006
@@ -862,8 +862,8 @@
 static void xset_curwin(integer *intnum, integer *v2, integer *v3, integer *v4)
 { 
   struct BCG *bcgk;
-  bcgk =  ScilabXgc ;
   integer ierr;
+  bcgk =  ScilabXgc ;
   /** send info to menu **/
   if (v2 != (integer *) 0) MenuFixCurrentWin(*intnum);
   if ( ScilabXgc == (struct BCG *) 0 ) 
