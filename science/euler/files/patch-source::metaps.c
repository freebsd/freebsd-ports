--- metaps.c.orig	Sat Jul 19 02:38:38 2003
+++ metaps.c	Sat Jul 19 02:39:09 2003
@@ -209,7 +209,7 @@
 //	rectangle clipping
 //	x1 y1 x2 y2 setclip
 static char setclipmacro[]= "/setclip {\n\
-gsave
+gsave\
 	/y2 exch def\n\
 	/x2 exch def\n\
 	/y1 exch def\n\
