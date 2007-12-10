--- ezfm.h.orig	1999-10-06 00:01:29.000000000 +0200
+++ ezfm.h	2007-12-07 00:02:05.000000000 +0100
@@ -52,8 +52,11 @@
 #define REMOVABLE_DRIVES
 #endif
 /*************************************************************/
-EXTERN   int erron, sys_nerr;
+EXTERN   int erron;
+#ifndef __FreeBSD__
+EXTERN   int sys_nerr;
 EXTERN   char *sys_errlist[];
+#endif
 #define syserr(en) (((en) >= 0 && (en) < sys_nerr) ? sys_errlist[(en)] : "Unknown error")
 #define SECONDS_IN_YEAR         31536000
 #define SelectionBackground     "yellow"
@@ -253,7 +256,6 @@
 EXTERN char               ezfmFolderBgPixmap[];
 EXTERN EZ_Widget          *ezfmDragIcon;
 EXTERN Cursor             ezfmDragCursor;
-EXTERN Pixmap             rootBgPixmap;
 EXTERN EZ_LabelPixmap     *bigPixmap;  
 EXTERN int                transparent;
 EXTERN Display            *theDisplay;
