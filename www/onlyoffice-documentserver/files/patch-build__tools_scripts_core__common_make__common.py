--- build_tools/scripts/core_common/make_common.py.orig	2021-11-16 07:07:24 UTC
+++ build_tools/scripts/core_common/make_common.py
@@ -8,17 +8,17 @@ import glob
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
-import harfbuzz
+#import harfbuzz
 
 def check_android_ndk_macos_arm(dir):
   if base.is_dir(dir + "/darwin-x86_64") and not base.is_dir(dir + "/darwin-arm64"):
@@ -33,14 +33,15 @@ def make():
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
   v8.make()
   html2.make()
-  hunspell.make(False)
-  harfbuzz.make()
+#  hunspell.make(False)
+#  harfbuzz.make()
   glew.make()
   if config.check_option("module", "mobile"):
     curl.make()
