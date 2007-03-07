--- setup.py	Sat Feb 18 16:22:43 2006
+++ setup.py	Wed Jan  3 23:38:53 2007
@@ -127,7 +127,7 @@
         ]
     files = [
         ('share/pixmaps', ['images/straw.png']),
-        ('share/straw', images + misc)]
+        ('share/gnome/straw', images + misc)]
     return files
 
 # Let distutils do the work
@@ -146,7 +146,7 @@
       pot_file         = 'po/straw.pot',
       translations     = translations(),
       modules_check    = modules_check,
-      msg_sources      = translation_files(),
+      msg_sources      = ['glade/strings.c'] + glob.glob('src/lib/*.py'),
       desktop_file     = ['straw.desktop.in'],
       constants        = [('constants.py.in', strawenv)],
       scripts          = ['src/straw'],
