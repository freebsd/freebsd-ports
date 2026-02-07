--- libtsfuncs/crc.c.orig	2012-01-05 12:41:01 UTC
+++ libtsfuncs/crc.c
@@ -46,7 +46,7 @@ uint32_t ts_crc32(uint8_t *data, int dat
 	return crc;
 }
 
-u_int32_t ts_crc32_section(struct ts_section_header *section_header) {
+uint32_t ts_crc32_section(struct ts_section_header *section_header) {
 	return ts_crc32(section_header->section_data, section_header->section_data_len);
 }
 
