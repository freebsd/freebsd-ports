--- src/jpegbase.cc.orig	Thu Sep 26 22:09:33 2002
+++ src/jpegbase.cc	Thu Sep 26 22:18:35 2002
@@ -19,6 +19,8 @@
  */
 
 #include <assert.h>
+#include <vector>
+#include <string>
 
 #include "binaryio.h"
 #include "jpegbase.h"
@@ -176,17 +178,17 @@
 
 JpegContainer::~JpegContainer ()
 {
-	for (vector<JpegObject*>::iterator i = jpegobjs.begin() ; i != jpegobjs.end() ; i++) {
+	for (std::vector<JpegObject*>::iterator i = jpegobjs.begin() ; i != jpegobjs.end() ; i++) {
 		delete (*i) ;
 	}
 }
 
-vector<JpegObject*> JpegContainer::getJpegObjects ()
+std::vector<JpegObject*> JpegContainer::getJpegObjects ()
 {
 	return jpegobjs ;
 }
 
-vector<CvrStgObject*> JpegContainer::getCvrStgObjects ()
+std::vector<CvrStgObject*> JpegContainer::getCvrStgObjects ()
 {
 	return cvrstgobjs ;
 }
@@ -213,7 +215,7 @@
 void JpegContainer::write (BinaryIO *io)
 {
 	// writing is only done here, not in derived classes
-	for (vector<JpegObject*>::iterator i = jpegobjs.begin() ; i != jpegobjs.end() ; i++) {
+	for (std::vector<JpegObject*>::iterator i = jpegobjs.begin() ; i != jpegobjs.end() ; i++) {
 		(*i)->write (io) ;
 	}
 }
@@ -222,7 +224,7 @@
 {
 	unsigned long sum = 0 ;
 
-	for (vector<CvrStgObject*>::const_iterator i = cvrstgobjs.begin() ; i != cvrstgobjs.end() ; i++) {
+	for (std::vector<CvrStgObject*>::const_iterator i = cvrstgobjs.begin() ; i != cvrstgobjs.end() ; i++) {
 		sum += (*i)->getCapacity() ;
 	}
 
@@ -245,7 +247,7 @@
 CvrStgObject *JpegContainer::calcCvrStgObject (unsigned long *pos) const
 {
 	unsigned long curCapacity = 0 ;
-	vector<CvrStgObject*>::const_iterator i = cvrstgobjs.begin() ;
+	std::vector<CvrStgObject*>::const_iterator i = cvrstgobjs.begin() ;
 
 	curCapacity = (*i)->getCapacity() ;
 	while (*pos >= curCapacity) {
