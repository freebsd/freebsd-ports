--- rdpsnd_oss.c.orig	2007-08-20 23:20:40.000000000 -0700
+++ rdpsnd_oss.c	2007-08-20 23:21:51.000000000 -0700
@@ -51,6 +51,35 @@
 } packet_queue[MAX_QUEUE];
 static unsigned int queue_hi, queue_lo;
 
+/** Frees the first audio packet in the queue (that is, packet_queue[queue_lo]),
+ * sending a completion notification back to the server.
+ *
+ * @return True if the packet queue has become empty; False otherwise.&nbsp;
+ *
+ * If the packet queue is not empty, queue_lo will point at the next packet to
+ * play.
+ */
+static BOOL
+packet_done(void)
+{
+	struct audio_packet *packet = &packet_queue[queue_lo++];
+	queue_lo %= MAX_QUEUE;
+	rdpsnd_send_completion(packet->tick, packet->index);
+	free(packet->s.data);
+	return (queue_lo == queue_hi);
+}
+
+/** Discards all audio packets queued, sending completion notifications back to
+ * the server as necessary.
+ */
+static void
+clear_queue(void)
+{
+	while (queue_lo != queue_hi)
+		packet_done();
+	g_dsp_busy = False;
+}
+
 BOOL
 wave_out_open(void)
 {
@@ -74,6 +103,7 @@
 wave_out_close(void)
 {
 	close(g_dsp_fd);
+	clear_queue();
 }
 
 BOOL
@@ -277,9 +307,7 @@
 
 		if (elapsed >= (duration * 85) / 100)
 		{
-			rdpsnd_send_completion(packet->tick, packet->index);
-			free(out->data);
-			queue_lo = (queue_lo + 1) % MAX_QUEUE;
+			packet_done();
 			started = False;
 		}
 		else
