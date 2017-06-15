--- swapd.c.orig	2013-10-06 16:09:13 UTC
+++ swapd.c
@@ -1,3 +1,6 @@
+#include <syslog.h>
+#include <stdarg.h>
+#include <errno.h>
 #include "compat.h"
 
 #ifdef HAVE_STDIO_H
@@ -188,15 +191,18 @@ int swapd_swapon(const char *swapfile) {
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
@@ -287,7 +293,9 @@ swap_t *swapd_mkswap(const char *swapdir
 
 int swapd_swapoff(swap_t *swapfile) {
 	int swapoffret = -1;
+#ifdef SWAPD_SWAPOFF_CMDLINE
 	char cmdline[1024] = {0};
+#endif
 
 	if (swapfile == NULL) {
 		return(-1);
@@ -300,11 +308,13 @@ int swapd_swapoff(swap_t *swapfile) {
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
@@ -445,6 +455,8 @@ int main(int argc, char **argv) {
 	int chdirret = 0, statret = 0;
 	int gfm_errorcount = 0;
 
+	openlog("swapd", LOG_PID, LOG_DAEMON);
+
 	if (!swapd_init_stats()) {
 		return(EXIT_FAILURE);
 	}
@@ -519,7 +531,7 @@ int main(int argc, char **argv) {
 
 	daemonize();
 
-	dh = opendir(".");
+	dh = opendir(swapdir);
 
 	if (dh != NULL) {
 		inactive_swaps = 0;
@@ -588,7 +600,7 @@ int main(int argc, char **argv) {
 				}
 			}
 
-			swapinfo = swapd_mkswap(".", swapsize, swapfile);
+			swapinfo = swapd_mkswap(swapdir, swapsize, swapfile);
 
 			if (swapfile != NULL) {
 				free(swapfile);
@@ -638,6 +650,7 @@ int main(int argc, char **argv) {
 					if (swaps[i]->active == 0 && swaps[i]->pathname != NULL) {
 						inactive_swaps++;
 						if (inactive_swaps > max_inactive_swaps) {
+						        syslog(LOG_NOTICE, "unlink(%s)", swaps[i]->pathname);
 							unlink(swaps[i]->pathname);
 							free(swaps[i]->pathname);
 							free(swaps[i]);
@@ -659,5 +672,6 @@ int main(int argc, char **argv) {
 
 	}
 
+	closelog();
 	return(EXIT_FAILURE);
 }
