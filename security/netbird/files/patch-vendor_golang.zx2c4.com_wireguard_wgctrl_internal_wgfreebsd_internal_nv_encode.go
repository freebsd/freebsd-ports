--- vendor/golang.zx2c4.com/wireguard/wgctrl/internal/wgfreebsd/internal/nv/encode.go.orig	2025-09-06 11:15:21 UTC
+++ vendor/golang.zx2c4.com/wireguard/wgctrl/internal/wgfreebsd/internal/nv/encode.go
@@ -44,7 +44,7 @@ func marshal(m List) (nvl *C.struct_nvlist, err error)
 			C.nvlist_add_bool(nvl, ckey, C.bool(value))
 
 		case uint64:
-			C.nvlist_add_number(nvl, ckey, C.ulong(value))
+			C.nvlist_add_number(nvl, ckey, C.uint64_t(value))
 
 		case []byte:
 			sz := len(value)
@@ -54,8 +54,8 @@ func marshal(m List) (nvl *C.struct_nvlist, err error)
 
 		case []List:
 			sz := len(value)
-			buf := C.malloc(C.size_t(C.sizeof_nvlist_ptr * sz))
-			items := (*[1<<30 - 1]*C.struct_nvlist)(buf)
+			buf := (**C.struct_nvlist)(C.malloc(C.size_t(C.sizeof_nvlist_ptr * sz)))
+			items := unsafe.Slice(buf, sz)
 
 			for i, val := range value {
 				if items[i], err = marshal(val); err != nil {
@@ -64,8 +64,8 @@ func marshal(m List) (nvl *C.struct_nvlist, err error)
 				}
 			}
 
-			C.nvlist_add_nvlist_array(nvl, ckey, (**C.struct_nvlist)(buf), C.size_t(sz))
-			C.free(buf)
+			C.nvlist_add_nvlist_array(nvl, ckey, buf, C.size_t(sz))
+			C.free(unsafe.Pointer(buf))
 		}
 
 		C.free(unsafe.Pointer(ckey))
