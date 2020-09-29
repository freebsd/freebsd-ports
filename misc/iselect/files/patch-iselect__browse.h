--- iselect_browse.h.orig	2007-07-08 09:27:18 UTC
+++ iselect_browse.h
@@ -31,7 +31,7 @@
 /*
  *  The Structure of our screen lines
  */
-struct Line { 
+extern struct Line { 
     char *cpLine;      /* the input line */
     int   fSelectable; /* whether selectable or not */
     int   fSelected;   /* whether already selected or not */
