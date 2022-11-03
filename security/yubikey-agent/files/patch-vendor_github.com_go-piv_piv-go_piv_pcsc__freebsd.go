armv7 build fix from github.com/gp-piv/piv-go upstream commit:
https://github.com/go-piv/piv-go/commit/1902689552e974ba88750e3ab71902d253172ead

--- vendor/github.com/go-piv/piv-go/piv/pcsc_freebsd.go.orig	2020-12-08 15:51:45 UTC
+++ vendor/github.com/go-piv/piv-go/piv/pcsc_freebsd.go
@@ -26,5 +26,5 @@ func scCheck(rc C.long) error {
 }
 
 func isRCNoReaders(rc C.long) bool {
-	return rc == 0x8010002E
+	return uint32(rc) == 0x8010002E
 }
