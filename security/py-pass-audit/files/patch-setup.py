--- setup.py.orig	2022-01-30 14:55:34 UTC
+++ setup.py
@@ -10,9 +10,13 @@ base = '/usr'
 
 share = Path(sys.prefix, 'share')
 base = '/usr'
-if os.uname().sysname == 'Darwin':
-    base = '/usr/local'
+if os.uname().sysname == 'Darwin' or os.uname().sysname == 'FreeBSD':
+    base = '%%PREFIX%%'
+
 lib = Path(base, 'lib', 'password-store', 'extensions')
+if os.uname().sysname == 'FreeBSD':
+    lib = Path(base, 'libexec', 'password-store', 'extensions')
+    share = Path(base, 'share')
 
 if '--user' in sys.argv:
     if 'PASSWORD_STORE_EXTENSIONS_DIR' in os.environ:
