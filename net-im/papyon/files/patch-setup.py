--- setup.py.orig	2010-12-19 02:32:37.000000000 -0500
+++ setup.py	2010-12-19 02:32:47.000000000 -0500
@@ -50,7 +50,7 @@ if pieces[-1] == '':
 else:
     len_root_dir = len(pieces)
 
-for directory in ('papyon', 'tests'):
+for directory in ('papyon',):
     papyon_dir = os.path.join(root_dir, directory)
     for dirpath, dirnames, filenames in os.walk(papyon_dir):
         # Ignore dirnames that start with '.'
