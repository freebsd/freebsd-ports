--- gpu/demos/demos.gyp.orig	2011-06-24 11:30:31.000000000 +0300
+++ gpu/demos/demos.gyp	2011-06-26 22:43:26.842781274 +0300
@@ -14,7 +14,7 @@
       # also be compiled with -fPIC flag. Setting GYP_DEFINES="linux_fpic=1"
       # compiles everything with -fPIC. Disable pepper demos on linux/x64
       # unless linux_fpic is 1.
-      ['OS=="linux" and (target_arch=="x64" or target_arch=="arm") and linux_fpic!=1', {
+      ['(OS=="linux" or OS=="freebsd") and (target_arch=="x64" or target_arch=="arm") and linux_fpic!=1', {
         'enable_pepper_demos%': 0,
       }, {
         'enable_pepper_demos%': 1,
@@ -107,7 +107,7 @@
           ],
         },
         'conditions': [
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="freebsd"', {
             # -gstabs, used in the official builds, causes an ICE. Remove it.
             'cflags!': ['-gstabs'],
           }],
