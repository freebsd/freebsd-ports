--- gfuncts.c.orig	Sat Aug 30 00:16:50 2003
+++ gfuncts.c	Sat Aug 30 15:58:09 2003
@@ -382,14 +382,24 @@
 	info ("Invalid destination port value\n");
 	return -1;
      }
+#ifdef __FreeBSD__
+   if (strtoll(gtk_entry_get_text(GTK_ENTRY(seq_entry)), NULL, 10)<0 ||
+       strtoll(gtk_entry_get_text(GTK_ENTRY(seq_entry)), NULL, 10)>4294970000)
+#else
    if (atoll(gtk_entry_get_text(GTK_ENTRY(seq_entry)))<0 ||
        atoll(gtk_entry_get_text(GTK_ENTRY(seq_entry)))>4294970000)
+#endif
      {
 	info ("Invalid sequence number value\n");
 	return -1;
      }
+#ifdef __FreeBSD__
+   if (strtoll(gtk_entry_get_text(GTK_ENTRY(ack_entry)), NULL, 10)<0 ||
+       strtoll(gtk_entry_get_text(GTK_ENTRY(ack_entry)), NULL, 10)>4294970000)
+#else
    if (atoll(gtk_entry_get_text(GTK_ENTRY(ack_entry)))<0 ||
        atoll(gtk_entry_get_text(GTK_ENTRY(ack_entry)))>4294970000)
+#endif
      {
 	info ("Invalid acknowledgment value\n");
 	return -1;
