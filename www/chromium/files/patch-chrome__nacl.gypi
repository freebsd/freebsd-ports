--- chrome/nacl.gypi.orig	2011-10-10 21:43:36.427755838 +0300
+++ chrome/nacl.gypi	2011-10-10 21:47:51.837729515 +0300
@@ -103,8 +103,8 @@
               ],
             },
           ],
-        }],
-        ['OS!="win" and target_arch=="ia32"', {
+        }], # Disable nacl on freebsd for now.
+        ['OS!="win" and OS!="freebsd" and target_arch=="ia32"', {
           # Linux-x86-32 and OSX need only the x86-32 IRT.
           'actions': [
             {
@@ -120,7 +120,7 @@
             },
           ],
         }],
-        ['OS!="win" and target_arch=="x64"', {
+        ['OS!="win" and OS!="freebsd" and target_arch=="x64"', {
           # Linux-x86-64 needs only the x86-64 IRT.
           'actions': [
             {
