--- server/dhcp.c.orig	Wed Feb 22 23:43:27 2006
+++ server/dhcp.c	Mon May 22 01:39:59 2006
@@ -2442,6 +2442,7 @@
 		offered_lease_time =
 			state -> offered_expiry - cur_time;
 
+		state -> expiry = 0;
 		putULong ((unsigned char *)&state -> expiry,
 			  (unsigned long)offered_lease_time);
 		i = DHO_DHCP_LEASE_TIME;
@@ -2452,7 +2453,7 @@
 		if (option_cache_allocate (&oc, MDL)) {
 			if (make_const_data (&oc -> expression,
 					     (unsigned char *)&state -> expiry,
-					     sizeof state -> expiry,
+					     4,
 					     0, 0, MDL)) {
 				oc -> option = dhcp_universe.options [i];
 				save_option (&dhcp_universe,
@@ -2463,6 +2464,7 @@
 
 		/* Renewal time is lease time * 0.5. */
 		offered_lease_time /= 2;
+		state -> renewal = 0;
 		putULong ((unsigned char *)&state -> renewal,
 			  (unsigned long)offered_lease_time);
 		i = DHO_DHCP_RENEWAL_TIME;
@@ -2474,7 +2476,7 @@
 			if (make_const_data (&oc -> expression,
 					     (unsigned char *)
 					     &state -> renewal,
-					     sizeof state -> renewal,
+					     4,
 					     0, 0, MDL)) {
 				oc -> option = dhcp_universe.options [i];
 				save_option (&dhcp_universe,
@@ -2486,6 +2488,7 @@
 		/* Rebinding time is lease time * 0.875. */
 		offered_lease_time += (offered_lease_time / 2
 				       + offered_lease_time / 4);
+		state -> rebind = 0;
 		putULong ((unsigned char *)&state -> rebind,
 			  (unsigned)offered_lease_time);
 		i = DHO_DHCP_REBINDING_TIME;
@@ -2496,7 +2499,7 @@
 		if (option_cache_allocate (&oc, MDL)) {
 			if (make_const_data (&oc -> expression,
 					     (unsigned char *)&state -> rebind,
-					     sizeof state -> rebind,
+					     4,
 					     0, 0, MDL)) {
 				oc -> option = dhcp_universe.options [i];
 				save_option (&dhcp_universe,
