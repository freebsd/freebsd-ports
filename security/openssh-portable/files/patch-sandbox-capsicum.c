--- sandbox-capsicum.c.orig	2014-01-25 16:39:53.000000000 -0600
+++ sandbox-capsicum.c	2014-02-02 20:14:02.881233373 -0600
@@ -94,10 +94,12 @@ ssh_sandbox_child(struct ssh_sandbox *bo
 		fatal("can't limit stderr: %m");
 
 	cap_rights_init(&rights, CAP_READ, CAP_WRITE);
-	if (cap_rights_limit(box->monitor->m_recvfd, &rights) == -1)
+	if (cap_rights_limit(box->monitor->m_recvfd, &rights) == -1 &&
+	    errno != ENOSYS)
 		fatal("%s: failed to limit the network socket", __func__);
 	cap_rights_init(&rights, CAP_WRITE);
-	if (cap_rights_limit(box->monitor->m_log_sendfd, &rights) == -1)
+	if (cap_rights_limit(box->monitor->m_log_sendfd, &rights) == -1 &&
+	    errno != ENOSYS)
 		fatal("%s: failed to limit the logging socket", __func__);
 	if (cap_enter() < 0 && errno != ENOSYS)
 		fatal("%s: failed to enter capability mode", __func__);
