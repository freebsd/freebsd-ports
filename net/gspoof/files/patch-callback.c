--- callbacks.c.orig	Wed Sep 25 04:19:53 2002
+++ callbacks.c	Wed May  7 03:40:18 2003
@@ -194,13 +194,21 @@
 	return;
      }
 
+#ifdef __FreeBSD__
+   if (atoi (gtk_entry_get_text (GTK_ENTRY(tcp_seq_txt))) > 4294970000 || atoi (gtk_entry_get_text (GTK_ENTRY(tcp_seq_txt))) < 0)
+#else
    if (atoll (gtk_entry_get_text (GTK_ENTRY(tcp_seq_txt))) > 4294970000 || atoi (gtk_entry_get_text (GTK_ENTRY(tcp_seq_txt))) < 0)
+#endif
      {
 	info ("Error: sequence number is not valid, it must be between 0 and 2^32-1\n");
 	return;
      }
 
+#ifdef __FreeBSD__
+   if (atoi (gtk_entry_get_text (GTK_ENTRY(tcp_ack_txt))) > 4294970000 || atoi (gtk_entry_get_text (GTK_ENTRY(tcp_ack_txt))) < 0)
+#else
    if (atoll (gtk_entry_get_text (GTK_ENTRY(tcp_ack_txt))) > 4294970000 || atoi (gtk_entry_get_text (GTK_ENTRY(tcp_ack_txt))) < 0)
+#endif
      {
 	info ("Error: acknowledgement number is not valid, it must be between 0 and 2^32-1\n");
 	return;
