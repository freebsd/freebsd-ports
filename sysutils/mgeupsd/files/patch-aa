--- mgeupsd.c.old	Sat Dec 26 02:42:52 1998
+++ mgeupsd.c	Sat Mar 17 23:59:09 2001
@@ -33,9 +33,9 @@
 #define BS_TDP 12
 
 /* status file for init */
-#define PWRFILE "/etc/powerstatus"
+#define PWRFILE "/var/run/powerstatus"
 /* Linux usual */
-#define LOCKDIR "/var/lock"
+#define LOCKDIR "/var/run"
 #define RUNDIR	"/var/run"
 char lockfile[40] = {0,};
 char pidfile[40] = {0,};
@@ -640,7 +640,7 @@
 		  else
 		    {
 #ifndef TEST
-		      if (kill (init_pid, SIGPWR))
+		      if (kill (init_pid, SIGUSR2))
 			syslog (LOG_CRIT, "Process %u doesn not exist! Can't send SIGPWR", init_pid);
 #endif
 		    }
@@ -677,7 +677,7 @@
 		      else
 			{
 #ifndef TEST
-			  if (kill (init_pid, SIGPWR))
+			  if (kill (init_pid, SIGINT))
 			    syslog (LOG_CRIT, "Process %u doesn not exist! Can't send SIGPWR", init_pid);
 #endif
 			}
@@ -711,7 +711,7 @@
 		  else
 		    {
 #ifndef TEST
-		      if (kill (init_pid, SIGPWR))
+		      if (kill (init_pid, SIGHUP))
 			syslog (LOG_CRIT, "Process %u doesn not exist! Can't send SIGPWR", init_pid);
 #endif
 		    }
@@ -758,4 +758,5 @@
 	    }
 	}			/* while(1) */
     }
+  return 0;
 }
