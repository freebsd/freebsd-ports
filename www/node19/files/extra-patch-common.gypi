--- common.gypi.orig	2019-10-01 15:32:40.000000000 +0200
+++ common.gypi	2019-10-16 12:47:09.236138000 +0200
@@ -390,8 +390,8 @@
             'ldflags': [ '-m32' ],
           }],
           [ 'target_arch=="ppc64" and OS!="aix"', {
-            'cflags': [ '-m64', '-mminimal-toc' ],
-            'ldflags': [ '-m64' ],
+            'cflags': [ '-m64' ],
+            'ldflags': [ '-m64' ],
           }],
           [ 'target_arch=="s390x"', {
             'cflags': [ '-m64', '-march=z196' ],
