--- popd.c.orig	Tue Apr 17 05:09:26 2001
+++ popd.c	Wed May 16 09:00:39 2001
@@ -501,6 +503,7 @@
 	closesigpipe();
 	opensigpipe();
 	setsignals();
+	facility = LOG_INFO;
 	if (config.daemonise || config.debug)
 		getnameinfo((struct sockaddr *)&addr, addr.ss_len,
 			    ip, sizeof(ip), NULL, 0,
@@ -518,6 +521,8 @@
 	sendline("+OK %s ready %s", IDENT, config.timestamp);
 	switch (authenticate(&user)) {
 		case TRUE:
+			syslog(facility, "Login user=%s host=[%s]",
+			    user->username, ip);
 			if (!config.proxy)
 				transaction(user);
 			else
