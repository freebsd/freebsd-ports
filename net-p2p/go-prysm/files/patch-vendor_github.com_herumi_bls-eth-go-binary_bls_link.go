--- vendor/github.com/herumi/bls-eth-go-binary/bls/link.go.orig	2022-09-24 03:41:18 UTC
+++ vendor/github.com/herumi/bls-eth-go-binary/bls/link.go
@@ -15,6 +15,7 @@ package bls
 #cgo darwin,arm64 LDFLAGS:-L${SRCDIR}/lib/darwin/arm64
 #cgo windows,amd64 LDFLAGS:-L${SRCDIR}/lib/windows/amd64
 #cgo openbsd,amd64 LDFLAGS:-L${SRCDIR}/lib/openbsd/amd64
+#cgo freebsd,arm64 LDFLAGS:-L${SRCDIR}/lib/freebsd/arm64
 #cgo freebsd,amd64 LDFLAGS:-L${SRCDIR}/lib/freebsd/amd64
 */
 import "C"
