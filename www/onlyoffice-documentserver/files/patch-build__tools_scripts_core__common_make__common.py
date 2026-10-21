--- build_tools/scripts/core_common/make_common.py.orig	2026-09-30 13:05:36 UTC
+++ build_tools/scripts/core_common/make_common.py
@@ -8,25 +8,25 @@
 import base
 import glob
 
-import boost
-import libxml2
-import cef
-import icu
-import openssl
+#import boost
+#import libxml2
+#import cef
+#import icu
+#import openssl
 import curl
 import websocket_all
 import v8
-import html2
+#import html2
 import iwork
-import md
-import hunspell
+#import md
+#import hunspell
 import glew
 import harfbuzz
-import oo_brotli
-import hyphen
-import googletest
+#import oo_brotli
+#import hyphen
+#import googletest
 import libvlc
-import heif
+#import heif
 
 def check_android_ndk_macos_arm(dir):
   if base.is_dir(dir + "/darwin-x86_64") and not base.is_dir(dir + "/darwin-arm64"):
@@ -41,23 +41,23 @@
       if base.is_dir(toolchain):
         check_android_ndk_macos_arm(toolchain + "/prebuilt")
 
-  boost.make()
-  libxml2.make()
-  cef.make()
-  icu.make()
-  openssl.make()
+#  boost.make()
+#  libxml2.make()
+#  cef.make()
+#  icu.make()
+#  openssl.make()
   v8.make()
-  html2.make()
+#  html2.make()
   iwork.make(False)
-  md.make()
-  hunspell.make(False)
-  harfbuzz.make()
-  glew.make()
-  hyphen.make()
-  googletest.make()
-  oo_brotli.make()
-  heif.make()
-  websocket_all.make()
+#  md.make()
+#  hunspell.make(False)
+#  harfbuzz.make()
+#  glew.make()
+#  hyphen.make()
+#  googletest.make()
+#  oo_brotli.make()
+#  heif.make()
+#  websocket_all.make()
 
   if config.check_option("build-libvlc", "1"):
     libvlc.make()
