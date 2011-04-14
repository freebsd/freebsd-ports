--- src/dvb/dvbsi.h.orig	2011-04-09 15:09:19.000000000 +0200
+++ src/dvb/dvbsi.h	2011-04-09 15:09:29.000000000 +0200
@@ -957,7 +957,6 @@
 		return DvbPmtSectionEntry(getData() + 12 + descriptorsLength, getLength() - (16 + descriptorsLength));
 	}
 
-private:
 	Q_DISABLE_COPY(DvbPmtSection)
 	void initPmtSection(const char *data, int size);
 
