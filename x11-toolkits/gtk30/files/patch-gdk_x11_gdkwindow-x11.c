This is a temporary patch.  It is already in GNOME CVS, and will be merged in
the next gtk+-2.0.x release.  More details on what this patch fixes can be
found at:

http://bugzilla.gnome.org/show_bug.cgi?id=94806

--- gdk/x11/gdkwindow-x11.c.orig	Sat Nov 16 19:25:15 2002
+++ gdk/x11/gdkwindow-x11.c	Sat Nov 16 19:26:16 2002
@@ -202,6 +202,8 @@
                             &window_attributes);
       drawable_impl->colormap =
         gdk_colormap_lookup (window_attributes.colormap);
+      if (drawable_impl->colormap)
+	g_object_ref (drawable_impl->colormap);
     }
   
   return drawable_impl->colormap;
