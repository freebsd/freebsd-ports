--- src/mux_h2.c
+++ src/mux_h2.c
@@ -1735,7 +1735,7 @@ static void h2_process_demux(struct h2c *h2c)
 				goto fail;
 			}
 
-			if ((int)hdr.len < 0 || (int)hdr.len > h2c->mfs) {
+			if ((int)hdr.len < 0 || (int)hdr.len > global.tune.bufsize) {
 				/* RFC7540#3.5: a GOAWAY frame MAY be omitted */
 				h2c_error(h2c, H2_ERR_FRAME_SIZE_ERROR);
 				h2c->st0 = H2_CS_ERROR2;
@@ -1765,7 +1765,7 @@ static void h2_process_demux(struct h2c *h2c)
 			if (!h2_peek_frame_hdr(h2c->dbuf, &hdr))
 				break;
 
-			if ((int)hdr.len < 0 || (int)hdr.len > h2c->mfs) {
+			if ((int)hdr.len < 0 || (int)hdr.len > global.tune.bufsize) {
 				h2c_error(h2c, H2_ERR_FRAME_SIZE_ERROR);
 				h2c->st0 = H2_CS_ERROR;
 				break;
