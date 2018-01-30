This patch fixes the build on 32-bit platforms. It was failing with the
following error:
bosh/ip.go:55:16: constant 4278190080 overflows int

--- bosh/ip.go.orig	2018-01-20 21:01:35 UTC
+++ bosh/ip.go
@@ -52,9 +52,9 @@ func (i IP) Subtract(offset int) IP {
 }
 
 func (i IP) String() string {
-	first := i.ip & 0xff000000 >> 24
-	second := i.ip & 0xff0000 >> 16
-	third := i.ip & 0xff00 >> 8
-	fourth := i.ip & 0xff
+	first := uint32(i.ip) & 0xff000000 >> 24
+	second := uint32(i.ip) & 0xff0000 >> 16
+	third := uint32(i.ip) & 0xff00 >> 8
+	fourth := uint32(i.ip) & 0xff
 	return fmt.Sprintf("%v.%v.%v.%v", first, second, third, fourth)
 }
