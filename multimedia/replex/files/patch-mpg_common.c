--- mpg_common.c.orig	2007-06-19 09:30:08 UTC
+++ mpg_common.c
@@ -73,8 +73,10 @@ void show_buf(uint8_t *buf, int length)
                         else if (Data[i+2+offset]==0 && Data[i+3+offset]==1) \
                                 return i+1+offset; \
                 } \
-                else if (x==1 && Data[i-1+offset]==0 && Data[i+offset]==0 && (i+offset)>0) \
-                         return i-1+offset; \
+                else if (x==1 && (i+offset)>0) { \
+                        if (Data[i-1+offset]==0 && Data[i+offset]==0) \
+                                return i-1+offset; \
+                } \
          }
 
 int FindPacketHeader(const uint8_t *Data, int s, int l)
