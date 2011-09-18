--- third_party/WebKit/Source/WebKit/chromium/WebKit.gyp.orig	2011-09-15 00:29:43.000000000 +0300
+++ third_party/WebKit/Source/WebKit/chromium/WebKit.gyp	2011-09-15 00:30:28.000000000 +0300
@@ -1142,6 +1142,7 @@
             ],
             'include_dirs': [
                 '<(chromium_src_dir)',
+                '<(prefix_dir)/include',
                 '../../../Tools/DumpRenderTree/TestNetscapePlugIn',
                 '../../../Tools/DumpRenderTree/chromium/TestNetscapePlugIn/ForwardingHeaders',
             ],
