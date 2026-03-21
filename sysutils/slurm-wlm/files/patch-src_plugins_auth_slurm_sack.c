--- src/plugins/auth/slurm/sack.c.orig	2026-01-15 20:26:01 UTC
+++ src/plugins/auth/slurm/sack.c
@@ -43,6 +43,7 @@
 #include "slurm/slurm.h"
 #include "slurm/slurm_errno.h"
 #include "src/common/slurm_xlator.h"
+#include "src/common/slurm_sockaddr.h"
 
 #include "src/common/env.h"
 #include "src/common/fd.h"
@@ -299,6 +300,7 @@ extern void init_sack_conmgr(void)
 		char *runtime_dir = NULL, *runtime_socket = NULL;
 		slurm_addr_t addr = {0};
 		mode_t mask;
+		socklen_t bind_len = 0;
 
 		if (running_in_slurmctld()) {
 			_prepare_run_dir("slurmctld", true);
@@ -337,9 +339,9 @@ extern void init_sack_conmgr(void)
 		/* set value of socket path */
 		mask = umask(0);
 
-		/* bind() will EINVAL if socklen=sizeof(addr) */
-		if ((rc = bind(sack_fd, (const struct sockaddr *) &addr,
-			       sizeof(struct sockaddr_un))))
+		bind_len = slurm_sockaddr_fixlen((struct sockaddr *)&addr,
+						 sizeof(struct sockaddr_un));
+		if ((rc = bind(sack_fd, (const struct sockaddr *) &addr, bind_len)))
 			fatal("%s: [%pA] Unable to bind UNIX socket: %m",
 			      __func__, &addr);
 		umask(mask);
