--- setup.py.orig	Tue Nov 21 17:49:07 2006
+++ setup.py	Wed Dec 27 12:28:29 2006
@@ -471,7 +471,6 @@
     # windows does not have unistd.h
     define_macros.append(('YY_NO_UNISTD_H', None))
 else:
-    extra_compile_args.append("-pedantic")
     if win_compiling:
         # we are cross compiling with mingw
         # add directory for pyconfig.h
@@ -488,7 +487,7 @@
 data_files = [
          ('share/linkchecker',
              ['config/linkcheckerrc', 'config/logging.conf', ]),
-         ('share/linkchecker/examples',
+         ('share/examples/linkchecker',
              ['cgi-bin/lconline/leer.html.en',
               'cgi-bin/lconline/leer.html.de',
               'cgi-bin/lconline/index.html',
@@ -500,10 +499,8 @@
       ]
 
 if os.name == 'posix':
-    data_files.append(('share/man/man1', ['doc/en/linkchecker.1']))
-    data_files.append(('share/man/de/man1', ['doc/de/linkchecker.1']))
-    data_files.append(('share/man/fr/man1', ['doc/fr/linkchecker.1']))
-    data_files.append(('share/linkchecker/examples',
+    data_files.append(('man/man1', ['doc/en/linkchecker.1']))
+    data_files.append(('share/examples/linkchecker',
               ['config/linkchecker-completion',
                'doc/examples/check_blacklist.sh',
                'doc/examples/check_for_x_errors.sh',
