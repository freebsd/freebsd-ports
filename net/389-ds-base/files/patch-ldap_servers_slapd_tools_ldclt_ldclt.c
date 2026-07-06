--- ldap/servers/slapd/tools/ldclt/ldclt.c.orig	2026-06-28 09:51:29 UTC
+++ ldap/servers/slapd/tools/ldclt/ldclt.c
@@ -821,13 +821,8 @@ initMainThread(void)
 /*
    * Trap SIGINT.
    */
-#ifdef LDCLT_CAST_SIGACTION                     /*JLS 01-12-00*/
-    act.sa_handler = (void (*)(int))trapVector; /*JLS 14-11-00*/
-#else                                           /*JLS 14-11-00*/
-    act.sa_handler = trapVector;
-#endif                                          /*JLS 14-11-00*/
     act.sa_sigaction = trapVector;
-    act.sa_flags = SA_NODEFER;
+    act.sa_flags = SA_NODEFER | SA_SIGINFO;
     sigemptyset(&(act.sa_mask));
     sigaddset(&(act.sa_mask), SIGINT);
     sigfillset(&(act.sa_mask));
@@ -841,13 +836,8 @@ initMainThread(void)
 /*
    * Trap SIGQUIT.
    */
-#ifdef LDCLT_CAST_SIGACTION                     /*JLS 01-12-00*/
-    act.sa_handler = (void (*)(int))trapVector; /*JLS 14-11-00*/
-#else                                           /*JLS 14-11-00*/
-    act.sa_handler = trapVector;
-#endif                                          /*JLS 14-11-00*/
     act.sa_sigaction = trapVector;
-    act.sa_flags = SA_NODEFER;
+    act.sa_flags = SA_NODEFER | SA_SIGINFO;
     sigemptyset(&(act.sa_mask));
     sigaddset(&(act.sa_mask), SIGQUIT);
     sigfillset(&(act.sa_mask));
