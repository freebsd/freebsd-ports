--- vendor/golang.org/x/sys/unix/ztypes_freebsd_arm64.go.orig	2026-09-17 21:54:16 UTC
+++ vendor/golang.org/x/sys/unix/ztypes_freebsd_arm64.go
@@ -397,7 +397,7 @@ type FpReg struct {
 }
 
 type FpReg struct {
-	Fp_q  [32]uint128
+	Fp_q  [32][16]uint8
 	Fp_sr uint32
 	Fp_cr uint32
 }
