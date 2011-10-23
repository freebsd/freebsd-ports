--- ./entropy.c	2009-08-08 20:54:21.000000000 -0400
+++ ../../pam_ssh_agent_auth-0.9.3.fixed/entropy.c	2011-10-10 13:10:35.864389493 -0400
@@ -79,11 +79,11 @@
 	mysig_t old_sigchld;
 
 	if (RAND_status() == 1) {
-		verbose("RNG is ready, skipping seeding");
+		pam_ssh_auth_verbose("RNG is ready, skipping seeding");
 		return;
 	}
 
-	verbose("Seeding PRNG from %s", SSH_RAND_HELPER);
+	pam_ssh_auth_verbose("Seeding PRNG from %s", SSH_RAND_HELPER);
 
 	if ((devnull = open("/dev/null", O_RDWR)) == -1)
 		fatal("Couldn't open /dev/null: %s", strerror(errno));
@@ -187,7 +187,7 @@
 
 	buf = buffer_get_string_ret(m, &len);
 	if (buf != NULL) {
-		verbose("rexec_recv_rng_seed: seeding rng with %u bytes", len);
+		pam_ssh_auth_verbose("rexec_recv_rng_seed: seeding rng with %u bytes", len);
 		RAND_add(buf, len, len);
 	}
 }
