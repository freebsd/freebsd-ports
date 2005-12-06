--- libavcodec/utils.c.orig	Tue Dec  6 17:51:14 2005
+++ libavcodec/utils.c	Tue Dec  6 17:53:17 2005
@@ -249,6 +249,16 @@
             const int h_shift= i==0 ? 0 : h_chroma_shift;
             const int v_shift= i==0 ? 0 : v_chroma_shift;
 
+	    if(s->pix_fmt == PIX_FMT_PAL8 && i == 1)
+		{
+		buf->base[i] = av_malloc(256 * 4);
+		if(buf->base[i] == NULL)
+		    return -1;
+		buf->data[i] = buf->base[i];
+		continue;
+		}
+
+
             //FIXME next ensures that linesize= 2^x uvlinesize, thats needed because some MC code assumes it
             buf->linesize[i]= ALIGN(pixel_size*w>>h_shift, s_align<<(h_chroma_shift-h_shift)); 
 
