--- agent/snmpd.c.orig	2009-01-25 17:25:26.000000000 +0900
+++ agent/snmpd.c	2009-01-25 17:36:52.000000000 +0900
@@ -426,6 +426,9 @@
     char           *cptr, **argvptr;
     char           *pid_file = NULL;
     char            option_compatability[] = "-Le";
+#if HAVE_UNISTD_H
+    const char     *ccptr;
+#endif
 #if HAVE_GETPID
     int fd;
     FILE           *PID;
@@ -960,8 +963,8 @@
 #endif
 
 #if HAVE_UNISTD_H
-    cptr = get_persistent_directory();
-    mkdirhier( cptr, NETSNMP_AGENT_DIRECTORY_MODE, 0 );
+    ccptr = get_persistent_directory();
+    mkdirhier( ccptr, NETSNMP_AGENT_DIRECTORY_MODE, 0 );
    
     uid = netsnmp_ds_get_int(NETSNMP_DS_APPLICATION_ID, 
 			     NETSNMP_DS_AGENT_USERID);
@@ -970,7 +973,7 @@
     
 #ifdef HAVE_CHOWN
     if ( uid != 0 || gid != 0 )
-        chown( cptr, uid, gid );
+        chown( ccptr, uid, gid );
 #endif
 
 #ifdef HAVE_SETGID
