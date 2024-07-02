--- build.psm1.orig	2023-11-15 23:14:17.000000000 +0100
+++ build.psm1	2024-06-26 20:41:37.701712000 +0200
@@ -317,6 +317,7 @@
                      "linux-arm",
                      "linux-arm64",
                      "linux-x64",
+                     "freebsd-x64",
                      "osx-arm64",
                      "osx-x64",
                      "win-arm",
@@ -908,6 +909,7 @@
                      "linux-arm",
                      "linux-arm64",
                      "linux-x64",
+                     "freebsd-x64",
                      "osx-arm64",
                      "osx-x64",
                      "win-arm",
@@ -955,6 +957,10 @@
 
             'Linux' {
                 $Runtime = "linux-${Architecture}"
+            }
+
+            'FreeBSD' {
+                $Runtime = "freebsd-${Architecture}"
             }
 
             'Darwin' {
