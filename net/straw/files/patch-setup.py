--- setup.py	Sat Feb 18 16:22:43 2006
+++ setup.py	Wed Jan  3 23:38:53 2007
@@ -146,7 +146,7 @@
       pot_file         = 'po/straw.pot',
       translations     = translations(),
       modules_check    = modules_check,
-      msg_sources      = translation_files(),
+      msg_sources      = ['glade/strings.c'] + glob.glob('src/lib/*.py'),
       desktop_file     = ['straw.desktop.in'],
       constants        = [('constants.py.in', strawenv)],
       scripts          = ['src/straw'],
