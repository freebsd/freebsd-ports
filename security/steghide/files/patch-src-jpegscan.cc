--- src/jpegscan.cc.orig	Tue May 14 07:48:06 2002
+++ src/jpegscan.cc	Wed Aug 13 10:27:45 2003
@@ -20,6 +20,8 @@
 
 #include <vector>
 #include <limits.h>
+#include <string>
+#include <assert.h>
 
 #include <libintl.h>
 #define _(S) gettext (S)
@@ -141,11 +143,11 @@
 	}
 }
 
-vector<vector <unsigned long> > JpegScan::getFreqs ()
+std::vector<std::vector <unsigned long> > JpegScan::getFreqs ()
 {
-	vector<vector <unsigned long> > freqs = ECSegs[0]->getFreqs() ;
-	for (vector<JpegEntropyCoded*>::iterator i = ECSegs.begin() + 1 ; i != ECSegs.end() ; i++) {
-		vector<vector <unsigned long> > addfreqs = (*i)->getFreqs() ;
+	std::vector<std::vector <unsigned long> > freqs = ECSegs[0]->getFreqs() ;
+	for (std::vector<JpegEntropyCoded*>::iterator i = ECSegs.begin() + 1 ; i != ECSegs.end() ; i++) {
+		std::vector<std::vector <unsigned long> > addfreqs = (*i)->getFreqs() ;
 		for (unsigned int j = 0 ; j < addfreqs.size() ; j++) {
 			for (unsigned int k = 0 ; k < 256 ; k++) {
 				// don't touch freqs[j][256], must remain 1
