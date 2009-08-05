--- setup.py	2009-07-28 15:20:50.000000000 -0300
+++ patch-setup.py	2009-08-05 08:41:06.000000000 -0300
@@ -40,9 +40,8 @@
         scripts = ['bin/lshell'],
         package_dir = {'':'lshellmodule'},
         packages = [''],
-        data_files = [('/etc', ['etc/lshell.conf']),
-            ('share/doc/lshell',['README', 'COPYING', 'CHANGES']),
-            ('share/man/man1/', ['man/lshell.1']) ],
+        data_files = [('etc', ['etc/lshell.conf']),
+            ('man/man1/', ['man/lshell.1']) ],
         classifiers=[
                 'Development Status :: 4 - Beta',
                 'Environment :: Console'
