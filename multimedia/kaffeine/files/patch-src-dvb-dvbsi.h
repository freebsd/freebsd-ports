--- src/dvb/dvbsi.h.orig	2015-08-07 15:43:59 UTC
+++ src/dvb/dvbsi.h
@@ -957,7 +957,6 @@ public:
 		return DvbPmtSectionEntry(getData() + 12 + descriptorsLength, getLength() - (16 + descriptorsLength));
 	}
 
-private:
 	Q_DISABLE_COPY(DvbPmtSection)
 	void initPmtSection(const char *data, int size);
 
