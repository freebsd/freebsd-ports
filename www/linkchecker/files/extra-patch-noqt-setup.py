--- setup.py.orig	2014-04-23 22:52:23.000000000 +0200
+++ setup.py	2014-06-16 21:07:43.000000000 +0200
@@ -627,7 +627,7 @@
 # libraries
 libraries = []
 # scripts
-scripts = ['linkchecker', 'linkchecker-gui']
+scripts = ['linkchecker']
 
 if os.name == 'nt':
     # windows does not have unistd.h
@@ -658,9 +658,9 @@
 ]
 
 if os.name == 'posix':
-    data_files.append(('share/man/man1', ['doc/en/linkchecker.1', 'doc/en/linkchecker-gui.1']))
+    data_files.append(('share/man/man1', ['doc/en/linkchecker.1']))
     data_files.append(('share/man/man5', ['doc/en/linkcheckerrc.5']))
-    data_files.append(('share/man/de/man1', ['doc/de/linkchecker.1', 'doc/de/linkchecker-gui.1']))
+    data_files.append(('share/man/de/man1', ['doc/de/linkchecker.1']))
     data_files.append(('share/man/de/man5', ['doc/de/linkcheckerrc.5']))
     data_files.append(('share/linkchecker/examples',
               ['config/linkchecker-completion',
@@ -668,7 +668,6 @@
                'doc/examples/check_for_x_errors.sh',
                'doc/examples/check_urls.sh']))
     data_files.append(('share/applications', ['doc/linkchecker.desktop']))
-    data_files.append(('share/applications', ['doc/linkchecker-gui.desktop']))
 if 'py2app' in sys.argv[1:]:
     if not has_py2app:
         raise SystemExit("py2app module could not be imported.")
