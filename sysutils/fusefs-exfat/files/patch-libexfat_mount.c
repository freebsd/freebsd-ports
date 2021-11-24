--- libexfat/mount.c.orig	2018-09-15 05:03:24 UTC
+++ libexfat/mount.c
@@ -79,18 +79,6 @@ static int get_int_option(const char* options, const c
 	return strtol(p, NULL, base);
 }
 
-static bool match_option(const char* options, const char* option_name)
-{
-	const char* p;
-	size_t length = strlen(option_name);
-
-	for (p = strstr(options, option_name); p; p = strstr(p + 1, option_name))
-		if ((p == options || p[-1] == ',') &&
-				(p[length] == ',' || p[length] == '\0'))
-			return true;
-	return false;
-}
-
 static void parse_options(struct exfat* ef, const char* options)
 {
 	int opt_umask;
@@ -102,7 +90,7 @@ static void parse_options(struct exfat* ef, const char
 	ef->uid = get_int_option(options, "uid", 10, geteuid());
 	ef->gid = get_int_option(options, "gid", 10, getegid());
 
-	ef->noatime = match_option(options, "noatime");
+	ef->noatime = exfat_match_option(options, "noatime");
 
 	switch (get_int_option(options, "repair", 10, 0))
 	{
@@ -205,9 +193,9 @@ int exfat_mount(struct exfat* ef, const char* spec, co
 
 	parse_options(ef, options);
 
-	if (match_option(options, "ro"))
+	if (exfat_match_option(options, "ro"))
 		mode = EXFAT_MODE_RO;
-	else if (match_option(options, "ro_fallback"))
+	else if (exfat_match_option(options, "ro_fallback"))
 		mode = EXFAT_MODE_ANY;
 	else
 		mode = EXFAT_MODE_RW;
