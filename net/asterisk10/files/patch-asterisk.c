
$FreeBSD$

--- asterisk.c.orig
+++ asterisk.c
@@ -177,6 +177,7 @@
 int fully_booted = 0;
 char record_cache_dir[AST_CACHE_DIR_LEN] = AST_TMP_DIR;
 char debug_filename[AST_FILENAME_MAX] = "";
+enum ast_trans_algorithm option_translation_algorithm = AST_TRANS_ALG_STRICT;
 
 static int ast_socket = -1;		/*!< UNIX Socket for allowing remote control */
 static int ast_consock = -1;		/*!< UNIX Socket for controlling another asterisk */
@@ -1803,7 +1804,6 @@
 
 	if (option_exec && data) {  /* hack to print output then exit if asterisk -rx is used */
 		char tempchar;
-#ifdef __Darwin__
 		struct pollfd fds[0];
 		fds[0].fd = ast_consock;
 		fds[0].events = POLLIN;
@@ -1811,9 +1811,6 @@
 		while (poll(fds, 1, 100) > 0) {
 			ast_el_read_char(el, &tempchar);
 		}
-#else
-		while (!ast_el_read_char(el, &tempchar));
-#endif
 		return;
 	}
 	for(;;) {
@@ -2009,6 +2006,30 @@
 			ast_copy_string(ast_config_AST_RUN_GROUP, v->value, sizeof(ast_config_AST_RUN_GROUP));
 		}
 		v = v->next;
+	}
+	option_translation_algorithm = AST_TRANS_ALG_STRICT;
+	for (v = ast_variable_browse(cfg, "codec_negotiation"); v; v = v->next)
+	{
+		if (!strcasecmp(v->name, "translation_algorithm")) {
+			if (!strcasecmp(v->value, "loose") ||
+			    !strcasecmp(v->value, "save_cpu") ||
+			    !strcasecmp(v->value, "avoid_translation") ||
+			    !strcasecmp(v->value, "asymmetric"))
+			{
+				option_translation_algorithm = AST_TRANS_ALG_LOOSE;
+			}
+/*
+			else if (!strcasecmp(v->value, "strict") ||
+				 !strcasecmp(v->value, "follow_peer") ||
+				 !strcasecmp(v->value, "avoid_asymmetry"))
+			{
+				option_translation_algorithm = AST_TRANS_ALG_STRICT;
+			}
+*/
+			else {
+				option_translation_algorithm = AST_TRANS_ALG_STRICT;
+			}
+		}
 	}
 	ast_config_destroy(cfg);
 }
