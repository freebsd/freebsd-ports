--- setup.py	Wed Dec 27 12:28:29 2006
+++ setup.py	Wed Dec 27 12:28:04 2006
@@ -500,6 +500,8 @@
 
 if os.name == 'posix':
     data_files.append(('man/man1', ['doc/en/linkchecker.1']))
+    data_files.append(('man/de/man1', ['doc/de/linkchecker.1']))
+    data_files.append(('man/fr/man1', ['doc/fr/linkchecker.1']))
     data_files.append(('share/examples/linkchecker',
               ['config/linkchecker-completion',
                'doc/examples/check_blacklist.sh',
