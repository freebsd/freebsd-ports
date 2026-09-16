--- tools/rkcommon.c.orig	2026-09-16 07:35:31 UTC
+++ tools/rkcommon.c
@@ -473,7 +473,7 @@ int rkcommon_verify_header(unsigned char *buf, int siz
 	int ret;
 
 	/* spl_hdr is abandon on header_v2 */
-	if ((*(uint32_t *)buf) == RK_MAGIC_V2)
+	if ((*(uint32_t *)buf) == cpu_to_le32(RK_MAGIC_V2))
 		return 0;
 
 	ret = rkcommon_parse_header(buf, &header0, &img_spl_info);
@@ -508,7 +508,7 @@ void rkcommon_print_header(const void *buf, struct ima
 	uint8_t image_type;
 	int ret, boot_size, init_size;
 
-	if ((*(uint32_t *)buf) == RK_MAGIC_V2) {
+	if ((*(uint32_t *)buf) == cpu_to_le32(RK_MAGIC_V2)) {
 		ret = rkcommon_parse_header_v2(buf, &header0_v2);
 
 		if (ret < 0) {
