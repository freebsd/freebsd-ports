--- agent/mibgroup/mibII/udpTable.c.orig	Fri Nov 14 15:14:52 2003
+++ agent/mibgroup/mibII/udpTable.c	Fri Nov 14 15:18:08 2003
@@ -577,6 +577,7 @@
      *  Unpick this into the constituent 'xinpgen' structures, and extract
      *     the 'inpcb' elements into a linked list (built in reverse)
      */
+#if 0
     xig = (struct xinpgen *) udpcb_buf;
     xig = (struct xinpgen *) ((char *) xig + xig->xig_len);
 
@@ -584,12 +585,13 @@
         nnew = SNMP_MALLOC_TYPEDEF(struct inpcb);
         if (!nnew)
             break;
-        memcpy(nnew, ((struct xinpcb *) xig)->xi_inp, sizeof(struct inpcb));
+        memcpy(nnew, &((struct xinpcb *) xig)->xi_inp, sizeof(struct inpcb));
 
 	nnew->next = udp_head;		/* XXX - ?? Check 'next' pointer */
 	udp_head   = nnew;
         xig = (struct xinpgen *) ((char *) xig + xig->xig_len);
     }
+#endif
 
     free(udpcb_buf);
     if (udp_head) {
