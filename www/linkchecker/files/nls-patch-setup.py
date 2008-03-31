--- setup.py.orig	2008-02-07 21:27:59.000000000 +0100
+++ setup.py	2008-02-07 21:28:56.000000000 +0100
@@ -501,6 +501,8 @@
 if os.name == 'posix':
     data_files.append(('man/man1', ['doc/en/linkchecker.1']))
     data_files.append(('man/man5', ['doc/en/linkcheckerrc.5']))
+    data_files.append(('man/de/man1', ['doc/de/linkchecker.1']))
+    data_files.append(('man/de/man5', ['doc/de/linkcheckerrc.5']))
     data_files.append(('share/examples/linkchecker',
               ['config/linkchecker-completion',
                'doc/examples/check_blacklist.sh',
