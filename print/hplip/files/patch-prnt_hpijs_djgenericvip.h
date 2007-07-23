diff -uNr hplip-2.7.6.old/prnt/hpijs/djgenericvip.h hplip-2.7.6.new/prnt/hpijs/djgenericvip.h
--- prnt/hpijs/djgenericvip.h.orig	2007-07-06 10:31:25.000000000 -0700
+++ prnt/hpijs/djgenericvip.h	2007-07-06 10:48:25.000000000 -0700
@@ -52,6 +52,7 @@
     virtual PHOTOTRAY_STATE PhotoTrayEngaged (BOOL bQueryPrinter);
     //! Returns TRUE if a hagaki feed is present in printer.
     virtual BOOL HagakiFeedPresent(BOOL bQueryPrinter);
+	virtual DATA_FORMAT GetDataFormat () { return RASTER_STRIP; }
 
 #ifdef APDK_AUTODUPLEX
     //!Returns TRUE if duplexer and hagaki feed (combined) unit is present in printer.
