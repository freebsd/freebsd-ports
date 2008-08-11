
$FreeBSD$

--- main/manager.c.orig
+++ main/manager.c
@@ -73,7 +73,7 @@
 
 struct fast_originate_helper {
 	char tech[AST_MAX_EXTENSION];
-	char data[AST_MAX_EXTENSION];
+	char data[AST_MAX_EXTENSION * 5];
 	int timeout;
 	char app[AST_MAX_APP];
 	char appdata[AST_MAX_EXTENSION];
