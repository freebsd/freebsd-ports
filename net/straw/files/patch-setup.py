--- setup.py.orig	Fri Feb 20 17:53:55 2004
+++ setup.py	Fri Feb 20 17:54:20 2004
@@ -79,9 +79,9 @@
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
 
