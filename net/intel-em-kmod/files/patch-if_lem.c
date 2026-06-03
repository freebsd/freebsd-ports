--- if_lem.c.orig	2026-05-24 15:03:45.830943000 +0700
+++ if_lem.c	2026-05-24 15:06:00.908555000 +0700
@@ -1483,11 +1483,8 @@ lem_irq_fast(void *arg)
 lem_irq_fast(void *arg)
 {
 	struct adapter	*adapter = arg;
-	if_t ifp;
 	u32		reg_icr;
 
-	ifp = adapter->ifp;
-
 	reg_icr = E1000_READ_REG(&adapter->hw, E1000_ICR);
 
 	/* Hot eject?  */
