--- swapd.c.orig	2005-02-18 20:32:30.000000000 -0800
+++ swapd.c	2010-06-25 12:16:07.000000000 -0700
@@ -1,3 +1,6 @@
+#include <syslog.h>
+#include <stdarg.h>
+#include <errno.h>
 #include "compat.h"
 
 #ifdef HAVE_STDIO_H
@@ -187,15 +190,18 @@
 #  ifdef SWAPON_TAKES_2_ARGS
 	/* Linux */
 	swaponret = swapon(swapfile, 0);
+	syslog(LOG_NOTICE, "swapon(%s, 0) ret:%d errno:%d", swapfile, swaponret, errno);
 #  else
 	/* BSD */
 	swaponret = swapon(swapfile);
+	syslog(LOG_NOTICE, "swapon(%s) ret:%d errno:%d", swapfile, swaponret, errno);
 #  endif
 #else
 # ifdef SWAPD_SWAPON_CMDLINE
 	char cmdline[1024] = {0};
 	snprintf(cmdline, sizeof(cmdline) - 1, SWAPD_SWAPON_CMDLINE, swapfile);
 	swaponret = system(cmdline);
+	syslog(LOG_NOTICE, "swapon: %s ret:%d errno:%d", cmdline, swaponret, errno);
 #  else
 #    error Dont know how to swapon() on this platform!
 #  endif
@@ -286,7 +292,9 @@
 
 int swapd_swapoff(swap_t *swapfile) {
 	int swapoffret = -1;
+#ifdef SWAPD_SWAPOFF_CMDLINE
 	char cmdline[1024] = {0};
+#endif
 
 	if (swapfile == NULL) {
 		return(-1);
@@ -299,11 +307,13 @@
 /* Prefer the swapoff() system call ... */
 #ifdef HAVE_SWAPOFF
 	swapoffret = swapoff(swapfile->pathname);
+	syslog(LOG_NOTICE, "swapoff(%s) ret:%d errno:%d", swapfile->pathname, swapoffret, errno);
 #else
 /* ... if that's not available, try some command.. */
 #  ifdef SWAPD_SWAPOFF_CMDLINE
 	snprintf(cmdline, sizeof(cmdline) - 1, SWAPD_SWAPOFF_CMDLINE, swapfile->pathname);
 	swapoffret = system(cmdline);
+	syslog(LOG_NOTICE, "swapoff: %s ret:%d errno:%d", cmdline, swapoffret, errno);
 #  else
 /*  ... otherwise, issue a warning since we don't know what to do. */
 #    warning Dont know how to swapoff on this platform
@@ -444,6 +454,8 @@
 	int chdirret = 0, statret = 0;
 	int gfm_errorcount = 0;
 
+	openlog("swapd", LOG_PID, LOG_DAEMON);
+
 	if (!swapd_init_stats()) {
 		return(EXIT_FAILURE);
 	}
@@ -518,7 +530,7 @@
 
 	daemonize();
 
-	dh = opendir(".");
+	dh = opendir(swapdir);
 
 	if (dh != NULL) {
 		inactive_swaps = 0;
@@ -587,7 +599,7 @@
 				}
 			}
 
-			swapinfo = swapd_mkswap(".", swapsize, swapfile);
+			swapinfo = swapd_mkswap(swapdir, swapsize, swapfile);
 
 			if (swapfile != NULL) {
 				free(swapfile);
@@ -637,6 +649,7 @@
 					if (swaps[i]->active == 0 && swaps[i]->pathname != NULL) {
 						inactive_swaps++;
 						if (inactive_swaps > max_inactive_swaps) {
+						        syslog(LOG_NOTICE, "unlink(%s)", swaps[i]->pathname);
 							unlink(swaps[i]->pathname);
 							free(swaps[i]->pathname);
 							free(swaps[i]);
@@ -658,5 +671,6 @@
 
 	}
 
+	closelog();
 	return(EXIT_FAILURE);
 }
