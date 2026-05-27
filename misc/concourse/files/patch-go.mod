-- Lower the minimum Go version from 1.26.3 to 1.26.2 to match the go126 package
-- available in the FreeBSD ports tree. Patch releases do not introduce new
-- language features, so this change is safe.
--- go.mod.orig	2026-05-27 16:51:12 UTC
+++ go.mod
@@ -1,6 +1,6 @@ module github.com/concourse/concourse
 module github.com/concourse/concourse
 
-go 1.26.3
+go 1.26.2
 
 require (
 	charm.land/bubbles/v2 v2.1.0
