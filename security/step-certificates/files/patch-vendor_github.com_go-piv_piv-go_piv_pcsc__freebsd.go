--- vendor/github.com/go-piv/piv-go/piv/pcsc_freebsd.go.orig	2020-05-23 07:13:27 UTC
+++ vendor/github.com/go-piv/piv-go/piv/pcsc_freebsd.go
@@ -26,5 +26,5 @@ func scCheck(rc C.long) error {
 }
 
 func isRCNoReaders(rc C.long) bool {
-	return rc == 0x8010002E
+	return int64(rc) == 0x8010002E
 }
