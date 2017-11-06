--- res/res_pjsip/pjsip_cli.c.orig	2017-10-13 17:46:56 UTC
+++ res/res_pjsip/pjsip_cli.c
@@ -172,7 +172,7 @@ char *ast_sip_cli_traverse_objects(struct ast_cli_entr
 		}
 		regex = a->argv[4];
 	} else {
-		regex = "";
+		regex = ".";
 	}
 
 	if (cmd == CLI_GENERATE
