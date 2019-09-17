--- src/checks.c.orig	2019-09-17 10:00:12.658926000 +0000
+++ src/checks.c	2019-09-17 10:02:03.978010000 +0000
@@ -1447,12 +1447,8 @@ static int wake_srv_chk(struct conn_stream *cs)
 		ret = tcpcheck_main(check);
 		cs = check->cs;
 		conn = cs->conn;
-	} else {
-		if (!(check->wait_list.events & SUB_RETRY_SEND))
-			__event_srv_chk_w(cs);
-		if (!(check->wait_list.events & SUB_RETRY_RECV))
-			__event_srv_chk_r(cs);
-	}
+	} else if (!(check->wait_list.events & SUB_RETRY_SEND))
+		__event_srv_chk_w(cs);
 
 	if (unlikely(conn->flags & CO_FL_ERROR || cs->flags & CS_FL_ERROR)) {
 		/* We may get error reports bypassing the I/O handlers, typically
@@ -2262,9 +2258,7 @@ static struct task *process_chk_conn(struct task *t, v
 				 * sending since otherwise we won't be woken up.
 				 */
 				__event_srv_chk_w(cs);
-				if (!(conn->flags & CO_FL_WAIT_L4_CONN) ||
-				    !(check->wait_list.events & SUB_RETRY_SEND))
-					__event_srv_chk_r(cs);
+				__event_srv_chk_r(cs);
 			}
 
 			task_set_affinity(t, tid_bit);
