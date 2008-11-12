
$FreeBSD$

--- res/res_agi.c
+++ res/res_agi.c
@@ -969,7 +969,7 @@
 		
 		start = ast_tvnow();
 		while ((ms < 0) || ast_tvdiff_ms(ast_tvnow(), start) < ms) {
-			res = ast_waitfor(chan, -1);
+			res = ast_waitfor(chan, ms - ast_tvdiff_ms(ast_tvnow(), start));
 			if (res < 0) {
 				ast_closestream(fs);
 				fdprintf(agi->fd, "200 result=%d (waitfor) endpos=%ld\n", res,sample_offset);
