--- bin/smtp-vilter/smtp-vilter.c.orig	Wed Dec 24 16:14:20 2003
+++ bin/smtp-vilter/smtp-vilter.c	Sat Jan 17 16:28:34 2004
@@ -1008,7 +1008,7 @@
 	/* Load the backends */
 
 	for (n = 0; n < nbe; n++) {
-		snprintf(libname, sizeof(libname), "lib%s.so.%d.%d", be[n].name, MAJOR, MINOR);
+		snprintf(libname, sizeof(libname), "lib%s.so.%d", be[n].name, MAJOR);
 
 		if ((be[n].dlhandle = dlopen(libname, RTLD_LAZY)) == NULL)
 			errx(1, "error loading backend %s (%s), %s", be[n].name, libname, dlerror());
@@ -1114,14 +1114,6 @@
 			err(1, "can't chdir to / after chroot to %s", chrootdir);
 	}
 
-	/* Change the user and group id */
-	
-	setgid(gid);
-	setuid(uid);
-		
-	if (!getuid() || !getgid())
-		errx(1, "must not be run as root");
-	
 	syslog(LOG_INFO, "dropped privileges, running as %d:%d", uid, gid);
 	
 	/* Initialize sendmail milter */
@@ -1150,8 +1142,6 @@
 	if (smfi_register(desc) == MI_FAILURE)
 		errx(1, "failed to register with sendmail");	
 		
-	smfi_setconn(port);
-	
 	if (!stat(pidfile, &statbuf))
 		errx(1, "pid file %s exists, another copy running?", pidfile);
 	
@@ -1167,6 +1157,16 @@
 		err(1, "can't write pid to pidfile %s", pidfile);
 	if (fclose(fp))
 		err(1, "error closing pidfile %s", pidfile);
+
+	/* Change the user and group id */
+	
+	setgid(gid);
+	setuid(uid);
+
+	smfi_setconn(port);
+		
+	if (!getuid() || !getgid())
+		errx(1, "must not be run as root");
 	
 	if (smfi_main() == MI_FAILURE)
 		syslog(LOG_ERR, "failed to establish a connection on port %s", port);
