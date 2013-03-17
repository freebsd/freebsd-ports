diff --git a/libfreerdp-core/fastpath.c b/libfreerdp-core/fastpath.c
index dc9caac..587c316 100644
--- libfreerdp-core/fastpath.c
+++ libfreerdp-core/fastpath.c
@@ -82,7 +82,7 @@ uint16 fastpath_read_header(rdpFastPath* fastpath, STREAM* s)
 	return length;
 }
 
-INLINE void fastpath_read_update_header(STREAM* s, uint8* updateCode, uint8* fragmentation, uint8* compression)
+static INLINE void fastpath_read_update_header(STREAM* s, uint8* updateCode, uint8* fragmentation, uint8* compression)
 {
 	uint8 updateHeader;
 
@@ -92,7 +92,7 @@ INLINE void fastpath_read_update_header(STREAM* s, uint8* updateCode, uint8* fra
 	*compression = (updateHeader >> 6) & 0x03;
 }
 
-INLINE void fastpath_write_update_header(STREAM* s, uint8 updateCode, uint8 fragmentation, uint8 compression)
+static INLINE void fastpath_write_update_header(STREAM* s, uint8 updateCode, uint8 fragmentation, uint8 compression)
 {
 	uint8 updateHeader = 0;
 
