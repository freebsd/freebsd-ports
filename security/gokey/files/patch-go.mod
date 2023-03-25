--- go.mod.orig	2023-03-25 23:03:40 UTC
+++ go.mod
@@ -1,8 +1,10 @@
 module github.com/cloudflare/gokey
 
-go 1.13
+go 1.17
 
 require (
 	golang.org/x/crypto v0.0.0-20220622213112-05595931fe9d
 	golang.org/x/term v0.0.0-20201126162022-7de9c90e9dd1
 )
+
+require golang.org/x/sys v0.6.0 // indirect
