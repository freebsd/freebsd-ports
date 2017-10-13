--- build/common.gypi.orig	2017-10-06 23:46:24 UTC
+++ build/common.gypi
@@ -44,7 +44,7 @@
     # way for our users to change the compiler (since gclient gets in
     # the way of tweaking gyp flags directly).
     'clang_version':
-      '<!(python <(DEPTH)/build/clang_version.py)',
+      '<!(python2.7 <(DEPTH)/build/clang_version.py)',
 
     'conditions': [
       # TODO(morlovich): AIX, Solaris, FreeBSD10?
@@ -131,6 +131,15 @@
         # libraries.
         'ldflags!': [
           '-Wl,-z,defs',
+          '-zdefs',
+        ],
+        'cflags!': [
+          '-Wl,-z,defs',
+          '-zdefs',
+        ],
+        'cflags_cc!': [
+          '-Wl,-z,defs',
+          '-zdefs',
         ],
       }],
       ['OS == "mac"', {
