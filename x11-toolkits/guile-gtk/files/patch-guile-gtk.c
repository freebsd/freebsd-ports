--- guile-gtk.c.orig	Wed Apr 30 23:26:36 2003
+++ guile-gtk.c	Wed Apr 30 23:27:57 2003
@@ -19,6 +19,7 @@
 #include <string.h>
 #include <config.h>
 #include <assert.h>
+#include <sys/types.h>
 #ifdef GTK_2_0
 #include <gtk-2.0/gtk/gtk.h>
 #include <gtk-2.0/gdk/gdkprivate.h>
@@ -44,6 +45,8 @@
 #ifndef SCM_VECTOR_SET
 #define SCM_VECTOR_SET(obj,i,v) (SCM_VELTS(obj)[i]=(v))
 #endif
+
+typedef unsigned long ulong;
 
 static SCM
 sgtk_make_cell (scm_t_bits word0, scm_t_bits word1)
