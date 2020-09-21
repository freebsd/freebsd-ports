--- size/size.go.orig	2020-09-21 17:38:18 UTC
+++ size/size.go
@@ -7,7 +7,7 @@ import (
 )
 
 // Size represents size that implements flag.Var
-type Size int
+type Size int64
 
 // the following regexes follow Go semantics https://golang.org/ref/spec#Letters_and_digits
 var (
