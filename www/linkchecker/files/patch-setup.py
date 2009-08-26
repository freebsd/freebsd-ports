--- setup.py.orig	2009-08-03 23:53:01.000000000 +0200
+++ setup.py	2009-08-26 15:56:00.000000000 +0200
@@ -364,17 +361,14 @@
 if os.name == 'nt':
     # windows does not have unistd.h
     define_macros.append(('YY_NO_UNISTD_H', None))
-else:
-    extra_compile_args.append("-pedantic")
 
 myname = "Bastian Kleineidam"
 myemail = "calvin@users.sourceforge.net"
 
 data_files = [
     ('share/linkchecker',
-        ['config/linkcheckerrc', 'config/logging.conf',
-        'doc/html/lccollection.qhc', 'doc/html/lcdoc.qch']),
-    ('share/linkchecker/examples',
+        ['config/linkcheckerrc', 'config/logging.conf']),
+    ('share/examples/linkchecker',
         ['cgi-bin/lconline/leer.html.en',
          'cgi-bin/lconline/leer.html.de',
          'cgi-bin/lconline/index.html',
@@ -388,11 +382,9 @@
 ]
 
 if os.name == 'posix':
-    data_files.append(('share/man/man1', ['doc/en/linkchecker.1', 'doc/en/linkchecker-gui.1']))
-    data_files.append(('share/man/man5', ['doc/en/linkcheckerrc.5']))
-    data_files.append(('share/man/de/man1', ['doc/de/linkchecker.1', 'doc/de/linkchecker-gui.1']))
-    data_files.append(('share/man/de/man5', ['doc/de/linkcheckerrc.5']))
-    data_files.append(('share/linkchecker/examples',
+    data_files.append(('man/man1', ['doc/en/linkchecker.1']))
+    data_files.append(('man/man5', ['doc/en/linkcheckerrc.5']))
+    data_files.append(('share/examples/linkchecker',
               ['config/linkchecker-completion',
                'doc/examples/check_blacklist.sh',
                'doc/examples/check_for_x_errors.sh',
