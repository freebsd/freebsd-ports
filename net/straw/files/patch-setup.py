--- setup.py.orig	Tue Feb 17 13:31:30 2004
+++ setup.py	Tue Feb 17 13:32:32 2004
@@ -80,9 +80,9 @@
     '''Build list of data files to be installed'''
     images = glob.glob('images/*.png')
     files = [
-        ('share/pixmaps', ['images/straw.png']),        
-        ('share/applications', ['straw.desktop']),
-        ('share/straw', images +
+        ('share/gnome/pixmaps', ['images/straw.png']),        
+        ('share/gnome/applications', ['straw.desktop']),
+        ('share/gnome/straw', images +
          ['data/default_subscriptions.opml', 'glade/straw.glade'])]
     return files
 
