From 91241bb0f0abb00ac82c31ebe07e98808a7f86c3 Mon Sep 17 00:00:00 2001
From: Lars Windolf <lars.windolf@gmx.de>
Date: Wed, 29 Mar 2023 23:21:57 +0200
Subject: [PATCH] Fixes #1217: Endless recursion in 1.14.3 (reported by
 uduecoder)

---
 src/common.c | 4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git a/src/common.c b/src/common.c
index dddc8b09f..b0fa55369 100644
--- a/src/common.c
+++ b/src/common.c
@@ -85,6 +85,8 @@ common_init_paths (void)
 	common_check_dir (g_build_filename (g_get_user_config_dir(), "liferea", NULL));
 	common_check_dir (g_build_filename (g_get_user_data_dir(), "liferea", NULL));
 
+	pathsChecked = TRUE;
+
 	/* Install default stylesheet if it does not yet exist */
 	filename = common_create_config_filename ("liferea.css");
 	if (!g_file_test (filename, G_FILE_TEST_EXISTS))
@@ -95,8 +97,6 @@ common_init_paths (void)
 	umask (077);
 
 	g_free (lifereaCachePath);
-
-	pathsChecked = TRUE;
 }
 
 gchar *
