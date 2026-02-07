--- src/main.c.orig	2014-11-20 03:16:13 UTC
+++ src/main.c
@@ -280,10 +280,8 @@ int main(int argc, char *argv[])
 	colorlabel_read_config();
 
 	prefs_common.user_agent_str = g_strdup_printf
-		("%s (GTK+ %d.%d.%d; %s)",
-		 prog_version,
-		 gtk_major_version, gtk_minor_version, gtk_micro_version,
-		 TARGET_ALIAS);
+		("%s",
+		 prog_version);
 
 #if defined(G_OS_WIN32) || defined(__APPLE__)
 	fix_font_setting();
