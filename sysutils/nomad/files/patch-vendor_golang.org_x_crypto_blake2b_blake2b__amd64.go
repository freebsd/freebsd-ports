--- vendor/golang.org/x/crypto/blake2b/blake2b_amd64.go.orig	2018-10-12 12:39:07 UTC
+++ vendor/golang.org/x/crypto/blake2b/blake2b_amd64.go
@@ -6,12 +6,11 @@
 
 package blake2b
 
+import "golang.org/x/sys/cpu"
+
 func init() {
-	useSSE4 = supportsSSE4()
+	useSSE4 = cpu.X86.HasSSE41
 }
-
-//go:noescape
-func supportsSSE4() bool
 
 //go:noescape
 func hashBlocksSSE4(h *[8]uint64, c *[2]uint64, flag uint64, blocks []byte)
