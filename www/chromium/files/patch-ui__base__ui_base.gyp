--- ui/base/ui_base.gyp.orig	2014-10-02 17:39:48 UTC
+++ ui/base/ui_base.gyp
@@ -427,7 +427,7 @@
             'x/selection_utils.h',
           ]
         }],
-        ['use_aura==0 or OS!="linux"', {
+        ['use_aura==0 or (OS!="linux" and os_bsd!=1)', {
           'sources!': [
             'resource/resource_bundle_auralinux.cc',
           ],
