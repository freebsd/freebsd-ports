--- tools/install.py.orig	2024-03-26 14:14:20 UTC
+++ tools/install.py
@@ -182,7 +182,7 @@ def files(options, action):
   action(options, [os.path.join(options.v8_dir, 'tools/gdbinit')], 'share/doc/node/')
   action(options, [os.path.join(options.v8_dir, 'tools/lldb_commands.py')], 'share/doc/node/')
 
-  if 'freebsd' in sys.platform or 'openbsd' in sys.platform:
+  if 'openbsd' in sys.platform:
     action(options, ['doc/node.1'], 'man/man1/')
   else:
     action(options, ['doc/node.1'], 'share/man/man1/')
