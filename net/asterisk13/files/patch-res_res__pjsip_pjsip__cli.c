--- res/res_pjsip/pjsip_cli.c.orig	2016-05-13 17:41:41 UTC
+++ res/res_pjsip/pjsip_cli.c
@@ -172,7 +172,7 @@ char *ast_sip_cli_traverse_objects(struc
 		}
 		regex = a->argv[4];
 	} else {
-		regex = "";
+		regex = ".";
 	}
 
 	if (cmd == CLI_GENERATE
