--- src/jpegentropycoded.cc.orig	Thu Sep 26 23:02:46 2002
+++ src/jpegentropycoded.cc	Thu Sep 26 23:05:21 2002
@@ -19,6 +19,8 @@
  */
 
 #include <assert.h>
+#include <string>
+#include <vector>
 
 #include <libintl.h>
 #define _(S) gettext (S)
@@ -74,17 +76,17 @@
 {
 }
 
-vector<vector <unsigned long> > JpegEntropyCoded::getFreqs ()
+std::vector<std::vector <unsigned long> > JpegEntropyCoded::getFreqs ()
 {
-	vector<vector<unsigned long> > freq ;
+	std::vector<std::vector<unsigned long> > freq ;
 
 	JpegScan *p_scan = (JpegScan *) getParent() ;
 	JpegScanHeader *p_scanhdr = (JpegScanHeader *) p_scan->getScanHeader() ;
 	JpegFrame *p_frame = (JpegFrame *) p_scan->getParent() ;
 	JpegFrameHeader *p_framehdr = (JpegFrameHeader *) p_frame->getFrameHeader() ;
 
-	vector<unsigned int> dataunits ;
-	vector<unsigned int> htdestspec ;
+	std::vector<unsigned int> dataunits ;
+	std::vector<unsigned int> htdestspec ;
 	unsigned int maxdestspec = 0 ;
 	for (unsigned int comp = 0 ; comp < p_framehdr->getNumComponents() ; comp++) {
 		dataunits.push_back (p_framehdr->getHorizSampling (comp) * p_framehdr->getVertSampling (comp)) ;
@@ -95,7 +97,7 @@
 	}
 
 	for (unsigned int destspec = 0 ; destspec <= maxdestspec ; destspec++) {
-		freq.push_back (vector<unsigned long> (257)) ;
+		freq.push_back (std::vector<unsigned long> (257)) ;
 		freq[destspec][256] = 1 ;
 	}
 
@@ -151,7 +153,7 @@
 	JpegFrameHeader *p_framehdr = (JpegFrameHeader *) p_frame->getFrameHeader() ;
 
 	unsigned long unitstart = 0 ;
-	vector<int> prediction ;
+	std::vector<int> prediction ;
 	for (unsigned int comp = 0 ; comp < p_framehdr->getNumComponents() ; comp++) {
 		prediction.push_back (0) ;
 	}
@@ -228,10 +230,10 @@
 	JpegFrame *p_frame = (JpegFrame *) p_scan->getParent() ;
 	JpegFrameHeader *p_framehdr = (JpegFrameHeader *) p_frame->getFrameHeader() ;
 
-	vector<int> prediction ;
-	vector<JpegHuffmanTable*> DCTables ;
-	vector<JpegHuffmanTable*> ACTables ;
-	vector<unsigned int> dataunits ;
+	std::vector<int> prediction ;
+	std::vector<JpegHuffmanTable*> DCTables ;
+	std::vector<JpegHuffmanTable*> ACTables ;
+	std::vector<unsigned int> dataunits ;
 	for (unsigned int comp = 0 ; comp < p_framehdr->getNumComponents() ; comp++) {
 		prediction.push_back (0) ;
 		DCTables.push_back (p_frame->getDCTable (p_scanhdr->getDCDestSpec (comp))) ;
