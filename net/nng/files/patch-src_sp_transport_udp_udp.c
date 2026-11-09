--- src/sp/transport/udp/udp.c.orig	2026-10-18 17:22:45 UTC
+++ src/sp/transport/udp/udp.c
@@ -888,9 +888,9 @@ udp_rx_cb(void *arg)
 		// Fix the endianness, so other routines don't have to.
 		// We only have to do this for systems that are not known
 		// (at compile time) to be little endian.
-		hdr->us_type      = NNI_GET16LE(&hdr->us_type);
-		hdr->us_params[0] = NNI_GET16LE(&hdr->us_params[0]);
-		hdr->us_params[1] = NNI_GET16LE(&hdr->us_params[1]);
+		NNI_GET16LE(&hdr->us_type, hdr->us_type);
+		NNI_GET16LE(&hdr->us_params[0], hdr->us_params[0]);
+		NNI_GET16LE(&hdr->us_params[1], hdr->us_params[1]);
 #endif
 
 		switch (hdr->us_op_code) {
