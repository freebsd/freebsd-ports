--- setup.py.orig	2009-08-26 15:56:00.000000000 +0200
+++ setup.py	2009-08-26 15:57:17.000000000 +0200
@@ -384,6 +386,8 @@
 if os.name == 'posix':
     data_files.append(('man/man1', ['doc/en/linkchecker.1']))
     data_files.append(('man/man5', ['doc/en/linkcheckerrc.5']))
+    data_files.append(('man/de/man1', ['doc/de/linkchecker.1']))
+    data_files.append(('man/de/man5', ['doc/de/linkcheckerrc.5']))
     data_files.append(('share/examples/linkchecker',
               ['config/linkchecker-completion',
                'doc/examples/check_blacklist.sh',
