--- setup.py.orig	2018-05-28 18:32:09 UTC
+++ setup.py
@@ -294,18 +294,9 @@ package_data_exclude = {
 }
 
 data_files = [
-    ('docs', ['docs/*.*']),
-    ('', ['readme/README.html']),
-    ('config', ['theonionbox/config/*.*']),
-    ('service', []),
-    ('service/FreeBSD', ['FreeBSD/theonionbox.sh']),
-    ('service/init.d', ['init.d/theonionbox.sh']),
-    ('service/systemd', ['systemd/theonionbox.service']),
-    ('support', []),
-    ('support/osxtemp', []),
-    ('support/osxtemp/libsmc', ['support/osxtemp/libsmc/LICENSE', 'support/osxtemp/libsmc/Makefile']),
-    ('support/osxtemp/libsmc/include', ['support/osxtemp/libsmc/include/smc.h']),
-    ('support/osxtemp/libsmc/src', ['support/osxtemp/libsmc/src/smc.c']),
+    ('share/doc/theonionbox', ['docs/*.*']),
+    ('etc/theonionbox', ['theonionbox/config/*.*']),
+    ('etc/rc.d', ['FreeBSD/theonionbox']),
 ]
 # print(generate_data_files(data_files))
 
@@ -374,13 +365,12 @@ setup(
     },
     install_requires=[
         'psutil>=5.4.0',
-        'apscheduler>=2.1.2, <3.*; python_version<"3.0"',
-        'apscheduler>=3.4; python_version>="3.0"',
+        'apscheduler>=3.5.1',
         'requests>2.18',
         'PySocks>=1.6.7',
         'bottle>=0.12.13',
         'stem>=1.5.4',
-        'tzlocal>=1.5',
+        'tzlocal>=1.4',
         'futures>=3.2; python_version<"3.0"',
         'urllib3>=1.22'
     ],
