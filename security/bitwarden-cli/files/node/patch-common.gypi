--- common.gypi.orig	2024-10-16 14:36:50 UTC
+++ common.gypi
@@ -521,7 +521,7 @@
                 'ldflags': [ '-m32' ],
               }],
               [ 'host_arch=="ppc64" and OS not in "aix os400"', {
-                'cflags': [ '-m64', '-mminimal-toc' ],
+                'cflags': [ '-m64' ],
                 'ldflags': [ '-m64' ],
               }],
               [ 'host_arch=="s390x" and OS=="linux"', {
@@ -545,7 +545,7 @@
                 'ldflags': [ '-m32' ],
               }],
               [ 'target_arch=="ppc64" and OS not in "aix os400"', {
-                'cflags': [ '-m64', '-mminimal-toc' ],
+                'cflags': [ '-m64' ],
                 'ldflags': [ '-m64' ],
               }],
               [ 'target_arch=="s390x" and OS=="linux"', {
