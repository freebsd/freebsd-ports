--- src/jpegframe.cc.orig	Thu Sep 26 23:59:23 2002
+++ src/jpegframe.cc	Fri Sep 27 00:04:28 2002
@@ -19,6 +19,8 @@
  */
 
 #include <limits.h>
+#include <string>
+#include <vector>
 
 #include <libintl.h>
 #define _(S) gettext (S)
@@ -34,16 +36,16 @@
 	: JpegContainer()
 {
 	framehdr = NULL ;
-	ACTables = vector<JpegHuffmanTable*> (4) ;
-	DCTables = vector<JpegHuffmanTable*> (4) ;
+	ACTables = std::vector<JpegHuffmanTable*> (4) ;
+	DCTables = std::vector<JpegHuffmanTable*> (4) ;
 }
 
 JpegFrame::JpegFrame (BinaryIO *io)
 	: JpegContainer()
 {
 	framehdr = NULL ;
-	ACTables = vector<JpegHuffmanTable*> (4) ;
-	DCTables = vector<JpegHuffmanTable*> (4) ;
+	ACTables = std::vector<JpegHuffmanTable*> (4) ;
+	DCTables = std::vector<JpegHuffmanTable*> (4) ;
 
 	read (io) ;
 }
@@ -164,24 +166,24 @@
 	JpegContainer::write (io) ;
 }
 
-void JpegFrame::recalcACTables (vector<vector <unsigned long> > freqs)
+void JpegFrame::recalcACTables (std::vector<std::vector <unsigned long> > freqs)
 {
-	for (vector<JpegHuffmanTable*>::iterator ht = ACTables.begin() ; ht != ACTables.end() ; ht++) {	
+	for (std::vector<JpegHuffmanTable*>::iterator ht = ACTables.begin() ; ht != ACTables.end() ; ht++) {	
 		if (*ht != NULL) {
-			vector<unsigned int> codesize = calcCodeSize (freqs[(*ht)->getDestId()]) ;
-			vector<unsigned int> bits = calcBits (codesize) ;
-			vector<unsigned int> huffval = calcHuffVal (codesize) ;
+			std::vector<unsigned int> codesize = calcCodeSize (freqs[(*ht)->getDestId()]) ;
+			std::vector<unsigned int> bits = calcBits (codesize) ;
+			std::vector<unsigned int> huffval = calcHuffVal (codesize) ;
 
 			(*ht)->reset (bits, huffval) ;
 		}
 	}
 }
 
-vector<unsigned int> JpegFrame::calcCodeSize (vector<unsigned long> freq)
+std::vector<unsigned int> JpegFrame::calcCodeSize (std::vector<unsigned long> freq)
 {
-	vector<unsigned int> codesize(257) ;
-	vector<long int> others(257) ;
-	for (vector<long int>::iterator j = others.begin() ; j != others.end() ; j++) {
+	std::vector<unsigned int> codesize(257) ;
+	std::vector<long int> others(257) ;
+	for (std::vector<long int>::iterator j = others.begin() ; j != others.end() ; j++) {
 		*j = -1 ;
 	}
 
@@ -230,9 +232,9 @@
 	return codesize ;
 }
 
-vector<unsigned int> JpegFrame::calcBits (vector<unsigned int> codesize)
+std::vector<unsigned int> JpegFrame::calcBits (std::vector<unsigned int> codesize)
 {
-	vector<unsigned int> bits (33) ;
+	std::vector<unsigned int> bits (33) ;
 
 	for (unsigned int i = 0 ; i < 257 ; i++) {
 		if (codesize[i] > 0) {
@@ -275,9 +277,9 @@
 	return bits ;
 }
 
-vector<unsigned int> JpegFrame::calcHuffVal (vector<unsigned int> codesize)
+std::vector<unsigned int> JpegFrame::calcHuffVal (std::vector<unsigned int> codesize)
 {
-	vector<unsigned int> huffval ;
+	std::vector<unsigned int> huffval ;
 	for (unsigned int i = 1 ; i <= 32 ; i++) {
 		for (unsigned j = 0 ; j <= 255 ; j++) {
 			if (codesize[j] == i) {
