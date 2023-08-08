--- src/evg/raster_yuv.c.orig	2022-12-08 16:12:27 UTC
+++ src/evg/raster_yuv.c
@@ -1291,7 +1291,7 @@ GF_Err evg_surface_clear_yuyv(GF_EVGSurface *_surf, GF
 #define set_u16_le(_ptr, val) { ((u8 *)_ptr)[0] = (val>>8)&0xFF;  ((u8 *)_ptr)[1] = (val&0xFF); }
 #define set_u16_be(_ptr, val) { *(u16 *) _ptr = (u16) val; }
 
-#define get_u16_le(val, _ptr) { val = ((u32) (*(u8 *) ptr+1)<< 8) | *(u8 *) ptr; }
+#define get_u16_le(val, _ptr) { val = ((u32) (*(u8 *) _ptr+1)<< 8) | *(u8 *) _ptr; }
 #define get_u16_be(val, _ptr) { val = *(u16 *) (_ptr); }
 
 #else
