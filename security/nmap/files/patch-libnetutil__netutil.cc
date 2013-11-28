PR: ports/184288
Fix security/nmap runtime on current (FreeBSD 11)
==========================================================================
--- ./libnetutil/netutil.cc.orig	2013-07-29 00:08:48.000000000 +0200
+++ ./libnetutil/netutil.cc	2013-11-25 21:26:22.000000000 +0100
@@ -1319,7 +1319,11 @@
     /* The first time through the loop we add the primary interface record.
        After that we add the aliases one at a time. */
     if (!primary_done) {
-      if (addr_ntos(&entry->intf_addr, (struct sockaddr *) &tmpss) == -1) {
+      if ( (addr_ntos(&entry->intf_addr, (struct sockaddr *) &tmpss) == -1)
+#ifdef AF_LINK
+              || (tmpss.ss_family == AF_LINK)
+#endif
+         ) {
         dcrn->ifaces[dcrn->numifaces].addr.ss_family = 0;
       } else {
         rc = canonicalize_address(&tmpss, &dcrn->ifaces[dcrn->numifaces].addr);
@@ -1328,7 +1332,11 @@
       dcrn->ifaces[dcrn->numifaces].netmask_bits = entry->intf_addr.addr_bits;
       primary_done = true;
     } else if (num_aliases_done < entry->intf_alias_num) {
-      if (addr_ntos(&entry->intf_alias_addrs[num_aliases_done], (struct sockaddr *) &tmpss) == -1) {
+      if ( (addr_ntos(&entry->intf_alias_addrs[num_aliases_done], (struct sockaddr *) &tmpss) == -1)
+#ifdef AF_LINK
+              || (tmpss.ss_family == AF_LINK)
+#endif
+         ) {
         dcrn->ifaces[dcrn->numifaces].addr.ss_family = 0;
       } else {
         rc = canonicalize_address(&tmpss, &dcrn->ifaces[dcrn->numifaces].addr);
