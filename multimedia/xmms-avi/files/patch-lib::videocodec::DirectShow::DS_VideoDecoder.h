--- lib/videocodec/DirectShow/DS_VideoDecoder.h.orig	Thu Dec 21 09:34:19 2000
+++ lib/videocodec/DirectShow/DS_VideoDecoder.h	Sun Dec  7 02:30:26 2003
@@ -18,7 +18,7 @@
 	}
 	catch(FatalError& error)
 	{
-	    cerr<<"~DS_VideoDecoder(): ";
+	    std::cerr<<"~DS_VideoDecoder(): ";
 	    error.Print();
 	} 
 	if(m_outFrame)delete m_outFrame;   
