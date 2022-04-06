--- mgeupsd.c.orig	1998-12-26 10:42:52 UTC
+++ mgeupsd.c
@@ -33,9 +33,9 @@ int RTS = TIOCM_RTS, use_syslog = 0;
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
@@ -640,7 +640,7 @@ operate:
 		  else
 		    {
 #ifndef TEST
-		      if (kill (init_pid, SIGPWR))
+		      if (kill (init_pid, SIGUSR2))
 			syslog (LOG_CRIT, "Process %u doesn not exist! Can't send SIGPWR", init_pid);
 #endif
 		    }
@@ -677,7 +677,7 @@ operate:
 		      else
 			{
 #ifndef TEST
-			  if (kill (init_pid, SIGPWR))
+			  if (kill (init_pid, SIGINT))
 			    syslog (LOG_CRIT, "Process %u doesn not exist! Can't send SIGPWR", init_pid);
 #endif
 			}
@@ -711,7 +711,7 @@ operate:
 		  else
 		    {
 #ifndef TEST
-		      if (kill (init_pid, SIGPWR))
+		      if (kill (init_pid, SIGHUP))
 			syslog (LOG_CRIT, "Process %u doesn not exist! Can't send SIGPWR", init_pid);
 #endif
 		    }
@@ -758,4 +758,5 @@ operate:
 	    }
 	}			/* while(1) */
     }
+  return 0;
 }
