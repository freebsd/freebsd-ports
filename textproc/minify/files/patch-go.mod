--- go.mod.orig	1979-11-29 16:00:00 UTC
+++ go.mod
@@ -1,9 +1,8 @@
 module github.com/tdewolff/minify/v2
 
-go 1.13
+go 1.17
 
 require (
-	github.com/cheekybits/is v0.0.0-20150225183255-68e9c0620927 // indirect
 	github.com/djherbis/atime v1.1.0
 	github.com/dustin/go-humanize v1.0.1
 	github.com/fsnotify/fsnotify v1.6.0
@@ -11,5 +10,9 @@ require (
 	github.com/spf13/pflag v1.0.5
 	github.com/tdewolff/parse/v2 v2.6.6
 	github.com/tdewolff/test v1.0.9
+)
+
+require (
+	github.com/cheekybits/is v0.0.0-20150225183255-68e9c0620927 // indirect
 	golang.org/x/sys v0.6.0 // indirect
 )
