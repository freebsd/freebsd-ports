--- sf_control.c.orig	Mon Dec 21 08:18:55 1998
+++ sf_control.c	Sat Nov  8 21:20:24 2003
@@ -266,7 +266,7 @@
 static char        xpm_filespec[MAX_FILESPEC+1]    = { 0 };
 
 static char        design_filespec[MAX_FILESPEC+1] = { 0 };
-static char        design_line = -1;
+static signed char        design_line = -1;
 static FILE*       design_file = (FILE*)0;
 
 /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
