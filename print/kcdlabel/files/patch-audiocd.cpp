--- kcdlabel/audiocd.cpp.orig	Mon Dec 29 01:15:28 2003
+++ kcdlabel/audiocd.cpp	Mon Dec 29 02:15:09 2003
@@ -58,8 +58,13 @@
 
 bool AudioCD::readTOC()
 {
+#ifdef __FreeBSD__
+	struct ioc_toc_header tochdr;
+	struct ioc_read_toc_single_entry tocentry;
+#else
 	struct cdrom_tochdr tochdr;
 	struct cdrom_tocentry tocentry;
+#endif
 	int i;
 
 	emit statusText((char *)"Reading Toc...");
@@ -73,36 +78,61 @@
 		return(false);
 		}
 		
+#ifdef __FreeBSD__
+	if (ioctl(cdromfd, CDIOREADTOCHEADER, &tochdr) == -1)
+#else
 	if (ioctl(cdromfd,CDROMREADTOCHDR,&tochdr) == -1)
+#endif
 		{
 		emit statusText((char *)"Read Toc - Read TOC Header error");
 		close(cdromfd);
 		return(false);
 		}
 
+#ifdef __FreeBSD__
+	tocentry.address_format = CD_MSF_FORMAT;
+	for (i = tochdr.starting_track; i <= tochdr.ending_track; i++) {
+		tocentry.track = i;
+		if (ioctl(cdromfd, CDIOREADTOCENTRY, &tocentry) == -1)
+#else
 	tocentry.cdte_format = CDROM_MSF;
 	for (i=tochdr.cdth_trk0;i<=tochdr.cdth_trk1;i++)
 		{
 		tocentry.cdte_track = i;
 		if (ioctl(cdromfd,CDROMREADTOCENTRY,&tocentry) == -1)
+#endif
 			{
 			emit statusText((char *)"Read Toc - Read TOC Entry error");
 			close(cdromfd);
 			return(false);
 			}
+#ifdef __FreeBSD__
+		TOC[nr_tracks++] = tocentry.entry;
+		TrackOffsets.push_back( (TOC[nr_tracks-1].addr.msf.minute*60+TOC[nr_tracks-1].addr.msf.second)*75+TOC[nr_tracks-1].addr.msf.frame ); 
+		}
+	tocentry.track = CDROM_LEADOUT;
+	if (ioctl(cdromfd, CDIOREADTOCENTRY, &tocentry) == -1)
+#else
 		TOC[nr_tracks++] = tocentry.cdte_addr.msf;
 		TrackOffsets.push_back( (TOC[nr_tracks-1].minute*60+TOC[nr_tracks-1].second)*75+TOC[nr_tracks-1].frame );
 		}
 	tocentry.cdte_track = CDROM_LEADOUT;
 	if (ioctl(cdromfd,CDROMREADTOCENTRY,&tocentry) == -1)
+#endif
 		{
 		emit statusText((char *)"Read Toc - Read TOC Entry (Lead-out) error");
 		close(cdromfd);
 		return(false);
         }
+#ifdef __FreeBSD__
+	TOC[nr_tracks] = tocentry.entry;
+	// cd length in seconds
+	CDLength = TOC[nr_tracks].addr.msf.minute*60 + TOC[nr_tracks].addr.msf.second;
+#else
 	TOC[nr_tracks] = tocentry.cdte_addr.msf;
 	// cd length in seconds
 	CDLength = TOC[nr_tracks].minute*60 + TOC[nr_tracks].second;
+#endif
 	// close the cdrom device
 	close(cdromfd);
 	TOCAvailable=true;
@@ -120,10 +150,18 @@
 		
 	while ( i < nr_tracks )
 		{
+#ifdef __FreeBSD__
+		n = n + cddb_sum( ( TOC[i].addr.msf.minute * 60 ) + TOC[i].addr.msf.second );
+#else
 		n = n + cddb_sum( ( TOC[i].minute * 60 ) + TOC[i].second );
+#endif
 		i++;
 		}
+#ifdef __FreeBSD__
+	t = (( TOC[nr_tracks].addr.msf.minute * 60 ) + TOC[nr_tracks].addr.msf.second ) - (( TOC[0].addr.msf.minute * 60)+ TOC[0].addr.msf.second );
+#else
 	t = (( TOC[nr_tracks].minute * 60 ) + TOC[nr_tracks].second ) - (( TOC[0].minute * 60)+ TOC[0].second );
+#endif
 	// get the discid in unsigned long
 	ulDiscID = (( n % 0xff) << 24 | t << 8 | nr_tracks);
 	// format the disc id to get a hexdecimal 8 digits string
