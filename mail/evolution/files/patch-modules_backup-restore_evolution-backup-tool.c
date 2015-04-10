From d9e63d55cd8ce597d9668dd4dd6f78c0900c9a94 Mon Sep 17 00:00:00 2001
From: Ting-Wei Lan <lantw@src.gnome.org>
Date: Wed, 8 Apr 2015 12:21:47 +0200
Subject: Bug 747461 - The tar command used to restore backups doesn't work on
 FreeBSD


diff --git a/modules/backup-restore/evolution-backup-tool.c b/modules/backup-restore/evolution-backup-tool.c
index 840cee1..a288ce6 100644
--- modules/backup-restore/evolution-backup-tool.c
+++ modules/backup-restore/evolution-backup-tool.c
@@ -538,14 +538,14 @@ restore (const gchar *filename,
 		g_mkdir_with_parents (e_get_user_config_dir (), 0700);
 
 		command = g_strdup_printf (
-			"cd $DATADIR && tar xzf %s %s --strip-components=%d",
-			quotedfname, data_dir, get_dir_level (data_dir));
+			"cd $DATADIR && tar --strip-components %d -xzf %s %s",
+			 get_dir_level (data_dir), quotedfname, data_dir);
 		run_cmd (command);
 		g_free (command);
 
 		command = g_strdup_printf (
-			"cd $CONFIGDIR && tar xzf %s %s --strip-components=%d",
-			quotedfname, config_dir, get_dir_level (config_dir));
+			"cd $CONFIGDIR && tar --strip-components %d -xzf %s %s",
+			get_dir_level (config_dir), quotedfname, config_dir);
 		run_cmd (command);
 		g_free (command);
 
-- 
cgit v0.10.2

