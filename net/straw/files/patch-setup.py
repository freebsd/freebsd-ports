--- setup.py.orig	Thu Jul 15 15:15:58 2004
+++ setup.py	Mon Aug 16 22:15:09 2004
@@ -108,8 +108,8 @@
     '''Build list of data files to be installed'''
     images = glob.glob('images/*.png')
     files = [
-        ('share/pixmaps', ['images/straw.png']),
-        ('share/straw', images + ['data/default_subscriptions.opml', 'data/straw.css', 'glade/straw.glade'])]
+        ('share/gnome/pixmaps', ['images/straw.png']),
+        ('share/gnome/straw', images + ['data/default_subscriptions.opml', 'data/straw.css', 'glade/straw.glade'])]
     return files
 
 long_desc = '''\
@@ -137,10 +137,9 @@
       #config_files     = [('gconf/schemas',['data/straw.schemas'],
       #                     'with-gconf-schema-file-dir')],
       scripts          = ['src/straw'],
-      modules_check    = modules_check,
       packages         = ['straw'],
       package_dir      = {'straw' : 'src/lib'},
-      msg_sources      = translation_files(),
+      msg_sources      = ['glade/strings.c'] + glob.glob('src/lib/*.py'),
       desktop_file     = ['straw.desktop.in'],
       ext_modules      = [TemplateExtension(name='trayicon',
                                             pkc_name='pygtk-2.0 gtk+-2.0',
