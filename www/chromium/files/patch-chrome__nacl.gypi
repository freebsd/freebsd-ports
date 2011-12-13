--- chrome/nacl.gypi.orig	2011-11-01 10:43:23.000000000 +0200
+++ chrome/nacl.gypi	2011-11-19 19:26:48.000000000 +0200
@@ -102,8 +102,8 @@
                   ],
                 },
               ],
-            }],
-            ['OS!="win" and target_arch=="ia32"', {
+            }], # Disable nacl on freebsd for now.
+            ['OS!="win" and OS!="freebsd" and target_arch=="ia32"', {
               # Linux-x86-32 and OSX need only the x86-32 IRT.
               'actions': [
                 {
@@ -119,7 +119,7 @@
                 },
               ],
             }],
-            ['OS!="win" and target_arch=="x64"', {
+            ['OS!="win" and OS!="freebsd" and target_arch=="x64"', {
               # Linux-x86-64 needs only the x86-64 IRT.
               'actions': [
                 {
