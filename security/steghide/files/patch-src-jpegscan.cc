--- src/jpegscan.cc.orig	Thu Sep 26 21:26:56 2002
+++ src/jpegscan.cc	Thu Sep 26 21:30:37 2002
@@ -20,6 +20,7 @@
 
 #include <vector>
 #include <limits.h>
+#include <string>
 
 #include <libintl.h>
 #define _(S) gettext (S)
@@ -141,11 +142,11 @@
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
