--- vendor/github.com/herumi/bls-eth-go-binary/bls/bls.go.orig	2021-03-17 23:11:47 UTC
+++ vendor/github.com/herumi/bls-eth-go-binary/bls/bls.go
@@ -15,7 +15,7 @@ package bls
 #cgo darwin,arm64 LDFLAGS:-L${SRCDIR}/lib/darwin/arm64
 #cgo windows,amd64 LDFLAGS:-L${SRCDIR}/lib/windows/amd64
 #cgo openbsd,amd64 LDFLAGS:-L${SRCDIR}/lib/openbsd/amd64
-#cgo freebsd,amd64 LDFLAGS:-L${SRCDIR}/lib/linux/amd64
+#cgo freebsd,amd64 LDFLAGS:-L${SRCDIR}/lib/freebsd/amd64
 typedef unsigned int (*ReadRandFunc)(void *, void *, unsigned int);
 int wrapReadRandCgo(void *self, void *buf, unsigned int n);
 #include <mcl/bn_c384_256.h>
