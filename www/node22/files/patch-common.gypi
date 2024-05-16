--- common.gypi.orig	2023-07-20 18:27:37 UTC
+++ common.gypi
@@ -426,7 +426,7 @@
                 'ldflags': [ '-m32' ],
               }],
               [ 'host_arch=="ppc64" and OS not in "aix os400"', {
-                'cflags': [ '-m64', '-mminimal-toc' ],
+                'cflags': [ '-m64' ],
                 'ldflags': [ '-m64' ],
               }],
               [ 'host_arch=="s390x" and OS=="linux"', {
@@ -450,7 +450,7 @@
                 'ldflags': [ '-m32' ],
               }],
               [ 'target_arch=="ppc64" and OS not in "aix os400"', {
-                'cflags': [ '-m64', '-mminimal-toc' ],
+                'cflags': [ '-m64' ],
                 'ldflags': [ '-m64' ],
               }],
               [ 'target_arch=="s390x" and OS=="linux"', {
