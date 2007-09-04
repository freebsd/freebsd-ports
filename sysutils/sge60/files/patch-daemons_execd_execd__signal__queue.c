
$FreeBSD$

--- daemons/execd/execd_signal_queue.c.orig
+++ daemons/execd/execd_signal_queue.c
@@ -542,11 +542,11 @@
    ** execd.uid==0 && execd.euid==admin_user
    **    => kill does neither send SIGCONT-signals nor return an error
    */
-#if defined(NECSX4) || defined(NECSX5) || defined(DARWIN)
+#if defined(NECSX4) || defined(NECSX5) || defined(DARWIN) || defined(FREEBSD)
    sge_switch2start_user();
 #endif    
    if (kill(pid, direct_signal?sig:SIGTTIN)) {
-#if defined(NECSX4) || defined(NECSX5) || defined(DARWIN)
+#if defined(NECSX4) || defined(NECSX5) || defined(DARWIN) || defined(FREEBSD)
       sge_switch2admin_user();
 #endif   
       if (errno == ESRCH)
@@ -554,7 +554,7 @@
       DEXIT; 
       return -1;
    }
-#if defined(NECSX4) || defined(NECSX5)
+#if defined(NECSX4) || defined(NECSX5) || defined(FREEBSD)
    sge_switch2admin_user();
 #endif 
    
