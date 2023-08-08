--- src/core/cfg.y.orig	(revision 2cebd46f8f2dc3f87c9cfd2054976e347aa75ace)
+++ src/core/cfg.y
@@ -2045,14 +2045,38 @@
 module_stm:
 	LOADMODULE STRING {
 		LM_DBG("loading module %s\n", $2);
-			if (load_module($2)!=0) {
+			if (ksr_load_module($2, NULL)!=0) {
+				yyerror("failed to load module");
+			}
+	}
+	| LOADMODULE LPAREN STRING RPAREN {
+		LM_DBG("loading module %s\n", $3);
+			if (ksr_load_module($3, NULL)!=0) {
+				yyerror("failed to load module");
+			}
+	}
+	| LOADMODULE LPAREN STRING COMMA STRING RPAREN {
+		LM_DBG("loading module %s opts %s\n", $3, $5);
+			if (ksr_load_module($3, $5)!=0) {
 				yyerror("failed to load module");
 			}
 	}
 	| LOADMODULE error	{ yyerror("string expected"); }
 	| LOADMODULEX STRING {
 		LM_DBG("loading module %s\n", $2);
-			if (load_modulex($2)!=0) {
+			if (ksr_load_modulex($2, NULL)!=0) {
+				yyerror("failed to load module");
+			}
+	}
+	| LOADMODULEX LPAREN STRING RPAREN {
+		LM_DBG("loading module %s\n", $3);
+			if (ksr_load_modulex($3, NULL)!=0) {
+				yyerror("failed to load module");
+			}
+	}
+	| LOADMODULEX LPAREN STRING COMMA STRING RPAREN {
+		LM_DBG("loading module %s opts %s\n", $3, $5);
+			if (ksr_load_modulex($3, $5)!=0) {
 				yyerror("failed to load module");
 			}
 	}
