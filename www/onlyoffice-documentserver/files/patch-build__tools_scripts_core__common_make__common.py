--- build_tools/scripts/core_common/make_common.py.orig	2021-11-16 07:07:24 UTC
+++ build_tools/scripts/core_common/make_common.py
@@ -8,15 +8,15 @@ import config
 import base
 import glob
 
-import boost
-import cef
-import icu
-import openssl
+#import boost
+#import cef
+#import icu
+#import openssl
 import curl
 import websocket
 import v8
 import html2
-import hunspell
+#import hunspell
 import glew
 
 def check_android_ndk_macos_arm(dir):
@@ -32,13 +32,15 @@ def make():
       if base.is_dir(toolchain):
         check_android_ndk_macos_arm(toolchain + "/prebuilt")
 
-  boost.make()
-  cef.make()
-  icu.make()
-  openssl.make()
+  if base.host_platform() != 'freebsd' :
+    boost.make()
+    cef.make()
+    icu.make()
+    openssl.make()
+
   v8.make()
   html2.make()
-  hunspell.make(False)
+#  hunspell.make(False)
   glew.make()
   if config.check_option("module", "mobile"):
     curl.make()
