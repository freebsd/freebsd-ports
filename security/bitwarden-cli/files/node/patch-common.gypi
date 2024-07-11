--- common.gypi.orig	2024-02-13 21:43:28 UTC
+++ common.gypi
@@ -466,7 +466,7 @@
                 'ldflags': [ '-m32' ],
               }],
               [ 'host_arch=="ppc64" and OS not in "aix os400"', {
-                'cflags': [ '-m64', '-mminimal-toc' ],
+                'cflags': [ '-m64' ],
                 'ldflags': [ '-m64' ],
               }],
               [ 'host_arch=="s390x" and OS=="linux"', {
@@ -490,7 +490,7 @@
                 'ldflags': [ '-m32' ],
               }],
               [ 'target_arch=="ppc64" and OS not in "aix os400"', {
-                'cflags': [ '-m64', '-mminimal-toc' ],
+                'cflags': [ '-m64' ],
                 'ldflags': [ '-m64' ],
               }],
               [ 'target_arch=="s390x" and OS=="linux"', {
