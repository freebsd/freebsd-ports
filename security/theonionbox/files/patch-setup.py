--- setup.py.orig	2019-05-11 04:02:35 UTC
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
 
