--- src/bgp/bgp.c.orig	2022-05-28 08:30:21 UTC
+++ src/bgp/bgp.c
@@ -830,9 +830,9 @@ void skinny_bgp_daemon_online()
 		bgp_peer_close(&peers[peers_check_idx], FUNC_TYPE_BGP, FALSE, FALSE, FALSE, FALSE, NULL);
 	      }
 	      else {
-		Log(LOG_WARNING, "WARN ( %s/%s ): [%s] Refusing new connection from existing peer (residual holdtime: %ld).\n",
+		Log(LOG_WARNING, "WARN ( %s/%s ): [%s] Refusing new connection from existing peer (residual holdtime: %lld).\n",
 			config.name, bgp_misc_db->log_str, bgp_peer_str,
-			(peers[peers_check_idx].ht - ((long)now - peers[peers_check_idx].last_keepalive)));
+			(long long)(peers[peers_check_idx].ht - ((long)now - peers[peers_check_idx].last_keepalive)));
 		FD_CLR(peer->fd, &bkp_read_descs);
 		bgp_peer_close(peer, FUNC_TYPE_BGP, FALSE, FALSE, FALSE, FALSE, NULL);
 		goto read_data;
