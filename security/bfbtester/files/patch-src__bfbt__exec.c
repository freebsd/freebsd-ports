Index: src/bfbt/exec.c
===================================================================
RCS file: /cvsroot/bfbtester/bfbtester/src/bfbt/exec.c,v
retrieving revision 1.5
diff -u -r1.5 exec.c
--- src/bfbt/exec.c	2001/01/25 06:24:49	1.5
+++ src/bfbt/exec.c	2001/02/01 03:35:37
@@ -144,7 +144,8 @@
 	else if( WIFSIGNALED(entry->status) ){
 		/* we ignore SIGKILL and SIGPIPE */
 		if( WTERMSIG(entry->status) == SIGKILL
-			|| WTERMSIG(entry->status) == SIGPIPE){
+			|| WTERMSIG(entry->status) == SIGPIPE
+			|| WTERMSIG(entry->status) == SIGPROF){
 			return;
 		}
 		{
