--- util.c.orig	Tue Aug 26 10:53:17 2003
+++ util.c	Thu Dec 28 13:31:06 2006
@@ -275,6 +275,8 @@
 	if (method->address) free(method->address);
 	if (method->sd) session_free(method->sd);
 	if (method->chatscript) free_chatscript(method->chatscript);
+	if (method->when) free(method->when);
+	if (method->when_fmt) free(method->when_fmt);
 	if (method->snmpreq) {
 		free_var_ref(method->snmpreq->var_ref);
 		free(method->snmpreq);
@@ -1236,11 +1238,9 @@
 		if (method->address)
 			printf("%s\tAddress = \"%s\" [%s]\n", prepend,
 			       method->address, intoa(ipaddr, method->ip_addr));
-		if ((proto = getprotobynumber(method->protocol)) == NULL) {
-			printf("%s\tUnknown protocol %d\n", prepend, method->protocol);
-			continue;
+		if ((proto = getprotobynumber(method->protocol)) != NULL) {
+		    printf("%s\t%s ", prepend, proto->p_name);
 		}
-		printf("%s\t%s ", prepend, proto->p_name);
 		switch (method->protocol) {
 		case IPPROTO_ICMP:
 			if (method->rport)
@@ -1265,6 +1265,14 @@
 				printf("..%d", method->lport_max);
 			}
 			break;
+		case WHEN_PROTO:
+			printf("%s\tWHEN = \"%s\"",prepend, method->when);
+			printf(" delay = %d sec.", method->timeout);
+			printf(" Report Format = \"%s\"", method->when_fmt);
+			break;
+		case PIPE_PROTO:
+			printf("%s\tPIPE programm = \"%s\"",prepend, method->when);
+			break;
 		default:
 			printf("Unsupported");
 		}
@@ -1409,22 +1417,36 @@
 	if (cf->saving > 0)
 		printf("Saving = %d sec.\n", cf->saving);
 	else	printf("Saving disabled\n");
+	if (cf->compatibility_flag > 0)
+		printf("Compatibility flag SET\n");
+	else 	printf("Compatibility flag NOT SET\n");
 
 	print_group_list("", cf->group_list);
 
 	printf("NetState %s\n", cf->ns_port ? "enabled" : "disabled");
 	if (cf->ns_port) {
 		printf("\tPort = %d\n", cf->ns_port);
+		if (cf->ns_address) 
+    		    printf("\tBindAddress = \"%s\" [%s]\n", cf->ns_address, intoa(ipaddr, cf->ns_ip_addr));		
 #ifndef	HAVE_PTHREAD
 		printf("\tTimeout = %d sec.\n", cf->ns_timo);
 #endif
 		print_group_ref("\t", cf->ns_acl);
 	}
+	printf("SrcAddress = \"%s\" [%s]\n", (cf->srcaddress!=NULL ) ? cf->srcaddress : "default",
+	    intoa(ipaddr, cf->ip_srcaddr));
+
+	printf("UserName = \"%s\" [%d]\n", cf->username, cf->uid);
+	printf("GroupName = \"%s\" [%d]\n", cf->groupname, cf->gid);
 
+	if (cf->chrootdir) 
+	    printf("ChRootDir = \"%s\"\n", cf->chrootdir );
 	printf("Traps ");
 	if (cf->enable_traps > 0) {
 		printf("enabled");
 		if (cf->source_traps > 0) printf(" (sourcecheck)");
+		if (cf->trap_address) 
+		    printf("\n\tTrapBindAddress = \"%s\" [%s]", cf->trap_address, intoa(ipaddr, cf->trap_ip_addr));		
 	} else	printf("disabled");
 	printf("\n");
 
@@ -1434,6 +1456,8 @@
 			printf("\tDescription = \"%s\"\n", target->descr);
 		printf("\tAddress = \"%s\" [%s]\n", target->address,
 		       intoa(ipaddr, target->ip_addr));
+		printf("\tSrcAddress = \"%s\" [%s]\n", (target->srcaddress!=NULL) ? target->srcaddress : "default",
+		       intoa(ipaddr, target->ip_srcaddr));
 		if (target->polling > 0)
 			printf("\tPolling = %d sec.\n", target->polling);
 		else	printf("\tPolling disabled\n");
@@ -1463,6 +1487,8 @@
 			if (iface->ns_acl)
 				print_group_ref("\t\tNetState ", iface->ns_acl);
 			else	printf("\t\tNetState Group = free access\n");
+			if (iface->ignore_state)
+				printf("\t\tIgnoreState flag set.\n");			
 			print_var_list("\t\t", iface->var_list);
 			print_save_list("\t\t", iface->save_list);
 		}
@@ -1475,6 +1501,8 @@
 			if (iface->ns_acl)
 				print_group_ref("\t\tNetState ", iface->ns_acl);
 			else	printf("\t\tNetState Group = free access\n");
+			if (iface->ignore_state)
+				printf("\t\tIgnoreState flag set.\n");			
 			print_var_list("\t\t", iface->var_list);
 			print_save_list("\t\t", iface->save_list);
 		}
@@ -1495,6 +1523,8 @@
 			if (bgp->ns_acl)
 				print_group_ref("\t\tNetState ", bgp->ns_acl);
 			else	printf("\t\tNetState Group = free access\n");
+			if (bgp->ignore_state)
+				printf("\t\tIgnoreState flag set.\n");			
 			print_save_list("\t\t", bgp->save_list);
 		}
 
@@ -1514,6 +1544,8 @@
 			if (env->ns_acl)
 				print_group_ref("\t\tNetState ", env->ns_acl);
 			else	printf("\t\tNetState Group = free access\n");
+			if (env->ignore_state)
+				printf("\t\tIgnoreState flag set.\n");			
 			print_save_list("\t\t", env->save_list);
 		}
 
@@ -1524,6 +1556,8 @@
 			if (service->ns_acl)
 				print_group_ref("\t\tNetState ", service->ns_acl);
 			else	printf("\t\tNetState Group = free access\n");
+			if (service->ignore_state)
+				printf("\t\tIgnoreState flag set.\n");			
 			print_var_list("\t\t", service->var_list);
 			print_method_list("\t\t", service->method_list);
 			print_trap_list("\t\t", service->trap_list);
