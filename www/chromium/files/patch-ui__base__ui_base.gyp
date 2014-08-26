--- ./ui/base/ui_base.gyp.orig	2014-08-20 21:02:15.000000000 +0200
+++ ./ui/base/ui_base.gyp	2014-08-22 15:06:27.000000000 +0200
@@ -366,7 +366,7 @@
             'x/selection_utils.h',
           ]
         }],
-        ['use_aura==0 or OS!="linux"', {
+        ['use_aura==0 or (OS!="linux" and os_bsd!=1)', {
           'sources!': [
             'resource/resource_bundle_auralinux.cc',
           ],
