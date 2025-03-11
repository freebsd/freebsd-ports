--- build_tools/scripts/core_common/make_common.py.orig	2021-11-16 07:07:24 UTC
+++ build_tools/scripts/core_common/make_common.py
@@ -8,20 +8,20 @@ import glob
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
 import websocket_all
 import v8
 import html2
 import iwork
-import hunspell
+#import hunspell
 import glew
 import harfbuzz
-import hyphen
-import googletest
+#import hyphen
+#import googletest
 import libvlc
 
 def check_android_ndk_macos_arm(dir):
@@ -37,18 +37,18 @@ def make():
       if base.is_dir(toolchain):
         check_android_ndk_macos_arm(toolchain + "/prebuilt")
 
-  boost.make()
-  cef.make()
-  icu.make()
-  openssl.make()
+#  boost.make()
+#  cef.make()
+#  icu.make()
+#  openssl.make()
   v8.make()
   html2.make()
   iwork.make(False)
-  hunspell.make(False)
-  harfbuzz.make()
+#  hunspell.make(False)
+#  harfbuzz.make()
   glew.make()
-  hyphen.make()
-  googletest.make()
+#  hyphen.make()
+#  googletest.make()
 
   if config.check_option("build-libvlc", "1"):
     libvlc.make()
