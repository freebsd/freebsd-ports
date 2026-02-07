--- src/Editeur.cc.orig	2022-03-09 17:34:39 UTC
+++ src/Editeur.cc
@@ -2924,7 +2924,7 @@ namespace xcas {
     Fl_Text_Buffer * b = new Fl_Text_Buffer;
     editor=new Xcas_Text_Editor(x,y+L,w,h-L,b,l);
     editor->Fl_Text_Display::textsize(labelsize());
-    editor->Fl_Text_Display::linenumber_width(3*labelsize());
+    // editor->Fl_Text_Display::linenumber_width(3*labelsize());
     editor->labelsize(labelsize());
     log = 0;
     if (logo){
