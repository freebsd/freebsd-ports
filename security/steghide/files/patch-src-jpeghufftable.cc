--- src/jpeghufftable.cc.orig	Thu Sep 26 21:02:04 2002
+++ src/jpeghufftable.cc	Thu Sep 26 21:22:37 2002
@@ -22,13 +22,14 @@
 #include <limits.h>
 
 #include <iostream>
+#include <vector>
 
 #include "error.h"
 #include "binaryio.h"
 #include "jpegbase.h"
 #include "jpeghufftable.h"
 
-JpegHuffmanTable::JpegHuffmanTable (unsigned int lr = UINT_MAX)
+JpegHuffmanTable::JpegHuffmanTable (unsigned int lr )
 	: JpegSegment (JpegElement::MarkerDHT)
 {
 	tableclass = 0xFF ;
@@ -36,7 +37,7 @@
 	lengthremaining = lr ;
 }
 
-JpegHuffmanTable::JpegHuffmanTable (BinaryIO *io, unsigned int lr = UINT_MAX)
+JpegHuffmanTable::JpegHuffmanTable (BinaryIO *io, unsigned int lr )
 	: JpegSegment (JpegElement::MarkerDHT)
 {
 	tableclass = 0xFF ;
@@ -81,7 +82,7 @@
 	return tabledestid ;
 }
 
-void JpegHuffmanTable::reset (vector<unsigned int> b, vector<unsigned int> hv)
+void JpegHuffmanTable::reset (std::vector<unsigned int> b, std::vector<unsigned int> hv)
 {
 	assert (b.size() == 16) ;
 
@@ -236,7 +237,7 @@
 	for (unsigned int l = 1 ; l <= Len_bits ; l++) {
 		io->write8 ((unsigned char) getBits(l)) ;
 	}
-	vector<unsigned int>::iterator p = huffval.begin() ;
+	std::vector<unsigned int>::iterator p = huffval.begin() ;
 	for (unsigned int l = 1 ; l <= Len_bits ; l++) {
 		for (unsigned int j = 0 ; j < getBits (l) ; j++) {
 			io->write8 (*p) ;
