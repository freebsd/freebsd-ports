--- grascal.cpp.orig	Fri Jul 13 10:04:16 2001
+++ grascal.cpp	Fri Jul 13 10:05:23 2001
@@ -91,7 +91,7 @@
    a.addMenu(new MenuFileSelect("/File/_Load","<control>L","Load Rascal File",rascal_load));
    a.addMenu(new MenuFileSelect("/File/_Save","<control>S","Save Rascal File",rascal_save));
    a.addMenu(new MenuSeparator("/File/sep1"));
-   a.addMenu(new MenuGtkFunction("/File/_Quit","<control>Q",gtk_main_quit));
+   a.addMenu(new MenuGtkFunction("/File/_Quit","<control>Q",(GtkItemFactoryCallback)gtk_main_quit));
 
    a.addMenu(new MenuTop("/_Show"));
    a.addMenu(new MenuSimpleSend("/Show/_Variables","","variables;\n"));
