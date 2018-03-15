--- res/res_pjsip/pjsip_cli.c.orig	2017-12-20 20:39:39 UTC
+++ res/res_pjsip/pjsip_cli.c
@@ -163,7 +163,7 @@ char *ast_sip_cli_traverse_objects(struct ast_cli_entr
 		}
 		regex = a->argv[4];
 	} else {
-		regex = "";
+		regex = ".";
 	}
 
 	if (cmd == CLI_GENERATE
