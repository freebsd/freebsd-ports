--- ui/base/ui_base.gyp.orig	2014-10-10 08:54:18 UTC
+++ ui/base/ui_base.gyp
@@ -434,7 +434,7 @@
             'x/selection_utils.h',
           ]
         }],
-        ['use_aura==0 or OS!="linux"', {
+        ['use_aura==0 or (OS!="linux" and os_bsd!=1)', {
           'sources!': [
             'resource/resource_bundle_auralinux.cc',
           ],
