--- ./src/ng_netams.c	Fri Mar  4 04:38:52 2005
+++ ./src/ng_netams.c	Wed Jun 14 11:54:21 2006
@@ -438,7 +438,10 @@
 		} else 
 			prev=e;
 	}
-	if (data->debug) printf("callout/%u%c active %u, checked %u, queued=%u, flushed %u\n", time_second, data->daemon_node?'+':'-', data->active_flows, t_active, f_queued, f_active);
+	if (data->debug)
+		printf("callout/%lu%c active %u, checked %u, queued=%u, flushed %u\n",
+			(u_long)time_second, data->daemon_node?'+':'-',
+			data->active_flows, t_active, f_queued, f_active);
 	mtx_unlock(&data->mtx_active);
 
 	if (data->daemon_node!=0 && time_second%10==0) { // time to send info to daemon
@@ -446,7 +449,9 @@
 		msg->header.token=data->daemon_cookie;
 		ng_netams_set_info(msg, data);
 		NG_SEND_MSG_ID(error, data->node, msg, data->daemon_node, NG_NODE_ID(data->node));
-		if (data->debug) printf("info/%u: sent to daemon [%u] with error=%u\n", time_second, data->daemon_node, error);
+		if (data->debug)
+			printf("info/%lu: sent to daemon [%u] with error=%u\n",
+				(u_long)time_second, data->daemon_node, error);
 		if (error) { data->daemon_cookie=data->daemon_node=0; } // something went wrong, reset userspace destination to prevent further loss
 	}
 
