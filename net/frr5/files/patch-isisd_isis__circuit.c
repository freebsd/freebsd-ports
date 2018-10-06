From d4670f515b7f62bfd8f9bdd750540245aab542c0 Mon Sep 17 00:00:00 2001
From: Christian Franke <chris@opensourcerouting.org>
Date: Tue, 17 Jul 2018 15:14:54 -0400
Subject: [PATCH] isisd: don't crash when isis_sock_init fails

When isis_sock_init fails in isis_circuit_up, isis_circuit_down would
be called to cancel timers which were scheduled. However
isis_circuit_down would immediately return, since the state had not been
changed to 'UP' yet.

Fix this by having isis_circuit_down always cancel all the timers.

Signed-off-by: Christian Franke <chris@opensourcerouting.org>
--- isisd/isis_circuit.c.orig	2018-07-05 07:40:17 UTC
+++ isisd/isis_circuit.c
@@ -638,7 +638,7 @@ int isis_circuit_up(struct isis_circuit *circuit)
 			thread_add_timer(master, isis_run_dr_l2, circuit,
 					 2 * circuit->hello_interval[1],
 					 &circuit->u.bc.t_run_dr[1]);
-	} else {
+	} else if (circuit->circ_type == CIRCUIT_T_P2P) {
 		/* initializing the hello send threads
 		 * for a ptp IF
 		 */
@@ -682,9 +682,6 @@ int isis_circuit_up(struct isis_circuit *circuit)
 
 void isis_circuit_down(struct isis_circuit *circuit)
 {
-	if (circuit->state != C_STATE_UP)
-		return;
-
 	/* Clear the flags for all the lsps of the circuit. */
 	isis_circuit_update_all_srmflags(circuit, 0);
 
@@ -756,10 +753,12 @@ void isis_circuit_down(struct isis_circuit *circuit)
 	}
 
 	/* send one gratuitous hello to spead up convergence */
-	if (circuit->is_type & IS_LEVEL_1)
-		send_hello(circuit, IS_LEVEL_1);
-	if (circuit->is_type & IS_LEVEL_2)
-		send_hello(circuit, IS_LEVEL_2);
+	if (circuit->state == C_STATE_UP) {
+		if (circuit->is_type & IS_LEVEL_1)
+			send_hello(circuit, IS_LEVEL_1);
+		if (circuit->is_type & IS_LEVEL_2)
+			send_hello(circuit, IS_LEVEL_2);
+	}
 
 	circuit->upadjcount[0] = 0;
 	circuit->upadjcount[1] = 0;
