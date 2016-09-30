--- common.gypi.orig	2016-09-28 09:34:52 UTC
+++ common.gypi
@@ -182,7 +182,6 @@
       [ 'OS in "linux freebsd openbsd solaris android"', {
         'cflags': [ '-Wall', '-Wextra', '-Wno-unused-parameter', ],
         'cflags_cc': [
-          '-fno-delete-null-pointer-checks',
           '-fno-exceptions',
           '-fno-rtti',
         ],
