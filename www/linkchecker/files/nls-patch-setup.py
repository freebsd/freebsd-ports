--- setup.py.orig	2011-02-06 04:07:27.486400241 +0300
+++ setup.py	2011-02-06 04:08:17.222411661 +0300
@@ -380,6 +380,8 @@
 if os.name == 'posix':
               data_files.append(('man/man1', ['doc/en/linkchecker.1']))
               data_files.append(('man/man5', ['doc/en/linkcheckerrc.5']))
+              data_files.append(('man/de/man1', ['doc/de/linkchecker.1']))
+              data_files.append(('man/de/man5', ['doc/de/linkcheckerrc.5']))
               data_files.append(('share/examples/linkchecker',
               ['config/linkchecker-completion',
                'doc/examples/check_blacklist.sh',
