diff --git a/src/remmina_stats.c b/src/remmina_stats.c
index a6eb6f609ba7f0a5d444da2eb9f34684725625a5..3b7cbf0bf61964cc027c936b753bece49986c193 100644
--- src/remmina_stats.c
+++ src/remmina_stats.c
@@ -159,8 +159,6 @@
 #endif
 #include "remmina_stats.h"
 
-struct utsname u;
-
 struct ProfilesData {
 	GHashTable *proto_count;
 	GHashTable *proto_date;
@@ -864,9 +862,6 @@ JsonNode *remmina_stats_get_all()
 	json_builder_set_member_name(b, "REMMINAVERSION");
 	json_builder_add_value(b, n);
 
-	if (uname(&u) == -1)
-		g_print("uname:");
-
 	n = remmina_stats_get_os_info();
 	json_builder_set_member_name(b, "SYSTEM");
 	json_builder_add_value(b, n);
