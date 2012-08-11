--- tools/install.py.orig	2012-08-11 15:59:08.000000000 +0800
+++ tools/install.py	2012-08-11 15:59:36.000000000 +0800
@@ -191,7 +191,7 @@
           'deps/uv/include/uv-private/uv-unix.h',
           'deps/uv/include/uv-private/uv-win.h'],
           'include/node/uv-private/')
-  action(['doc/node.1'], 'share/man/man1/')
+  action(['doc/node.1'], 'man/man1/')
   action(['out/Release/node'], 'bin/node')
 
   # install unconditionally, checking if the platform supports dtrace doesn't
