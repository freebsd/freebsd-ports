--- setup.py.orig	Mon Apr 26 12:17:31 2004
+++ setup.py	Thu May 20 13:41:56 2004
@@ -97,8 +97,8 @@
     '''Build list of data files to be installed'''
     images = glob.glob('images/*.png')
     files = [
-        ('share/pixmaps', ['images/straw.png']),
-        ('share/straw', images + ['data/default_subscriptions.opml', 'glade/straw.glade'])]
+        ('share/gnome/pixmaps', ['images/straw.png']),
+        ('share/gnome/straw', images + ['data/default_subscriptions.opml', 'glade/straw.glade'])]
     return files
 
 long_desc = '''\
@@ -121,9 +121,8 @@
       config_files     = [('gconf/schemas',['data/straw.schemas'],
                            'with-gconf-schema-file-dir')],
       scripts          = ['src/straw'],
-      modules_check    = modules_check,
       packages         = ['straw'],
       package_dir      = {'straw' : 'src/lib'},
-      msg_sources      = translation_files(),
+      msg_sources      = ['glade/strings.c'] + glob.glob('src/lib/*.py'),
       desktop_file     = ['straw.desktop.in'])
 
