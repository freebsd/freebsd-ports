--- ospfd/kroute.c.orig	Mon Nov 20 14:41:22 2006
+++ ospfd/kroute.c	Mon Nov 20 14:42:17 2006
@@ -875,10 +875,6 @@
 			send_rtmsg(kr_state.fd, RTM_DELETE, &kr->r);
 			free(kr);
 		} else {
-			if ((label = (struct sockaddr_rtlabel *)
-			    rti_info[RTAX_LABEL]) != NULL)
-				kr->r.rtlabel =
-				    rtlabel_name2id(label->sr_label);
 			kroute_insert(kr);
 		}
 
@@ -1075,10 +1071,6 @@
 
 				rtlabel_unref(kr->r.rtlabel);
 				kr->r.rtlabel = 0;
-				if ((label = (struct sockaddr_rtlabel *)
-				    rti_info[RTAX_LABEL]) != NULL)
-					kr->r.rtlabel =
-					    rtlabel_name2id(label->sr_label);
 
 				if (kif_validate(kr->r.ifindex))
 					kr->r.flags &= ~F_DOWN;
@@ -1098,11 +1090,6 @@
 				kr->r.nexthop.s_addr = nexthop.s_addr;
 				kr->r.flags = flags;
 				kr->r.ifindex = ifindex;
-
-				if ((label = (struct sockaddr_rtlabel *)
-				    rti_info[RTAX_LABEL]) != NULL)
-					kr->r.rtlabel =
-					    rtlabel_name2id(label->sr_label);
 
 				kroute_insert(kr);
 			}
