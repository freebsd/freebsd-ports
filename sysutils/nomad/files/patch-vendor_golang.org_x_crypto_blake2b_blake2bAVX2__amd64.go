--- vendor/golang.org/x/crypto/blake2b/blake2bAVX2_amd64.go.orig	2018-10-12 12:40:06 UTC
+++ vendor/golang.org/x/crypto/blake2b/blake2bAVX2_amd64.go
@@ -6,20 +6,13 @@
 
 package blake2b
 
+import "golang.org/x/sys/cpu"
+
 func init() {
-	useAVX2 = supportsAVX2()
-	useAVX = supportsAVX()
-	useSSE4 = supportsSSE4()
+	useAVX2 = cpu.X86.HasAVX2
+	useAVX = cpu.X86.HasAVX
+	useSSE4 = cpu.X86.HasSSE41
 }
-
-//go:noescape
-func supportsSSE4() bool
-
-//go:noescape
-func supportsAVX() bool
-
-//go:noescape
-func supportsAVX2() bool
 
 //go:noescape
 func hashBlocksAVX2(h *[8]uint64, c *[2]uint64, flag uint64, blocks []byte)
