--- pim_proto.c.orig	2014-01-26 12:48:37.048478574 +0100
+++ pim_proto.c	2014-01-26 12:51:08.180470630 +0100
@@ -669,7 +669,7 @@
 			    "\tPRUNE src %s, group %s - scheduling delayed join",
 			    inet_fmt(source, s1), inet_fmt(group, s2));
 		    
-		    schedule_delayed_join(mrtentry_ptr, uni_target_addr);
+		    schedule_delayed_join(mrtentry_ptr, uni_target_addr.unicast_addr);
 		}
 	    }
 
