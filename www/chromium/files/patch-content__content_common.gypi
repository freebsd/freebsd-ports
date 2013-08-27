--- content/content_common.gypi.orig	2013-08-09 22:07:06.000000000 +0300
+++ content/content_common.gypi	2013-08-17 20:29:03.000000000 +0300
@@ -391,6 +391,15 @@
         'content.gyp:common_aidl',
       ],
     }],
+    ['os_bsd==1', {
+      'sources!': [
+        'common/sandbox_linux.cc',
+        'common/sandbox_linux.h',
+        'common/sandbox_init_linux.cc',
+        'common/sandbox_seccomp_bpf_linux.cc',
+        'common/sandbox_seccomp_bpf_linux.h',
+      ],
+    }],
     ['toolkit_uses_gtk == 1', {
       'dependencies': [
         '../build/linux/system.gyp:gtk',
