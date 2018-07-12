--- ospf6d/ospf6_top.c.orig	2018-07-12 06:58:31 UTC
+++ ospf6d/ospf6_top.c
@@ -363,18 +363,12 @@ DEFUN(no_ospf6_router_id,
 	return CMD_SUCCESS;
 }
 
-#if CONFDATE > 20180828
-CPP_NOTICE("ospf6: `router-id A.B.C.D` deprecated 2017/08/28")
-#endif
 ALIAS_HIDDEN(ospf6_router_id,
 	     ospf6_router_id_hdn_cmd,
 	     "router-id A.B.C.D",
 	     "Configure OSPF6 Router-ID\n"
 	     V4NOTATION_STR)
 
-#if CONFDATE > 20180828
-CPP_NOTICE("ospf6: `no router-id A.B.C.D` deprecated 2017/08/28")
-#endif
 ALIAS_HIDDEN(no_ospf6_router_id,
 	     no_ospf6_router_id_hdn_cmd,
 	     "no router-id [A.B.C.D]",
