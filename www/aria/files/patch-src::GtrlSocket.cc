--- src/CtrlSocket.cc.orig	2002-10-01 17:32:00.000000000 +0200
+++ src/CtrlSocket.cc	2004-01-10 02:13:30.000000000 +0100
@@ -183,7 +183,7 @@
     stored_uid = getuid();
     euid = geteuid();
     setuid(euid);
-    sprintf(saddr.sun_path, "%s/aria_%s.%d", g_get_tmp_dir(), g_get_user_name(), session);
+    snprintf(saddr.sun_path, sizeof(saddr.sun_path)-1, "%s/aria_%s.%d", g_get_tmp_dir(), g_get_user_name(), session);
     setreuid(stored_uid, euid);
     if (connect(fd, (struct sockaddr *) &saddr, sizeof (saddr)) != -1)
       return fd;
