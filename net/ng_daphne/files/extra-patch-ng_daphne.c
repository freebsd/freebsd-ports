--- ng_daphne.c.orig	Fri Feb 13 13:08:06 2004
+++ ng_daphne.c	Wed Jun  9 13:00:20 2004
@@ -108,7 +108,7 @@
 	  NGM_DAPHNE_COOKIE,
 	  NGM_DAPHNE_SET_ENADDR,
 	  "setenaddr",
-	  &ng_ether_enaddr_type,
+	  &ng_parse_enaddr_type,
 	  NULL
 	},
 	{
@@ -116,7 +116,7 @@
 	  NGM_DAPHNE_GET_ENADDR,
 	  "getenaddr",
 	  NULL,
-	  &ng_ether_enaddr_type
+	  &ng_parse_enaddr_type
 	},
 	{ 0 }
 };
@@ -126,18 +126,16 @@
  * Node type descriptor
  */
 static struct ng_type ng_daphne_typestruct = {
-	NG_ABI_VERSION,
-	NG_DAPHNE_NODE_TYPE,
-	NULL,
-	ng_daphne_constructor,
-	ng_daphne_rcvmsg,
-	ng_daphne_shutdown,
-	ng_daphne_newhook,
-	NULL,
-	ng_daphne_connect,
-	ng_daphne_rcvdata,
-	ng_daphne_disconnect,
-	ng_daphne_cmdlist,
+	.version =	NG_ABI_VERSION,
+	.name =		NG_DAPHNE_NODE_TYPE,
+	.constructor = 	ng_daphne_constructor,
+	.rcvmsg =	ng_daphne_rcvmsg,
+	.shutdown =	ng_daphne_shutdown,
+	.newhook =	ng_daphne_newhook,
+	.connect =	ng_daphne_connect,
+	.rcvdata =	ng_daphne_rcvdata,
+	.disconnect =	ng_daphne_disconnect,
+	.cmdlist =	ng_daphne_cmdlist,
 };
 
 NETGRAPH_INIT(daphne, &ng_daphne_typestruct);
@@ -311,22 +309,18 @@
 			/* The peer node is eiface. If we know out hardware address, let it know */
 			if (priv->myRowHead)
 			{
-				struct ng_eiface_par *eiAddr;
+				struct ether_addr *eiAddr;
 
-				NG_MKMESSAGE (msg, NGM_EIFACE_COOKIE, NGM_EIFACE_SET, sizeof (struct ng_eiface_par), M_NOWAIT);
+				NG_MKMESSAGE (msg, NGM_EIFACE_COOKIE, NGM_EIFACE_SET, sizeof (struct ether_addr), M_NOWAIT);
 
 				if (msg == NULL)
 					return (ENOMEM);
 
 				/* Fill up msg data */
-				eiAddr = (struct ng_eiface_par *)(msg->data);
+				eiAddr = (struct ether_addr *)(msg->data);
 
-				eiAddr->oct0 = priv->myRowHead->etherAddr[0];
-				eiAddr->oct1 = priv->myRowHead->etherAddr[1];
-				eiAddr->oct2 = priv->myRowHead->etherAddr[2];
-				eiAddr->oct3 = priv->myRowHead->etherAddr[3];
-				eiAddr->oct4 = priv->myRowHead->etherAddr[4];
-				eiAddr->oct5 = priv->myRowHead->etherAddr[5];
+				bcopy((void *)priv->myRowHead->etherAddr,
+				    (void *)&eiAddr, sizeof(struct ether_addr));
 
 				/* Send message to this node */
 				NG_SEND_MSG_ID (error, node, msg, NG_PEER_NODE(hook)->nd_ID, 0);
@@ -1208,7 +1202,7 @@
 					{
 						FREE_CHAIN (p_tempRowHead->neighbours, rtElem);
 						p_tempRowHead->neighbours = NULL;
-						p_tempRowHead->numNeighb = NULL;
+						p_tempRowHead->numNeighb = 0;
 						p_tempRowHead->routingSeqNum = 0;
 						p_tempRowHead->routingSeqNumTimer = 0;
 
