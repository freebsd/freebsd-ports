--- src/Editeur.cc.orig	2026-01-28 09:16:56 UTC
+++ src/Editeur.cc
@@ -3134,7 +3134,7 @@ namespace xcas {
     Fl_Text_Buffer * b = new Fl_Text_Buffer;
     editor=new Xcas_Text_Editor(x,y+L,w,h-L,b,l);
     editor->Fl_Text_Display::textsize(labelsize());
-    editor->Fl_Text_Display::linenumber_width(3*labelsize());
+    // editor->Fl_Text_Display::linenumber_width(3*labelsize());
     editor->labelsize(labelsize());
     log = 0;
     if (
