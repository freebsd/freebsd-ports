--- common.gypi.orig	2024-10-03 09:20:49 UTC
+++ common.gypi
@@ -489,7 +489,7 @@
                 'ldflags': [ '-m32' ],
               }],
               [ 'host_arch=="ppc64" and OS not in "aix os400"', {
-                'cflags': [ '-m64', '-mminimal-toc' ],
+                'cflags': [ '-m64' ],
                 'ldflags': [ '-m64' ],
               }],
               [ 'host_arch=="s390x" and OS=="linux"', {
@@ -513,7 +513,7 @@
                 'ldflags': [ '-m32' ],
               }],
               [ 'target_arch=="ppc64" and OS not in "aix os400"', {
-                'cflags': [ '-m64', '-mminimal-toc' ],
+                'cflags': [ '-m64' ],
                 'ldflags': [ '-m64' ],
               }],
               [ 'target_arch=="s390x" and OS=="linux"', {
