--- mibs/bgp4_mib_1657_bgp4pathattrtable.cc.orig	2009-01-05 18:31:00.000000000 +0000
+++ mibs/bgp4_mib_1657_bgp4pathattrtable.cc	2011-12-27 03:17:03.000000000 +0000
@@ -139,7 +139,7 @@
 	    DEBUGMSGTL((BgpMib::the_instance().name(),
 		"updating local bgp4PathAttrTable...\n"));
 	    DEBUGMSGTL((BgpMib::the_instance().name(),
-		"local table size: %d\n", CONTAINER_SIZE(cb.container)));
+		"local table size: %zd\n", CONTAINER_SIZE(cb.container)));
 	    bgp_mib.send_get_v4_route_list_start("bgp", net, true, false,
 			     callback(get_v4_route_list_start_done));
 	    break;
@@ -156,12 +156,12 @@
 	    DEBUGMSGTL((BgpMib::the_instance().name(),
 		"removing old routes from bgp4PathAttrTable...\n"));
 	    DEBUGMSGTL((BgpMib::the_instance().name(),
-		"local table size: %d old_routes stack: %d\n", 
+		"local table size: %zd old_routes stack: %zd\n", 
 		CONTAINER_SIZE(cb.container), update.old_routes.size()));
 	    CONTAINER_FOR_EACH(cb.container, find_old_routes, NULL);
 	    while (update.old_routes.size()) {  
 		DEBUGMSGTL((BgpMib::the_instance().name(),
-		    "update.old_routes.size() = %d\n", 
+		    "update.old_routes.size() = %zd\n", 
 		    update.old_routes.size()));
 	        row = (bgp4PathAttrTable_context*) 
 		    CONTAINER_FIND(cb.container, &update.old_routes.top());	
@@ -745,7 +745,7 @@
 
     if (row->update_signature != (update.list_token)) {
         DEBUGMSGTL((BgpMib::the_instance().name(),
-	    "removing %#010x from table\n", row->bgp4PathAttrIpAddrPrefix));
+	    "removing %#010lx from table\n", row->bgp4PathAttrIpAddrPrefix));
 	update.old_routes.push(row->index); 
     }
 }
