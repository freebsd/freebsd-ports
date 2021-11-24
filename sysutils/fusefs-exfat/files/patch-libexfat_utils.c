--- libexfat/utils.c.orig	2018-09-15 05:03:24 UTC
+++ libexfat/utils.c
@@ -178,3 +178,15 @@ void exfat_print_info(const struct exfat_super_block* 
 	exfat_humanize_bytes(avail_space, &hb);
 	printf("Available space      %10"PRIu64" %s\n", hb.value, hb.unit);
 }
+
+bool exfat_match_option(const char* options, const char* option_name)
+{
+	const char* p;
+	size_t length = strlen(option_name);
+
+	for (p = strstr(options, option_name); p; p = strstr(p + 1, option_name))
+		if ((p == options || p[-1] == ',') &&
+				(p[length] == ',' || p[length] == '\0'))
+			return true;
+	return false;
+}
