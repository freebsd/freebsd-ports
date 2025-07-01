--- build_tools/scripts/core_common/make_common.py.orig	2025-06-11 12:56:35 UTC
+++ build_tools/scripts/core_common/make_common.py
@@ -8,21 +8,21 @@ import config
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
 import md
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
@@ -38,19 +38,19 @@ def make():
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
   md.make()
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
