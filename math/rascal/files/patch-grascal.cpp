--- grascal.cpp.orig	Tue May 14 07:09:26 2002
+++ grascal.cpp	Sat Oct 18 14:51:09 2003
@@ -76,7 +76,7 @@
 
 int main(int argc,char **argv)
 {
-   Calterm a(string("grascal ")+string(VERSION),"/usr/local/bin/rascal","--shellcolour 4 --outputcolour 0");
+   Calterm a(string("grascal ")+string(VERSION),"%%PREFIX%%/bin/rascal","--shellcolour 4 --outputcolour 0");
 
    if(exist("./rascal"))
       a.setClientPath("./rascal");
@@ -91,7 +91,7 @@
    a.addMenu(new MenuFileSelect("/File/_Load","<control>L","Load Rascal File",rascal_load));
    a.addMenu(new MenuFileSelect("/File/_Save","<control>S","Save Rascal File",rascal_save));
    a.addMenu(new MenuSeparator("/File/sep1"));
-   a.addMenu(new MenuGtkFunction("/File/_Quit","<control>Q",gtk_main_quit));
+   a.addMenu(new MenuGtkFunction("/File/_Quit","<control>Q",(GtkItemFactoryCallback)gtk_main_quit));
 
    a.addMenu(new MenuTop("/_Show"));
    a.addMenu(new MenuSimpleSend("/Show/_Variables","","variables;\n"));
@@ -113,7 +113,7 @@
    a.addMenu(new MenuSimpleSend("/Help/Licence","","licence;\n"));
    a.addMenu(new MenuSimpleSend("/Help/Changelog","","help changes;\n"));
    a.addMenu(new MenuSeparator("/Help/sep2"));
-   a.addMenu(new MenuShowUrl("/Help/Manual","","file:/usr/local/doc/rascal/html/index.html"));
+   a.addMenu(new MenuShowUrl("/Help/Manual","","file:%%PREFIX%%/share/doc/rascal/html/index.html"));
    a.addMenu(new MenuSeparator("/Help/sep1"));
    a.addMenu(new MenuShowUrl("/Help/Rascal Homepage","","http://rascal.sourceforge.net/"));
          
