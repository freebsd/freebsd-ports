--- lib/avifile/AviRead.cpp.orig	Sat Jan 20 14:17:27 2001
+++ lib/avifile/AviRead.cpp	Sun Dec  7 02:30:26 2003
@@ -104,12 +104,12 @@
     return pos;
 }
 
-Unsigned AviReadStream::GetNextKeyFrame(int frame=-1) const
+Unsigned AviReadStream::GetNextKeyFrame(int frame) const
 {
     if(m_pIStream==0)return 0;
     return m_pIStream->NextKeyFrame((frame<0)?(int)m_sample:frame);
 }    
-Unsigned AviReadStream::GetPrevKeyFrame(int frame=-1) const
+Unsigned AviReadStream::GetPrevKeyFrame(int frame) const
 {
     if(m_pIStream==0)return 0;
     if(frame==0)return 0;
