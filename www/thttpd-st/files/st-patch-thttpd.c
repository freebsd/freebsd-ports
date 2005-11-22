--- thttpd.c.orig	Thu Dec 25 22:06:52 2003
+++ thttpd.c	Wed Sep 21 22:30:25 2005
@@ -631,6 +631,7 @@
     watchdog_flag = 0;
     (void) alarm( OCCASIONAL_TIME * 3 );
 
+    st_init();
     /* Initialize the timer package. */
     tmr_init();
 
