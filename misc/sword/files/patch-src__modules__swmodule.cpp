--- src/modules/swmodule.cpp.orig	2009-12-28 13:03:22.000000000 -0500
+++ src/modules/swmodule.cpp	2013-01-10 18:59:59.000000000 -0500
@@ -40,7 +40,6 @@
 
 #ifdef USELUCENE
 #include <CLucene.h>
-#include <CLucene/CLBackwards.h>
 
 //Lucence includes
 //#include "CLucene.h"
@@ -59,6 +58,9 @@
 
 using std::vector;
 
+extern size_t lucene_utf8towcs(wchar_t *, const char *,  size_t maxslen);
+extern size_t lucene_wcstoutf8 (char *,  const wchar_t *, size_t maxslen);
+
 SWORD_NAMESPACE_START
 
 SWDisplay SWModule::rawdisp;
@@ -521,7 +523,7 @@
 
 			// iterate thru each good module position that meets the search
 			bool checkBounds = getKey()->isBoundSet();
-			for (long i = 0; i < h->length(); i++) {
+			for (unsigned long i = 0; i < h->length(); i++) {
 				Document &doc = h->doc(i);
 
 				// set a temporary verse key to this module position
@@ -1144,7 +1146,7 @@
 
 			lucene_utf8towcs(wcharBuffer, keyText, MAX_CONV_SIZE); //keyText must be utf8
 //			doc->add( *(new Field("key", wcharBuffer, Field::STORE_YES | Field::INDEX_TOKENIZED)));
-			doc->add( *Field::Text(_T("key"), wcharBuffer ) );
+			doc->add(*_CLNEW Field(_T("key"), wcharBuffer, Field::STORE_YES | Field::INDEX_TOKENIZED) );
 
 
 			if (includeKeyInSearch) {
@@ -1155,11 +1157,11 @@
 			}
 
 			lucene_utf8towcs(wcharBuffer, content, MAX_CONV_SIZE); //content must be utf8
-			doc->add( *Field::UnStored(_T("content"), wcharBuffer) );
+			doc->add(*_CLNEW Field(_T("content"), wcharBuffer, Field::STORE_NO | Field::INDEX_TOKENIZED));
 
 			if (strong.length() > 0) {
 				lucene_utf8towcs(wcharBuffer, strong, MAX_CONV_SIZE);
-				doc->add( *Field::UnStored(_T("lemma"), wcharBuffer) );
+				doc->add(*_CLNEW Field(_T("lemma"), wcharBuffer, Field::STORE_NO | Field::INDEX_TOKENIZED) );
 //printf("setting fields (%s).\ncontent: %s\nlemma: %s\n", (const char *)*key, content, strong.c_str());
 			}
 
@@ -1280,12 +1282,12 @@
 
 //printf("proxBuf after (%s).\nprox: %s\nproxLem: %s\n", (const char *)*key, proxBuf.c_str(), proxLem.c_str());
 
-			doc->add( *Field::UnStored(_T("prox"), wcharBuffer) );
+			doc->add(*_CLNEW Field(_T("prox"), wcharBuffer, Field::STORE_NO | Field::INDEX_TOKENIZED) );
 			good = true;
 		}
 		if (proxLem.length() > 0) {
 			lucene_utf8towcs(wcharBuffer, proxLem, MAX_CONV_SIZE); //keyText must be utf8
-			doc->add( *Field::UnStored(_T("proxlem"), wcharBuffer) );
+			doc->add(*_CLNEW Field(_T("proxlem"), wcharBuffer, Field::STORE_NO | Field::INDEX_TOKENIZED) );
 			good = true;
 		}
 		if (good) {
@@ -1303,20 +1305,20 @@
 	//coreWriter->optimize();
 	coreWriter->close();
 
+	d = FSDirectory::getDirectory(target.c_str());
 	if (IndexReader::indexExists(target.c_str())) {
-		d = FSDirectory::getDirectory(target.c_str(), false);
 		if (IndexReader::isLocked(d)) {
 			IndexReader::unlock(d);
 		}
-
-		fsWriter = new IndexWriter( d, an, false);
-	} else {
-		d = FSDirectory::getDirectory(target.c_str(), true);
+		fsWriter = new IndexWriter(d, an, false);
+	}
+	else {
 		fsWriter = new IndexWriter(d, an, true);
 	}
 
 	Directory *dirs[] = { ramDir, 0 };
-	fsWriter->addIndexes(dirs);
+	lucene::util::ConstValueArray< lucene::store::Directory *>dirsa(dirs, 1);
+	fsWriter->addIndexes(dirsa);
 	fsWriter->close();
 
 	delete ramDir;
