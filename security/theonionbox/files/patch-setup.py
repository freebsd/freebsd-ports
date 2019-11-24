--- setup.py.orig	2019-05-10 21:59:01 UTC
+++ setup.py
@@ -295,19 +295,9 @@ package_data_exclude = {
 }
 
 data_files = [
-    ('docs', ['docs/*.*']),
-    ('', ['readme/README.html']),
-    ('config', ['theonionbox/config/*.*']),
-    ('service', []),
-    ('service/FreeBSD', ['FreeBSD/theonionbox.sh']),
-    ('service/init.d', ['init.d/theonionbox.sh']),
-    ('service/systemd', ['systemd/theonionbox.service']),
-    ('service/Docker', ['Docker/Dockerfile', 'Docker/theonionbox.cfg']),
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
 
@@ -381,10 +371,10 @@ setup(
         'requests>=2.21',
         'PySocks>=1.6.7',
         'bottle>=0.12.13',
-        'stem>=1.5.4, <=1.6',
+        'stem>=1.5.4',
         'tzlocal>=1.5',
         'futures>=3.2; python_version<"3.0"',
-        'urllib3>=1.24.2, <1.25'    # '<1.25' due to requests 2.21 requirement
+        'urllib3>=1.21.1,<1.26' # copied (except the exclusions) from requests 2.22
     ],
     long_description_content_type='text/x-rst; charset=UTF-8',
     classifiers=[
