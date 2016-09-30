--- common.gypi.orig	2016-09-28 10:10:46 UTC
+++ common.gypi
@@ -180,7 +180,6 @@
       [ 'OS=="linux" or OS=="freebsd" or OS=="openbsd" or OS=="solaris"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', '-pthread', ],
         'cflags_cc': [
-          '-fno-delete-null-pointer-checks',
           '-fno-exceptions',
           '-fno-rtti',
         ],
