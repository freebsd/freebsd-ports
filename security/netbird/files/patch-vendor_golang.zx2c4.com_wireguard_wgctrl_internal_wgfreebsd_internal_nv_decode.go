--- vendor/golang.zx2c4.com/wireguard/wgctrl/internal/wgfreebsd/internal/nv/decode.go.orig	2025-09-06 11:14:13 UTC
+++ vendor/golang.zx2c4.com/wireguard/wgctrl/internal/wgfreebsd/internal/nv/decode.go
@@ -13,7 +13,7 @@ func Unmarshal(d []byte, out List) error {
 
 // Unmarshal decodes a FreeBSD name-value list (nv(9)) to a Go map
 func Unmarshal(d []byte, out List) error {
-	sz := C.ulong(len(d))
+	sz := C.size_t(len(d))
 	dp := unsafe.Pointer(&d[0])
 	nvl := C.nvlist_unpack(dp, sz, 0)
 
