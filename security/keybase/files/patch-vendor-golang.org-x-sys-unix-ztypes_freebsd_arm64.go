Obtained from:	https://github.com/golang/sys/commit/33540a1f603772f9d4b761f416f5c10dade23e96

--- vendor/golang.org/x/sys/unix/ztypes_freebsd_arm64.go.orig	2020-03-10 17:25:08 UTC
+++ vendor/golang.org/x/sys/unix/ztypes_freebsd_arm64.go
@@ -397,7 +397,7 @@ type Reg struct {
 }
 
 type FpReg struct {
-	Fp_q  [32]uint128
+	Fp_q  [512]uint8
 	Fp_sr uint32
 	Fp_cr uint32
 }
