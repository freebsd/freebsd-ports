--- ./src/yydecoder.h.orig	2007-06-25 23:05:38.000000000 -0500
+++ ./src/yydecoder.h	2007-06-25 23:06:50.000000000 -0500
@@ -87,7 +87,7 @@
 	
 private:
 	
-	inline void yyDecoder::charCRC(const unsigned char *c);
+	inline void charCRC(const unsigned char *c);
 	
 	QStringList m_fileParts;
 	QStringList::Iterator fileIterator;
