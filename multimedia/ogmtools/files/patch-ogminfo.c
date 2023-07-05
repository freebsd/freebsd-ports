--- ogminfo.c.orig	2003-11-20 22:21:36 UTC
+++ ogminfo.c
@@ -51,7 +51,7 @@ ogg_int64_t  pagebytesread = 0;
 
 void add_stream(stream_t *ndmx) {
   stream_t *cur = first;
-  
+
   if (first == NULL) {
     first = ndmx;
     first->next = NULL;
@@ -66,13 +66,13 @@ void add_stream(stream_t *ndmx) {
 
 stream_t *find_stream(int fserial) {
   stream_t *cur = first;
-  
+
   while (cur != NULL) {
     if (cur->serial == fserial)
       break;
     cur = cur->next;
   }
-  
+
   return cur;
 }
 
@@ -92,7 +92,7 @@ void usage(char *fname) {
     "  -V, --version  Show version information.\n", fname);
 }
 
-#ifndef XIPHCORRECTINTERLEAVING  
+#ifndef XIPHCORRECTINTERLEAVING
 #define OUTOFSYNC   ((((stream->stype == 't' ? end_pts : start_pts) \
                        - last_pts) < 0.0 ) ? "OUT_OF_SYNC " : "sync_ok ")
 #else
@@ -131,7 +131,7 @@ void dump_streamheader(stream_header *sth, char stype,
 
 int all_header_packets_dumped() {
   stream_t *stream = first;
-  
+
   while (stream != NULL) {
     if ((stream->stype == 'V') && (stream->header_packets < 3))
       return 0;
@@ -139,7 +139,7 @@ int all_header_packets_dumped() {
       return 0;
     stream = stream->next;
   }
-  
+
   return 1;
 }
 
@@ -172,7 +172,7 @@ void handle_packet(stream_t *stream, ogg_packet *pack,
     vorbis_comment_init(&vc);
     if (vorbis_unpack_comment(&vc, pack->packet, pack->bytes) != 0)
       fprintf(stdout, "(%s) %c%d: comment packet, length %ld. This packet "
-              "does NOT contain a valid Vorbis comment packet!\n", 
+              "does NOT contain a valid Vorbis comment packet!\n",
               __FILE__, stream->stype, stream->sno, pack->bytes);
     else {
       fprintf(stdout, "(%s) %c%d: comment packet, length %ld,", __FILE__,
@@ -194,9 +194,9 @@ void handle_packet(stream_t *stream, ogg_packet *pack,
              __FILE__, stream->sno, pack->bytes, ogg_page_granulepos(page),
              pack->packetno);
     if (check_timing && (stream->sample_rate != -1)) {
-      end_pts = (double)ogg_page_granulepos(page) * 
+      end_pts = (double)ogg_page_granulepos(page) *
                 (double)1000.0 / (double)stream->sample_rate;
-      start_pts = (double)stream->last_granulepos * 
+      start_pts = (double)stream->last_granulepos *
                   (double)1000.0 / (double)stream->sample_rate;
       fprintf(stdout, " start: % 13.2fms  end: % 13.2fms %s",
               start_pts, end_pts, OUTOFSYNC);
@@ -224,9 +224,9 @@ void handle_packet(stream_t *stream, ogg_packet *pack,
               "10lld ", __FILE__, stream->stype, stream->sno, n,
               ogg_page_granulepos(page), pack->packetno);
       if (check_timing && (stream->sample_rate != -1)) {
-        end_pts = (double)ogg_page_granulepos(page) * 
+        end_pts = (double)ogg_page_granulepos(page) *
                   (double)1000.0 / (double)stream->sample_rate;
-        start_pts = (double)stream->last_granulepos * 
+        start_pts = (double)stream->last_granulepos *
                     (double)1000.0 / (double)stream->sample_rate;
         fprintf(stdout, " start: % 13.2fms  end: % 13.2fms %s",
                 start_pts, end_pts, OUTOFSYNC);
@@ -344,8 +344,8 @@ void process_ogm(int fdin)
       copy_headers(&sth, (old_stream_header *)&pack.packet[1], pack.bytes);
       if (!strncmp(sth.streamtype, "video", 5)) {
         unsigned long codec;
-        codec = (sth.subtype[0] << 24) + 
-          (sth.subtype[1] << 16) + (sth.subtype[2] << 8) + sth.subtype[3]; 
+        codec = (sth.subtype[0] << 24) +
+          (sth.subtype[1] << 16) + (sth.subtype[2] << 8) + sth.subtype[3];
         fprintf(stdout, "(%s) (v%d/serial %d) fps: %.3f width height: %dx%d "
                 "codec: %p (%c%c%c%c)\n", __FILE__, nvstreams + 1,
                 serialnumber, (double)10000000 /
@@ -450,7 +450,7 @@ void process_ogm(int fdin)
       numstreams++;
     }
   }
-  
+
   if ((verbose == 0) && !summary)
     exit(0);
 
@@ -500,7 +500,7 @@ void process_ogm(int fdin)
     }
     pagebytesread += pageseek;
   }
-  
+
   if (summary) {
     stream = first;
     while (stream != NULL) {
@@ -513,7 +513,7 @@ void process_ogm(int fdin)
               stream->serial, stream->size,
               (stream->size * 8.0 / 1000.0) / now,
               (stream->size / 1024.0) / now,
-              stream->num_packets, now * 1000.0);
+              stream->num_packets, now);
       stream = stream->next;
     }
   }
@@ -521,7 +521,7 @@ void process_ogm(int fdin)
 
 int main(int argc, char *argv[]) {
   int i, fdin = -1;
-  
+
   nice(2);
 
   for (i = 1; i < argc; i++)
@@ -552,11 +552,11 @@ int main(int argc, char *argv[]) {
     usage(argv[0]);
     exit(1);
   }
-  
+
   if (verbose >= 2)
     summary = 1;
-  process_ogm(fdin);  
-  
+  process_ogm(fdin);
+
   close(fdin);
   return 0;
 }
