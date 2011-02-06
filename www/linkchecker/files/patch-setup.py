--- setup.py.orig	2011-02-06 03:58:59.454396452 +0300
+++ setup.py	2011-02-06 04:05:09.118442022 +0300
@@ -357,17 +357,14 @@
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
+    ['config/linkcheckerrc', 'config/logging.conf']),
+        ('share/examples/linkchecker',
         ['cgi-bin/lconline/leer.html.en',
          'cgi-bin/lconline/leer.html.de',
          'cgi-bin/lconline/index.html',
@@ -381,11 +378,9 @@
 ]
 
 if os.name == 'posix':
-    data_files.append(('share/man/man1', ['doc/en/linkchecker.1', 'doc/en/linkchecker-gui.1']))
-    data_files.append(('share/man/man5', ['doc/en/linkcheckerrc.5']))
-    data_files.append(('share/man/de/man1', ['doc/de/linkchecker.1', 'doc/de/linkchecker-gui.1']))
-    data_files.append(('share/man/de/man5', ['doc/de/linkcheckerrc.5']))
-    data_files.append(('share/linkchecker/examples',
+              data_files.append(('man/man1', ['doc/en/linkchecker.1']))
+              data_files.append(('man/man5', ['doc/en/linkcheckerrc.5']))
+              data_files.append(('share/examples/linkchecker',
               ['config/linkchecker-completion',
                'doc/examples/check_blacklist.sh',
                'doc/examples/check_for_x_errors.sh',
