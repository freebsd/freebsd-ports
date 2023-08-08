--- common.gypi.orig	2023-04-12 04:09:10 UTC
+++ common.gypi
@@ -426,7 +426,7 @@
             'ldflags': [ '-m32' ],
           }],
           [ 'target_arch=="ppc64" and OS not in "aix os400"', {
-            'cflags': [ '-m64', '-mminimal-toc' ],
+            'cflags': [ '-m64' ],
             'ldflags': [ '-m64' ],
           }],
           [ 'target_arch=="s390x" and OS=="linux"', {
