--- plugins/libvorbis/libvorbis.cpp.orig	Fri Aug  6 12:35:41 2004
+++ plugins/libvorbis/libvorbis.cpp	Fri Aug  6 12:49:27 2004
@@ -96,7 +96,7 @@
 	op.packet = NULL;
 	op.b_o_s  = 1; /* beginning of stream for first packet */
 	op.bytes  = hdrsizes[0];
-	(const void*) op.packet = vorbishdr;
+	op.packet = (unsigned char*) vorbishdr;
 	vorbishdr += op.bytes;
 	if (vorbis_synthesis_headerin(&vi, &vc, &op) < 0)
 	{
@@ -106,7 +106,7 @@
 
 	op.b_o_s  = 0;
 	op.bytes  = hdrsizes[1];
-	(const void*) op.packet = vorbishdr;
+	op.packet = (unsigned char*) vorbishdr;
 	vorbishdr += op.bytes;
 	if (vorbis_synthesis_headerin(&vi, &vc, &op) < 0)
 	{
@@ -115,7 +115,7 @@
 	}
 
 	op.bytes  = hdrsizes[2];
-	(const void*) op.packet = vorbishdr;
+	op.packet = (unsigned char*) vorbishdr;
 	vorbishdr += op.bytes;
 	if (vorbis_synthesis_headerin(&vi, &vc, &op) < 0)
 	{
