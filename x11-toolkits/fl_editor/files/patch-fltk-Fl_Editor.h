--- fltk/Fl_Editor.h.orig	Thu Dec 21 16:37:24 2006
+++ fltk/Fl_Editor.h	Thu Dec 21 16:55:36 2006
@@ -186,7 +186,7 @@
 	FL_API long FindRow(short screenY);
 	FL_API void HandleScroll();
 	FL_API void Cut();
-	static FL_API void Fl_Editor::draw_clip(void *v, int X, int Y, int W, int H);
+	static FL_API void draw_clip(void *v, int X, int Y, int W, int H);
 	FL_API void resize(int x, int y, int w, int h);
 #if (FL_MAJOR_VERSION > 1)
 	void layout(){ Fl_Group::layout(); resize(x(), y(),w(), h()); redraw(); }
