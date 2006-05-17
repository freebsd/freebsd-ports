--- ./client/core/asm/hxsmstr.cpp.orig	Fri Jul  9 04:05:30 2004
+++ ./client/core/asm/hxsmstr.cpp	Sat May  6 21:32:22 2006
@@ -278,10 +278,12 @@
 	IHXValues* pHeader = 0;
 
 	HX_VERIFY(pHeader = pStream->GetHeader());
+	/*
 	HX_VERIFY(HXR_OK == pHeader->GetPropertyULONG32("AvgBitRate",
 	    m_ulFixedBandwidth));
-	
-	m_ulCurrentBandwidth = m_ulFixedBandwidth; 
+	*/
+	pHeader->GetPropertyULONG32("AvgBitRate", m_ulFixedBandwidth);
+	m_ulCurrentBandwidth = m_ulFixedBandwidth;
 
 	pHeader->Release();
     }
