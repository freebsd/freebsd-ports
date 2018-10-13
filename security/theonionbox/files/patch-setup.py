--- setup.py.orig	2018-10-13 20:39:26 UTC
+++ setup.py
@@ -295,18 +295,9 @@ package_data_exclude = {
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
 
@@ -375,8 +366,7 @@ setup(
     },
     install_requires=[
         'psutil>=5.4.0',
-        'apscheduler>=2.1.2, <3.*; python_version<"3.0"',
-        'apscheduler>=3.4; python_version>="3.0"',
+        'apscheduler>=3.5.1',
         'requests>2.18',
         'PySocks>=1.6.7',
         'bottle>=0.12.13',
