--- third_party/icu/icu.gyp.orig	2011-01-06 11:00:47.000000000 +0100
+++ third_party/icu/icu.gyp	2011-01-09 19:47:16.000000000 +0100
@@ -54,7 +54,7 @@
             }, {  # else: OS != "win"
               'sources!': ['icudt42.dll'],
             }],
-            [ 'OS != "linux" or chromeos == 1', {
+            [ '(OS != "linux" and OS != "freebsd") or chromeos == 1', {
               'sources!': ['linux/icudt42l_dat.S'],
             }],
             [ 'OS != "mac"', {
@@ -232,7 +232,7 @@
             ],
           },
           'conditions': [
-            [ 'OS=="linux"', {
+            [ 'OS=="linux" or OS=="freebsd"', {
               # Since ICU wants to internally use its own deprecated APIs, don't
               # complain about it.
               'cflags': [
