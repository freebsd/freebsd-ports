Obtained from:	https://github.com/Ettercap/ettercap/commit/42600aada0ba56b9c63dabcc2b0cb1417fa27863

--- src/ec_utils.c.orig	2014-10-17 01:29:44.000000000 +0800
+++ src/ec_utils.c	2015-02-21 19:58:20.735805931 +0800
@@ -225,17 +225,19 @@
    else
       gid = GBL_CONF->ec_gid;
 
-   DEBUG_MSG("drop_privs: setuid(%d) setgid(%d)", uid, gid);
+   reset_logfile_owners(geteuid(), getegid(), uid, gid);
+
+   DEBUG_MSG("drop_privs: seteuid(%d) setegid(%d)", uid, gid);
 
    /* drop to a good uid/gid ;) */
-   if ( setgid(gid) < 0 )
-      ERROR_MSG("setgid()");
+   if ( setegid(gid) < 0 )
+      ERROR_MSG("setegid()");
 
    if ( seteuid(uid) < 0 )
       ERROR_MSG("seteuid()");
 
    DEBUG_MSG("privs: UID: %d %d  GID: %d %d", (int)getuid(), (int)geteuid(), (int)getgid(), (int)getegid() );
-   USER_MSG("Privileges dropped to UID %d GID %d...\n\n", (int)getuid(), (int)getgid() );
+   USER_MSG("Privileges dropped to EUID %d EGID %d...\n\n", (int)geteuid(), (int)getegid() );
 }
 
 /* base64 stuff */
