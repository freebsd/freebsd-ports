--- h5/glide3/src/glfb.c.orig	Thu Jan 16 01:23:50 2003
+++ h5/glide3/src/glfb.c	Sun Jul  1 03:06:16 2007
@@ -1014,17 +1014,28 @@
                  FXFALSE,
                  &info))
    {
-      FxU32 *src,*dst;
+      union {
+         FxU32 *src;
+         FxU16 *src16;
+         FxU8 *src8;
+      } s;
+
+      union {
+         FxU32 *dst;
+         FxU16 *dst16;
+         FxU8 *dst8;
+      } d;
+
       FxI32 length,scanline;
       FxU32 src_adjust,dst_adjust,tmp;
 
-      src=(FxU32 *) (((char*)info.lfbPtr)+
+      s.src=(FxU32 *) (((char*)info.lfbPtr)+
                      (src_y*info.strideInBytes) + (src_x * bpp));
-      dst=dst_data;
+      d.dst=dst_data;
       scanline=src_height;
 
       /* set length - alignment fix*/
-      tmp=(((AnyPtr)src)&2);
+      tmp=(((AnyPtr)s.src)&2);
       length=src_width * bpp - tmp;
       src_adjust=info.strideInBytes - tmp;
       dst_adjust=dst_stride - tmp;
@@ -1035,8 +1046,8 @@
       while(src_height--)
       {
          /* adjust starting alignment */
-         if (((AnyPtr)src)&3)
-            *((FxU16 *)dst)++=*((FxU16 *)src)++;
+         if (((AnyPtr)s.src)&3)
+            *d.dst16++ = *s.src16++;
 
          /* read in dwords of pixels */
          if(length)
@@ -1047,16 +1058,21 @@
             /* copies aligned dwords */
             do
             {
-               *((FxU32 *)(((AnyPtr)dst) + byte_index))=*((FxU32 *)(((AnyPtr)src) + byte_index));
+               FxU32 *dst = (FxU32 *)(((AnyPtr)dst) + byte_index);
+               FxU32 *src = (FxU32 *)(((AnyPtr)src) + byte_index);
+               *dst = *src;
             }while((byte_index+=4)<aligned);
 
             /* handle backend misalignment */
-            if (byte_index!=(FxU32)length)
-               *((FxU16 *)(((AnyPtr)dst) + byte_index))=*((FxU16 *)(((AnyPtr)src) + byte_index));
+            if (byte_index!=(FxU32)length) {
+               FxU16 *dst = (FxU16 *)(((AnyPtr)dst) + byte_index);
+               FxU16 *src = (FxU16 *)(((AnyPtr)src) + byte_index);
+               *dst = *src;
+            }
          }
          /* adjust for next line */
-         ((FxU8 *)src)+=src_adjust;
-         ((FxU8 *)dst)+=dst_adjust;
+         s.src8+=src_adjust;
+         d.dst8+=dst_adjust;
       }
       rv=FXTRUE;
       /* unlock buffer */
