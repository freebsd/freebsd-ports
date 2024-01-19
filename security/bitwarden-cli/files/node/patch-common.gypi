--- common.gypi.orig	2023-03-05 06:42:51 UTC
+++ common.gypi
@@ -426,7 +426,7 @@
             'ldflags': [ '-m32' ],
           }],
           [ 'target_arch=="ppc64" and OS!="aix"', {
-            'cflags': [ '-m64', '-mminimal-toc' ],
+            'cflags': [ '-m64' ],
             'ldflags': [ '-m64' ],
           }],
           [ 'target_arch=="s390x" and OS=="linux"', {
