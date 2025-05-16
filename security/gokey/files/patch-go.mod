--- go.mod.orig	1979-11-29 16:00:00 UTC
+++ go.mod
@@ -1,8 +1,10 @@ module github.com/cloudflare/gokey
 module github.com/cloudflare/gokey
 
-go 1.13
+go 1.17
 
 require (
 	golang.org/x/crypto v0.17.0
 	golang.org/x/term v0.15.0
 )
+
+require golang.org/x/sys v0.15.0 // indirect
