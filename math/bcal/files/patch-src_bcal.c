--- src/bcal.c.orig	2022-01-23 15:55:59 UTC
+++ src/bcal.c
@@ -179,7 +179,7 @@ static int try_bc(char *expr)
 	int pipe_pc[2], pipe_cp[2];
 	size_t len;
 	ssize_t ret;
-	char *ptr = cfg.calc ? "calc" : "bc";
+	char *ptr = cfg.calc ? "calc" : "%%BC_CMD%%";
 
 	if (!expr) {
 		if (curexpr)
