--- common/setup.py.orig	Sun Apr  3 14:40:00 2005
+++ common/setup.py	Thu Apr 28 00:56:41 2005
@@ -24,8 +24,6 @@
 		sources = ['idle.c'],
 #               extra_compile_args = ['-W'],
                 libraries = ['gtk-x11-2.0','gdk-x11-2.0','glib-2.0','X11','Xext','Xss','atk-1.0'],
-                library_dirs = ['/usr/X11R6/lib'],
-                include_dirs = ['/usr/include/gtk-2.0', '/usr/include/glib-2.0','/usr/lib/gtk-2.0/include','/usr/lib/glib-2.0/include','/usr/include/pango-1.0','/usr/include/atk-1.0']
 	)
 elif os.name == 'nt':
 	module1 = Extension( 'idle',
