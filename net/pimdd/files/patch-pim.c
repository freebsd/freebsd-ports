--- pim.c.orig	Fri Sep 29 11:54:13 2006
+++ pim.c	Fri Sep 29 11:54:28 2006
@@ -257,7 +257,6 @@
     pim		       = (pim_header_t *)(buf + sizeof(struct ip));
     pim->pim_type      = type;
     pim->pim_vers       = PIM_PROTOCOL_VERSION;
-    pim->reserved      = 0;
     pim->pim_cksum     = 0;
    /* TODO: XXX: if start using this code for PIM_REGISTERS, exclude the
     * encapsulated packet from the checsum.
@@ -349,7 +348,6 @@
     pim		           = (pim_header_t *)(buf + sizeof(struct ip));
     pim->pim_vers           = PIM_PROTOCOL_VERSION;
     pim->pim_type          = type;
-    pim->reserved          = 0;
     pim->pim_cksum	   = 0;
 
     bzero((void *)&sdst, sizeof(sdst));
