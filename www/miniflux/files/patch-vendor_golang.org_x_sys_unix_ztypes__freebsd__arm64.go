--- vendor/golang.org/x/sys/unix/ztypes_freebsd_arm64.go.orig	2019-12-25 18:35:13 UTC
+++ vendor/golang.org/x/sys/unix/ztypes_freebsd_arm64.go
@@ -397,7 +397,7 @@ type Reg struct {
 }
 
 type FpReg struct {
-	Fp_q  [32]uint128
+	Fp_q  [512]uint8
 	Fp_sr uint32
 	Fp_cr uint32
 }
