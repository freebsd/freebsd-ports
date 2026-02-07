--- src/3rdparty/chromium/build/download_nacl_toolchains.py.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/build/download_nacl_toolchains.py
@@ -11,6 +11,10 @@ import sys
 
 
 def Main(args):
+  # If `disable_nacl=1` is in GYP_DEFINES, exit
+  if 'disable_nacl=1' in os.environ.get('GYP_DEFINES', ''):
+    return 0
+
   script_dir = os.path.dirname(os.path.abspath(__file__))
   src_dir = os.path.dirname(script_dir)
   nacl_dir = os.path.join(src_dir, 'native_client')
