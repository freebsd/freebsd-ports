From 33540a1f603772f9d4b761f416f5c10dade23e96 Mon Sep 17 00:00:00 2001
From: Tobias Klauser <tklauser@distanz.ch>
Date: Fri, 25 Oct 2019 21:13:51 +0200
Subject: [PATCH] unix: don't use non-existing uint128 type on freebsd/arm64

CL 179099 introduced type FpReg on freebsd, on freebsd/arm64 using a
type uint128. This type doesn't exist in Go.

Change-Id: Ie7f065f38f2cc2c163abdfa7dddad886b8edbe3b
Reviewed-on: https://go-review.googlesource.com/c/sys/+/203419
Run-TryBot: Tobias Klauser <tobias.klauser@gmail.com>
TryBot-Result: Gobot Gobot <gobot@golang.org>
Reviewed-by: Brad Fitzpatrick <bradfitz@golang.org>
--- vendor/src/golang.org/x/sys/unix/ztypes_freebsd_arm64.go	2019-08-18 13:42:05 UTC
+++ vendor/src/golang.org/x/sys/unix/ztypes_freebsd_arm64.go
@@ -397,7 +397,7 @@ type Reg struct {
 }
 
 type FpReg struct {
-	Fp_q  [32]uint128
+	Fp_q  [512]uint8
 	Fp_sr uint32
 	Fp_cr uint32
 }
