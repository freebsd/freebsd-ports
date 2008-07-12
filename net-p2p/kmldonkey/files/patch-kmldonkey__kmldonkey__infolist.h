--- ./kmldonkey/kmldonkey/infolist.h.orig	2008-07-12 06:07:09.000000000 -0300
+++ ./kmldonkey/kmldonkey/infolist.h	2008-07-12 06:07:25.000000000 -0300
@@ -301,6 +301,7 @@
 QString humanReadableTime( time_t t, bool shortFormat );
 QString calculateETA( FileInfo* fi );
 QString humanReadablePriority( int pri );
+QString humanReadableFileNumber( int fileNo );
 
 
 #endif /* __INFOLIST_H__ */
