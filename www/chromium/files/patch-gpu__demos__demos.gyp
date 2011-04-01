--- ./gpu/demos/demos.gyp.orig	2010-12-16 02:11:23.000000000 +0100
+++ ./gpu/demos/demos.gyp	2010-12-20 20:15:08.000000000 +0100
@@ -11,7 +11,7 @@
       # also be compiled with -fPIC flag. Setting GYP_DEFINES="linux_fpic=1"
       # compiles everything with -fPIC. Disable pepper demos on linux/x64
       # unless linux_fpic is 1.
-      ['OS=="linux" and (target_arch=="x64" or target_arch=="arm") and linux_fpic!=1', {
+      ['(OS=="linux" or OS=="freebsd") and (target_arch=="x64" or target_arch=="arm") and linux_fpic!=1', {
         'enable_pepper_demos%': 0,
       }, {
         'enable_pepper_demos%': 1,
@@ -53,7 +53,7 @@
         'framework/window.h',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': ['../../build/linux/system.gyp:gtk'],
         }],
       ],
@@ -172,7 +172,7 @@
           ],
         },
         'conditions': [
-          ['OS=="linux"', {
+          ['OS=="linux" or OS=="freebsd"', {
             # -gstabs, used in the official builds, causes an ICE. Remove it.
             'cflags!': ['-gstabs'],
           }],
