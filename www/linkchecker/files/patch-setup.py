--- setup.py.orig	2008-02-07 21:27:02.000000000 +0100
+++ setup.py	2008-02-07 21:27:42.000000000 +0100
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
@@ -500,11 +499,9 @@
       ]
 
 if os.name == 'posix':
-    data_files.append(('share/man/man1', ['doc/en/linkchecker.1']))
-    data_files.append(('share/man/man5', ['doc/en/linkcheckerrc.5']))
-    data_files.append(('share/man/de/man1', ['doc/de/linkchecker.1']))
-    data_files.append(('share/man/de/man5', ['doc/de/linkcheckerrc.5']))
-    data_files.append(('share/linkchecker/examples',
+    data_files.append(('man/man1', ['doc/en/linkchecker.1']))
+    data_files.append(('man/man5', ['doc/en/linkcheckerrc.5']))
+    data_files.append(('share/examples/linkchecker',
               ['config/linkchecker-completion',
                'doc/examples/check_blacklist.sh',
                'doc/examples/check_for_x_errors.sh',
