--- ui/base/ui_base.gyp.orig	2016-05-11 19:02:35 UTC
+++ ui/base/ui_base.gyp
@@ -454,7 +454,7 @@
             'x/selection_utils.h',
           ]
         }],
-        ['use_aura==0 or OS!="linux"', {
+        ['use_aura==0 or (OS!="linux" and os_bsd!=1)', {
           'sources!': [
             'resource/resource_bundle_auralinux.cc',
           ],
@@ -477,7 +477,7 @@
             '../../build/linux/system.gyp:glib',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'conditions': [
             ['toolkit_views==0 and use_aura==0', {
               # Note: because of gyp predence rules this has to be defined as
@@ -510,7 +510,7 @@
             'clipboard/clipboard_aurax11.cc',
           ],
         }],
-        ['chromeos==1 or (use_aura==1 and OS=="linux" and use_x11==0)', {
+        ['chromeos==1 or (use_aura==1 and (OS=="linux" or os_bsd==1) and use_x11==0)', {
           'sources!': [
             'dragdrop/os_exchange_data_provider_aurax11.cc',
           ],
