--- sandbox-capsicum.c.orig	2015-07-18 20:23:31 UTC
+++ sandbox-capsicum.c
@@ -39,10 +39,13 @@ ksandbox_capsicum_init_child(void *arg, 
 
 	cap_rights_init(&rights);
 
-	if (cap_rights_limit(STDIN_FILENO, &rights) < 0 && errno != ENOSYS)
+	cap_rights_init(&rights, CAP_READ|CAP_FSTAT);
+	/* Test for EBADF because STDIN_FILENO can be close in fcgi */
+	if (cap_rights_limit(STDIN_FILENO, &rights) < 0 && errno != ENOSYS &&
+	    errno != EBADF)
 		XWARN("cap_rights_limit: STDIN_FILENO");
 
-	cap_rights_init(&rights, CAP_WRITE);
+	cap_rights_init(&rights, CAP_WRITE|CAP_FSTAT);
 	if (cap_rights_limit(STDOUT_FILENO, &rights) < 0 && errno != ENOSYS)
 		XWARN("cap_rights_limit: STDOUT_FILENO");
 	if (cap_rights_limit(STDERR_FILENO, &rights) < 0 && errno != ENOSYS)
