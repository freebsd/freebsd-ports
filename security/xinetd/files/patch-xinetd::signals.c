--- xinetd/signals.c.orig	Sun May  4 04:56:37 2003
+++ xinetd/signals.c	Sun May  4 04:57:19 2003
@@ -353,7 +353,7 @@
 
       switch (sig) {
          case SIGSEGV:
-            switch (siginfo->si_code) {
+/*            switch (siginfo->si_code) {
                case SEGV_MAPERR:
                   msg(LOG_CRIT, func, "address is not mapped for object");
                   break;
@@ -361,13 +361,13 @@
                   msg(LOG_CRIT, func, 
 			     "invalid permissions for mapped object");
                   break;
-               default:
+               default:*/
                   msg(LOG_CRIT, func, "unknown fault code");
-            }
+           // }
             break;
 
          case SIGBUS:
-            switch(siginfo->si_code) {
+/*            switch(siginfo->si_code) {
                case BUS_ADRALN:
                   msg(LOG_CRIT, func, "invalid address alignment");
                   break;
@@ -377,9 +377,9 @@
                case BUS_OBJERR:
                   msg(LOG_CRIT, func, "object-specific hardware error");
                   break;
-               default:
+               default:*/
                   msg(LOG_CRIT, func, "unknown fault code");
-            }
+            //}
             break;
       }
            	   
