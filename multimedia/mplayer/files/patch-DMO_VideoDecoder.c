--- loader/dmo/DMO_VideoDecoder.c	2007/01/26 09:21:22	22019
+++ loader/dmo/DMO_VideoDecoder.c	2007/02/11 17:55:49	22204
@@ -119,6 +119,7 @@
      
         this->iv.m_bh = malloc(bihs);
         memcpy(this->iv.m_bh, format, bihs);
+        this->iv.m_bh->biSize = bihs;
 
         this->iv.m_State = STOP;
         //this->iv.m_pFrame = 0;
