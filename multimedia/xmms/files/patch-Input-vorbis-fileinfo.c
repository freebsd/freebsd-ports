--- Input/vorbis/fileinfo.c.orig	Thu Nov 20 14:35:34 2003
+++ Input/vorbis/fileinfo.c	Sun Nov 21 17:35:46 2004
@@ -429,7 +429,8 @@
 	gchar *location;
 	gchar *rg_track_gain, *rg_album_gain, *rg_track_peak, *rg_album_peak;
 
-	gint time, minutes, seconds, bitrate, rate, channels, filesize, i;
+	gint time, minutes, seconds, bitrate, avgbitrate, rate, channels, filesize, i;
+	gchar *vendor = "N/A";
 
 	OggVorbis_File vf;
 	vorbis_info *vi;
@@ -437,10 +438,11 @@
 	FILE *fh;
 	gboolean clear_vf = FALSE;
 
-	static GtkWidget *info_frame, *info_box, *bitrate_label, *rate_label;
+	static GtkWidget *info_frame, *info_box, *bitrate_label, *avgbitrate_label, *rate_label;
 	static GtkWidget *channel_label, *length_label, *filesize_label;
 	static GtkWidget *replaygain_label, *audiophilegain_label, *peak_label;
 	static GtkWidget *filename_entry, *tag_frame;
+	static GtkWidget *vendor_label;
 
 	g_free(vte.filename);
 	vte.filename = g_strdup(fn);
@@ -721,7 +723,14 @@
 				      GTK_JUSTIFY_LEFT);
 		gtk_box_pack_start(GTK_BOX(info_box), bitrate_label, FALSE,
 				   FALSE, 0);
-		
+
+		avgbitrate_label = gtk_label_new("");
+		gtk_misc_set_alignment(GTK_MISC(avgbitrate_label), 0, 0);
+		gtk_label_set_justify(GTK_LABEL(avgbitrate_label),
+				      GTK_JUSTIFY_LEFT);
+		gtk_box_pack_start(GTK_BOX(info_box), avgbitrate_label, FALSE,
+				   FALSE, 0);
+
 		rate_label = gtk_label_new("");
 		gtk_misc_set_alignment(GTK_MISC(rate_label), 0, 0);
 		gtk_label_set_justify(GTK_LABEL(rate_label), GTK_JUSTIFY_LEFT);
@@ -749,6 +758,13 @@
 		gtk_box_pack_start(GTK_BOX(info_box), filesize_label, FALSE,
 				   FALSE, 0);
 
+		vendor_label = gtk_label_new("");
+		gtk_misc_set_alignment(GTK_MISC(vendor_label), 0, 0);
+		gtk_label_set_justify(GTK_LABEL(vendor_label),
+				      GTK_JUSTIFY_LEFT);
+		gtk_box_pack_start(GTK_BOX(info_box), vendor_label, FALSE,
+				   FALSE, 0);
+
 		replaygain_label = gtk_label_new("");
 		gtk_misc_set_alignment(GTK_MISC(replaygain_label), 0, 0);
 		gtk_label_set_justify(GTK_LABEL(replaygain_label),
@@ -780,10 +796,12 @@
 		gtk_widget_set_sensitive(tag_frame, TRUE);		
 
 	gtk_label_set_text(GTK_LABEL(bitrate_label), "");
+	gtk_label_set_text(GTK_LABEL(avgbitrate_label), "");
 	gtk_label_set_text(GTK_LABEL(rate_label), "");
 	gtk_label_set_text(GTK_LABEL(channel_label), "");
 	gtk_label_set_text(GTK_LABEL(length_label), "");
 	gtk_label_set_text(GTK_LABEL(filesize_label), "");
+	gtk_label_set_text(GTK_LABEL(vendor_label), "");
 
 	if ((fh = fopen(vte.filename, "r")) != NULL)
 	{
@@ -792,9 +810,18 @@
 		if (ov_open(fh, &vf, NULL, 0) == 0)
 		{
 			comment = ov_comment(&vf, -1);
+			if(comment)
+			{
+				vendor = comment->vendor;
+			}
+			else
+			{
+				vendor = (char*)"N/A";
+			}
 			if ((vi = ov_info(&vf, 0)) != NULL)
 			{
 				bitrate = vi->bitrate_nominal/1000;
+				avgbitrate = ov_bitrate(&vf, -1);
 				rate = vi->rate;
 				channels = vi->channels;
 				g_message("version: %d", vi->version);
@@ -803,6 +830,7 @@
 			else
 			{
 				bitrate = 0;
+				avgbitrate = 0;
 				rate = 0;
 				channels = 0;
 			}
@@ -814,10 +842,12 @@
 			filesize = ftell(fh);
 
 			label_set_text(bitrate_label, _("Nominal bitrate: %d kbps"), bitrate);
+			label_set_text(avgbitrate_label, _("Average bitrate: %.1f kbps"), ((float)avgbitrate)/1000);
 			label_set_text(rate_label, _("Samplerate: %d Hz"), rate);
 			label_set_text(channel_label, _("Channels: %d"), channels);
 			label_set_text(length_label, _("Length: %d:%.2d"), minutes, seconds);
 			label_set_text(filesize_label, _("File size: %d B"), filesize);
+			label_set_text(vendor_label, _("Vendor: %s"), vendor);
 
 		}
 		else
