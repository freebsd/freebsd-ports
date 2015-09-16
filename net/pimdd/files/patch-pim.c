--- pim.c.orig	1999-11-30 17:58:53 UTC
+++ pim.c
@@ -257,7 +257,6 @@ send_pim(buf, src, dst, type, datalen)
     pim		       = (pim_header_t *)(buf + sizeof(struct ip));
     pim->pim_type      = type;
     pim->pim_vers       = PIM_PROTOCOL_VERSION;
-    pim->reserved      = 0;
     pim->pim_cksum     = 0;
    /* TODO: XXX: if start using this code for PIM_REGISTERS, exclude the
     * encapsulated packet from the checsum.
@@ -349,7 +348,6 @@ send_pim_unicast(buf, src, dst, type, da
     pim		           = (pim_header_t *)(buf + sizeof(struct ip));
     pim->pim_vers           = PIM_PROTOCOL_VERSION;
     pim->pim_type          = type;
-    pim->reserved          = 0;
     pim->pim_cksum	   = 0;
 
     bzero((void *)&sdst, sizeof(sdst));
