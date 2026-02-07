--- pim_proto.c.orig	1999-11-30 17:58:53 UTC
+++ pim_proto.c
@@ -669,7 +669,7 @@ receive_pim_join_prune(src, dst, pim_mes
 			    "\tPRUNE src %s, group %s - scheduling delayed join",
 			    inet_fmt(source, s1), inet_fmt(group, s2));
 		    
-		    schedule_delayed_join(mrtentry_ptr, uni_target_addr);
+		    schedule_delayed_join(mrtentry_ptr, uni_target_addr.unicast_addr);
 		}
 	    }
 
