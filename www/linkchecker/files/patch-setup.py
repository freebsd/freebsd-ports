--- setup.py.orig	Wed Apr 13 23:03:04 2005
+++ setup.py	Sun May 22 11:44:58 2005
@@ -413,7 +413,6 @@
     # windows does not have unistd.h
     define_macros.append(('YY_NO_UNISTD_H', None))
 else:
-    extra_compile_args.append("-pedantic")
     if win_compiling:
         # we are cross compiling with mingw
         # add directory for pyconfig.h
@@ -430,7 +429,7 @@
 data_files = [
          ('share/linkchecker',
              ['config/linkcheckerrc', 'config/logging.conf', ]),
-         ('share/linkchecker/examples',
+         ('share/examples/linkchecker',
              ['cgi/lconline/leer.html.en', 'cgi/lconline/leer.html.de',
               'cgi/lconline/index.html', 'cgi/lconline/lc_cgi.html.en',
               'cgi/lconline/lc_cgi.html.de', 'cgi/lconline/check.js',
@@ -438,10 +437,8 @@
       ]
 
 if os.name == 'posix':
-    data_files.append(('share/man/man1', ['doc/en/linkchecker.1']))
-    data_files.append(('share/man/de/man1', ['doc/de/linkchecker.1']))
-    data_files.append(('share/man/fr/man1', ['doc/fr/linkchecker.1']))
-    data_files.append(('share/linkchecker/examples',
+    data_files.append(('man/man1', ['doc/en/linkchecker.1']))
+    data_files.append(('share/examples/linkchecker',
               ['config/linkchecker-completion', 'config/linkcheck-cron.sh']))
 elif win_compiling:
     data_files.append(('share/linkchecker/doc',
