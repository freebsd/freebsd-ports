--- agent/mibgroup/udp-mib/data_access/udp_endpoint_freebsd4.c.orig	2014-12-08 12:23:22.000000000 -0800
+++ agent/mibgroup/udp-mib/data_access/udp_endpoint_freebsd4.c	2017-04-07 16:05:05.752849000 -0700
@@ -153,7 +153,11 @@
 #endif
 
 #if !defined(NETSNMP_ENABLE_IPV6)
+#if __FreeBSD_version >= 1200026
+	if (pcb.inp_vflag & INP_IPV6)
+#else
         if (pcb.xi_inp.inp_vflag & INP_IPV6)
+#endif
 	    continue;
 #endif
 
@@ -164,9 +168,24 @@
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
 	if (pcb.xi_inp.inp_vflag & INP_IPV6) {
@@ -179,6 +198,8 @@
 	    memcpy(entry->loc_addr, &pcb.xi_inp.inp_laddr, 4);
 	    memcpy(entry->rmt_addr, &pcb.xi_inp.inp_faddr, 4);
 	}
+#endif
+        entry->pid = 0;
 
         /*
          * add entry to container
@@ -187,6 +208,8 @@
         CONTAINER_INSERT(container, entry);
     }
 
+    free(udpcb_buf);
+
     if(rc<0)
         return rc;
 
