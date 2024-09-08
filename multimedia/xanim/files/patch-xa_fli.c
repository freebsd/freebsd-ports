--- xa_fli.c.orig	1999-03-21 22:36:25 UTC
+++ xa_fli.c
@@ -126,7 +126,7 @@ Fli_Frame_Header *frame_hdr;
   DEBUG_LEVEL1 fprintf(stderr,"  magic = %02x%02x\n",(int)tmp[5],(int)tmp[4]);
   while( !( (tmp[5]==0xf1) && ((tmp[4]==0xfa) || (tmp[4] == 0x00)) ) )
   {
-    for(i=0;i<6;i++) tmp[i] = tmp[i+1];
+    for(i=0;i<4;i++) tmp[i] = tmp[i+1];
     tmp[5] = (xaUBYTE)xin->Read_U8(xin);
     if (xin->At_EOF(xin,10)) return(0);
   }
