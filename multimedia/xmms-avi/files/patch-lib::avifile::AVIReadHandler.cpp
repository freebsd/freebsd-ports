--- lib/avifile/AVIReadHandler.cpp.orig	Mon Nov 27 14:08:44 2000
+++ lib/avifile/AVIReadHandler.cpp	Sun Dec  7 13:27:54 2003
@@ -255,7 +255,7 @@
 
 
 class AVIReadStream : public IvAVIReadStream, public ListNode2<AVIReadStream> {
-	friend AVIReadHandler;
+	friend class AVIReadHandler;
 
 public:
 	AVIReadStream(AVIReadHandler *, AVIStreamNode *, int);
@@ -987,7 +987,7 @@
 		int hdrSize;
 		switch(fccType) {
 		case ckidAVIMAINHDR:
-			hdrSize=min(dwLength, sizeof(m_header));
+			hdrSize= (dwLength, sizeof(m_header)) ? dwLength: sizeof(m_header);
 			_readFile2(&m_header, hdrSize);
 //			printf("Found main header, size %d\n", hdrSize);
 			dwLength-=hdrSize;
@@ -1109,7 +1109,7 @@
 			__int64 cpos=_posFile();
 			while(cpos/(i64FileSize/10)>progress)
 			{
-			    cerr<<".";
+			    std::cerr<<".";
 			    progress++;
 			}    
 			
@@ -1154,7 +1154,7 @@
 //			pd.advance((long)((_posFile() - i64ChunkMoviPos)/1024));
 //			pd.check();
 		}
-		cerr<<endl;
+		std::cerr<<std::endl;
 
 	}
 
