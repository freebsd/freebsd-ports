--- efltk/Fl_Text_Buffer.h.orig	Sun Jan 28 17:53:23 2007
+++ efltk/Fl_Text_Buffer.h	Sun Jan 28 17:53:30 2007
@@ -78,7 +78,7 @@
    Fl_Text_Buffer(int requestedSize = 0);
    ~Fl_Text_Buffer();
 
-   char *Fl_Text_Buffer::static_buffer();
+   char *static_buffer();
 
     // Undo stack size: (default 50)
    int undo_size();
