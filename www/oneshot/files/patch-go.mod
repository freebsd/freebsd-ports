--- go.mod.orig	2023-03-21 14:55:12 UTC
+++ go.mod
@@ -1,6 +1,6 @@
 module github.com/raphaelreyna/oneshot
 
-go 1.16
+go 1.17
 
 require (
 	github.com/google/uuid v1.2.0
@@ -10,4 +10,17 @@ require (
 	github.com/raphaelreyna/ez-cgi v0.7.3
 	github.com/spf13/cobra v1.0.0
 	github.com/spf13/pflag v1.0.3
+)
+
+require (
+	github.com/cenkalti/backoff v2.2.1+incompatible // indirect
+	github.com/cpuguy83/go-md2man/v2 v2.0.0 // indirect
+	github.com/inconshreveable/mousetrap v1.0.0 // indirect
+	github.com/miekg/dns v1.1.27 // indirect
+	github.com/russross/blackfriday/v2 v2.0.1 // indirect
+	github.com/shurcooL/sanitized_anchor_name v1.0.0 // indirect
+	golang.org/x/crypto v0.0.0-20191011191535-87dc89f01550 // indirect
+	golang.org/x/net v0.8.0 // indirect
+	golang.org/x/sys v0.6.0 // indirect
+	gopkg.in/yaml.v2 v2.2.2 // indirect
 )
