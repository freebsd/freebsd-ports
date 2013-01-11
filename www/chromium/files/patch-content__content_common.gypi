--- content/content_common.gypi.orig	2012-11-27 10:01:27.000000000 +0200
+++ content/content_common.gypi	2012-12-10 22:16:37.000000000 +0200
@@ -436,6 +436,14 @@
         'content.gyp:common_aidl',
       ],
     }],
+    ['os_bsd==1', {
+      'sources!': [
+        'common/sandbox_linux.cc',
+        'common/sandbox_linux.h',
+        'common/sandbox_seccomp_bpf_linux.cc',
+        'common/sandbox_seccomp_bpf_linux.h',
+      ],
+    }],
     ['toolkit_uses_gtk == 1', {
       'dependencies': [
         '../build/linux/system.gyp:gtk',
