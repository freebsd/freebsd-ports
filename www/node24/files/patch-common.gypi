--- common.gypi.orig	2025-05-06 12:36:27 UTC
+++ common.gypi
@@ -529,7 +529,7 @@
                 'ldflags': [ '-m64' ],
               }],
               [ 'host_arch=="ppc64" and OS not in "aix os400"', {
-                'cflags': [ '-m64', '-mminimal-toc' ],
+                'cflags': [ '-m64' ],
                 'ldflags': [ '-m64' ],
               }],
               [ 'host_arch=="s390x" and OS=="linux"', {
@@ -549,7 +549,7 @@
                 'ldflags': [ '-m64' ],
               }],
               [ 'target_arch=="ppc64" and OS not in "aix os400"', {
-                'cflags': [ '-m64', '-mminimal-toc' ],
+                'cflags': [ '-m64' ],
                 'ldflags': [ '-m64' ],
               }],
               [ 'target_arch=="s390x" and OS=="linux"', {
