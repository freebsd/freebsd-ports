--- tools/install.py.orig	2012-08-29 04:51:31.000000000 +0800
+++ tools/install.py	2012-09-04 13:26:40.000000000 +0800
@@ -135,7 +135,7 @@
           'deps/uv/include/uv-private/uv-unix.h',
           'deps/uv/include/uv-private/uv-win.h'],
           'include/node/uv-private/')
-  action(['doc/node.1'], 'share/man/man1/')
+  action(['doc/node.1'], 'man/man1/')
   action(['out/Release/node'], 'bin/node')
 
   # install unconditionally, checking if the platform supports dtrace doesn't
@@ -143,7 +143,7 @@
   # with dtrace support now (oracle's "unbreakable" linux)
   action(['src/node.d'], 'lib/dtrace/')
 
-  if variables.get('node_install_npm'): npm_files(action)
+  if 'true' == variables.get('node_install_npm'): npm_files(action)
 
 def run(args):
   global dst_dir, node_prefix, target_defaults, variables
