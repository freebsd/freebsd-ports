Patch that fixes a bug with Galeon. Should go after 0.9. Obtained from
http://bugzilla.mozilla.org/show_bug.cgi?id=79022.

$FreeBSD$

--- widget/src/gtksuperwin/gtkmozarea.h.orig	Thu May  3 07:11:02 2001
+++ widget/src/gtksuperwin/gtkmozarea.h	Tue May 22 17:18:26 2001
@@ -39,6 +39,9 @@
   GtkWidget widget;
   GdkSuperWin *superwin;
   gboolean     toplevel_focus;
+
+  /* store away the toplevel window */
+  GdkWindow *toplevel_window;
 };
   
 struct _GtkMozAreaClass
