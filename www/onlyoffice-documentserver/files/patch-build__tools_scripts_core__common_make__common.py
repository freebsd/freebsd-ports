--- build_tools/scripts/core_common/make_common.py.orig	2025-10-15 14:25:47 UTC
+++ build_tools/scripts/core_common/make_common.py
@@ -8,24 +8,24 @@
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
 import oo_brotli
-import hyphen
-import googletest
+#import hyphen
+#import googletest
 import libvlc
-import heif
+#import heif
 
 def check_android_ndk_macos_arm(dir):
   if base.is_dir(dir + "/darwin-x86_64") and not base.is_dir(dir + "/darwin-arm64"):
@@ -40,21 +40,21 @@
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
   oo_brotli.make()
-  heif.make()
+#  heif.make()
 
   if config.check_option("build-libvlc", "1"):
     libvlc.make()
