--- ttf/export_ttf.c.orig	Fri Sep  2 21:30:43 2005
+++ ttf/export_ttf.c	Tue Nov 22 21:27:53 2005
@@ -274,10 +274,10 @@
 
 	char *oldmodule;
 
+	scheme *sc;
+
 	oldmodule=curmodule;
 	curmodule="scheme";
-
-	scheme *sc;
 
 	info("TinyScheme, Copyright (c) 2000, Dimitrios Souflis. All rights reserved.");
 
