--- kcdlabel/audiocd.h.orig	Mon Dec 29 01:08:45 2003
+++ kcdlabel/audiocd.h	Mon Dec 29 02:15:45 2003
@@ -30,7 +30,12 @@
 #include <qobject.h>
 #include <qstring.h>
 
+#ifdef __FreeBSD__
+#include <sys/cdio.h>
+#define CDROM_LEADOUT	0xAA
+#else
 #include <linux/cdrom.h>		// specific to Linux !!! --> must be encapsulated in DEFINE IFDEF to enable compilation on other Un*x platforms...
+#endif
 
 /**Access all the audio CD functions and compute CDDB DiscID
   *@author Pascal 'PeP' Panneels
@@ -74,7 +79,11 @@
 	QString DiscID;				// CDDB DiscID
 	int cdromfd;				// device descriptor of the CDROM
 	unsigned int nr_tracks;	   	// # of tracks
+#ifdef __FreeBSD__
+	struct cd_toc_entry TOC[101];	// Table Of Content of the CD (max 99 tracks + lead-out + lead in)
+#else
 	struct cdrom_msf0 TOC[101];	// Table Of Content of the CD (max 99 tracks + lead-out + lead in)
+#endif
 	bool TOCAvailable;          // true when the TOC is available
 	unsigned long ulDiscID;		// computed disc id as an unsigned long
 	VectorIntType TrackOffsets;	// offsets of each track
