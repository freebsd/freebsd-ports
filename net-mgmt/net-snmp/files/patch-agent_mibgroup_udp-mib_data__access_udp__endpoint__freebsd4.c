--- agent/mibgroup/udp-mib/data_access/udp_endpoint_freebsd4.c.orig	2018-07-16 14:33:40 UTC
+++ agent/mibgroup/udp-mib/data_access/udp_endpoint_freebsd4.c
@@ -168,9 +168,24 @@ _load(netsnmp_container *container, u_int load_flags)
         }
 
         /** oddly enough, these appear to already be in network order */
+#if __FreeBSD_version >= 1200026
+        entry->loc_port = htons(pcb.inp_lport);
+        entry->rmt_port = htons(pcb.inp_fport);
+        
+        /** the addr string may need work */
+	if (pcb.inp_vflag & INP_IPV6) {
+	    entry->loc_addr_len = entry->rmt_addr_len = 16;
+	    memcpy(entry->loc_addr, &pcb.in6p_laddr, 16);
+	    memcpy(entry->rmt_addr, &pcb.in6p_faddr, 16);
+	}
+	else {
+	    entry->loc_addr_len = entry->rmt_addr_len = 4;
+	    memcpy(entry->loc_addr, &pcb.inp_laddr, 4);
+	    memcpy(entry->rmt_addr, &pcb.inp_faddr, 4);
+	}
+#else
         entry->loc_port = htons(pcb.xi_inp.inp_lport);
         entry->rmt_port = htons(pcb.xi_inp.inp_fport);
-        entry->pid = 0;
         
         /** the addr string may need work */
 #ifdef INP_ISIPV6
@@ -187,6 +202,8 @@ _load(netsnmp_container *container, u_int load_flags)
 	    memcpy(entry->loc_addr, &pcb.xi_inp.inp_laddr, 4);
 	    memcpy(entry->rmt_addr, &pcb.xi_inp.inp_faddr, 4);
 	}
+#endif
+        entry->pid = 0;
 
         /*
          * add entry to container
@@ -194,6 +211,8 @@ _load(netsnmp_container *container, u_int load_flags)
 	entry->index = CONTAINER_SIZE(container) + 1;
         CONTAINER_INSERT(container, entry);
     }
+
+    free(udpcb_buf);
 
     free(udpcb_buf);
 
