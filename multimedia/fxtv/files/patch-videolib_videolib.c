--- videolib/videolib.c.orig	1999-11-03 02:22:04 UTC
+++ videolib/videolib.c
@@ -479,9 +479,8 @@ static void VIDEOLIBConvertRGBToRGB( VL_
             *(p++) = (*src16 >> 8) | (*src16 << 8);
             src16++;
           }
-          for ( i = dst_line_pad; i > 0; i-- )
-            *(((VL_UINT8 *)p)++) = 0x00;
-          (VL_UINT8 *)dst_line += dst->geom.bytes_per_line;
+          memset(p, 0, dst_line_pad);
+          dst_line += dst->geom.bytes_per_line / sizeof(VL_UINT16);
         }
 
         src16 = dst_line = (VL_UINT16 *) dst->buf;
@@ -513,9 +512,9 @@ static void VIDEOLIBConvertRGBToRGB( VL_
         if ( src_padded ) 
           src16 = (VL_UINT16 *)( (VL_UINT8 *)src16 + dst_line_pad );
         else
-          for ( i = dst_line_pad; i > 0; i-- )
-            *(((VL_UINT8 *)dst)++) = 0x00;
-        (VL_UINT8 *)dst_line += dst->geom.bytes_per_line;
+          memset(dst, 0, dst_line_pad);
+          dst += dst_line_pad / sizeof(VL_IMAGE);
+          dst_line += dst->geom.bytes_per_line / sizeof(VL_UINT16);
       }
 
       if ( !dst_swap_b ) {                       /*  More ugliness  */
@@ -527,8 +526,8 @@ static void VIDEOLIBConvertRGBToRGB( VL_
             *(p++) = (*src16 >> 8) | (*src16 << 8);
             src16++;
           }
-          (VL_UINT8 *)dst_line += dst->geom.bytes_per_line;
-          (VL_UINT8 *)src16    += dst->geom.bytes_per_line;
+          dst_line += dst->geom.bytes_per_line / sizeof(VL_UINT16);
+          src16    += dst->geom.bytes_per_line / sizeof(VL_UINT16);
         }
       }
     }
