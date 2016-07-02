--- sratool/print.c.orig	2016-06-29 19:21:44 UTC
+++ sratool/print.c
@@ -1202,7 +1202,7 @@ print_mgmt(axa_p_mgmt_t *mgmt, size_t mg
 	}
 
 	if (axa_debug != 0) {
-		printf("    mgmt_len       : %zdb\n", AXA_P2H32(mgmt_len));
+		printf("    mgmt_len       : %"PRIu32"\n", AXA_P2H32(mgmt_len));
 	}
 
 	/* UINT32_MAX or UINT64_MAX == server error in gathering stat */
