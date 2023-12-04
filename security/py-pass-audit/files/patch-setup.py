--- setup.py.orig	2023-12-04 19:45:19 UTC
+++ setup.py
@@ -10,9 +10,12 @@ base = '/usr'
 
 share = Path(sys.prefix, 'share')
 base = '/usr'
-if os.uname().sysname == 'Darwin':
+if os.uname().sysname == 'Darwin' or os.uname().sysname == 'FreeBSD':
     base = '/usr/local'
+
 lib = Path(base, 'lib', 'password-store', 'extensions')
+if os.uname().sysname == 'FreeBSD':
+    lib = Path(base, 'libexec', 'password-store', 'extensions')
 
 if '--user' in sys.argv:
     if 'PASSWORD_STORE_EXTENSIONS_DIR' in os.environ:
