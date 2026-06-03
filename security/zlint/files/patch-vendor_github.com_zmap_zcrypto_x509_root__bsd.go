-- Add missing root_bsd.go to zcrypto to fix build on FreeBSD
-- The vendored zcrypto was missing FreeBSD-specific certificate paths
-- leading to "undefined: certFiles" and "undefined: certDirectories" errors.

--- vendor/github.com/zmap/zcrypto/x509/root_bsd.go.orig	2026-05-11 05:45:46 UTC
+++ vendor/github.com/zmap/zcrypto/x509/root_bsd.go
@@ -0,0 +1,23 @@
+// Copyright 2015 The Go Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style
+// license that can be found in the LICENSE file.
+
+//go:build dragonfly || freebsd || netbsd || openbsd
+// +build dragonfly freebsd netbsd openbsd
+
+package x509
+
+// Possible certificate files; stop after finding one.
+var certFiles = []string{
+	"/usr/local/etc/ssl/cert.pem",            // FreeBSD
+	"/etc/ssl/cert.pem",                      // OpenBSD
+	"/usr/local/share/certs/ca-root-nss.crt", // DragonFly
+	"/etc/openssl/certs/ca-certificates.crt", // NetBSD
+}
+
+// Possible directories with certificate files; stop after successfully
+// reading at least one file from a directory.
+var certDirectories = []string{
+	"/etc/ssl/certs",         // FreeBSD
+	"/usr/local/share/certs", // FreeBSD
+}
