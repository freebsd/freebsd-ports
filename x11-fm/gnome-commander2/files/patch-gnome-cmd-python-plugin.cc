--- ./src/gnome-cmd-python-plugin.cc.orig       2007-09-10 07:38:08.000000000
+0000
+++ ./src/gnome-cmd-python-plugin.cc    2007-09-11 00:29:03.000000000 +0000
@@ -54,6 +54,11 @@
     }

     long dir_size = pathconf(".", _PC_PATH_MAX);
+    if( -1 == dir_size )
+    {
+        g_warning ( "pathconf(.): %s", strerror(errno) );
+       return;
+    }
     gchar *prev_dir = (gchar *) g_malloc (dir_size);

     if (!prev_dir)
