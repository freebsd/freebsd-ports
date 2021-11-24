--- libexfat/exfat.h.orig	2018-09-15 05:03:24 UTC
+++ libexfat/exfat.h
@@ -201,6 +201,7 @@ le16_t exfat_calc_name_hash(const struct exfat* ef, co
 void exfat_humanize_bytes(uint64_t value, struct exfat_human_bytes* hb);
 void exfat_print_info(const struct exfat_super_block* sb,
 		uint32_t free_clusters);
+bool exfat_match_option(const char* options, const char* option_name);
 
 int utf16_to_utf8(char* output, const le16_t* input, size_t outsize,
 		size_t insize);
