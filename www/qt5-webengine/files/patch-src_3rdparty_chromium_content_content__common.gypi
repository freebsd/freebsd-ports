--- src/3rdparty/chromium/content/content_common.gypi.orig	2016-11-07 14:46:18 UTC
+++ src/3rdparty/chromium/content/content_common.gypi
@@ -12,6 +12,7 @@
     '../skia/skia.gyp:skia',
     '../third_party/WebKit/public/blink_headers.gyp:blink_headers',
     '../third_party/icu/icu.gyp:icuuc',
+    '../third_party/mesa/mesa.gyp:mesa_headers',
     '../ui/accessibility/accessibility.gyp:accessibility',
     '../ui/accessibility/accessibility.gyp:ax_gen',
     '../ui/base/ime/ui_base_ime.gyp:ui_base_ime',
@@ -756,6 +757,21 @@
         'content.gyp:common_aidl',
       ],
     }],
+    ['os_bsd==1', {
+      'sources!': [
+        'common/sandbox_linux/bpf_cros_arm_gpu_policy_linux.cc',
+        'common/sandbox_linux/bpf_gpu_policy_linux.cc',
+        'common/sandbox_linux/bpf_ppapi_policy_linux.cc',
+        'common/sandbox_linux/bpf_renderer_policy_linux.cc',
+        'common/sandbox_linux/bpf_utility_policy_linux.cc',
+        'common/sandbox_linux/sandbox_bpf_base_policy_linux.cc',
+        'common/sandbox_linux/sandbox_debug_handling_linux.cc',
+        'common/sandbox_linux/sandbox_init_linux.cc',
+        'common/sandbox_linux/sandbox_linux.cc',
+        'common/sandbox_linux/sandbox_seccomp_bpf_linux.cc',
+        'common/set_process_title_linux.cc',
+      ],
+    }],
     ['use_pango == 1', {
       'dependencies': [
         '../build/linux/system.gyp:pangocairo',
