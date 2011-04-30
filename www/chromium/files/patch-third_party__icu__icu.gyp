--- third_party/icu/icu.gyp.orig	2011-04-15 11:18:40.000000000 +0300
+++ third_party/icu/icu.gyp	2011-04-19 22:22:13.540040004 +0300
@@ -54,7 +54,7 @@
             }, {  # else: OS != "win"
               'sources!': ['windows/icudt46.dll'],
             }],
-            [ 'OS != "linux" or chromeos == 1', {
+            [ '(OS != "linux" and OS != "freebsd") or chromeos == 1', {
               'sources!': ['linux/icudt46l_dat.S'],
             }],
             [ 'OS != "mac"', {
@@ -264,7 +264,7 @@
             ],
           },
           'conditions': [
-            [ 'OS=="linux"', {
+            [ 'OS=="linux" or OS=="freebsd"', {
               # Since ICU wants to internally use its own deprecated APIs, don't
               # complain about it.
               'cflags': [
@@ -479,7 +479,7 @@
                 'source/stubdata/stubdata.c',
               ],
             }],
-            [ 'OS == "linux"', {
+            [ 'OS == "linux" or OS == "freebsd"', {
               'cflags': [
                 # Since ICU wants to internally use its own deprecated APIs,
                 # don't complain about it.
