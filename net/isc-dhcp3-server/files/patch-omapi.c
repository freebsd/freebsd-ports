--- server/omapi.c.orig	Sat Apr 27 07:16:35 2002
+++ server/omapi.c	Fri May 10 06:10:54 2002
@@ -245,7 +245,7 @@
 		lease -> next_binding_state = bar;
 		if (supersede_lease (lease, 0, 1, 1, 1)) {
 			log_info ("lease %d state changed from %s to %s",
-				  ols, nls);
+				  piaddr (lease -> ip_addr), ols, nls);
 			return ISC_R_SUCCESS;
 		}
 		log_info ("lease state change from %s to %s failed.",
