--- check_pf.c.orig	2012-07-30 18:13:57 UTC
+++ check_pf.c
@@ -23,6 +23,7 @@
 #include <net/pfvar.h>
 
 #include <err.h>
+#include <libpfctl.h>
 #include <limits.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -60,16 +61,20 @@ main(int argc, char *argv[])
 int 
 main(int argc, char *argv[])
 {
-	struct pf_status    ps;
-	struct pfioc_limit  pl;
+	struct pfctl_handle	*dev;
+	struct pfctl_status *ps;
 	const char          *errstr;
 	const char          *pf_device;
 	const char          *msg;
+	char                *pctindex;
 	float               percent;
-	int                 ch, wflag, cflag, dev;
-	int                 states_warning; 
-	int                 states_critical;
+	int                 ch, wflag, cflag;
+	unsigned long       states_warning; 
+	unsigned long       states_critical;
+	int                 default_warn_percent=DEFAULT_WARN_PERCENT;
+	int                 default_crit_percent=DEFAULT_CRIT_PERCENT;
 	int                 ret;
+	unsigned int		pl;
 
 	pf_device = "/dev/pf"; 
 
@@ -85,16 +90,30 @@ main(int argc, char *argv[])
 			help();
 			break;
 		case 'w':
-			wflag = 1;
-			states_warning = strtonum(optarg, 0, UINT_MAX, &errstr);
+			pctindex = strchr(optarg, '%');
+			if(pctindex) {
+				/* Ends in a %, treat as a percentage */
+				*pctindex = '\0';
+				default_warn_percent = strtonum(optarg, 0, 100, &errstr);
+			} else {
+				wflag = 1;
+				states_warning = strtonum(optarg, 0, UINT_MAX, &errstr);
+			}
 			if (errstr) {
 				printf("PF UNKNOWN - -w is %s: %s\n", errstr, optarg);
 				return (STATE_UNKNOWN);
 			}
 			break;
 		case 'c':
-			cflag = 1;
-			states_critical = strtonum(optarg, 0, UINT_MAX, &errstr);
+			pctindex = strchr(optarg, '%');
+			if(pctindex) {
+				/* Ends in a %, treat as a percentage */
+				*pctindex = '\0';
+				default_crit_percent = strtonum(optarg, 0, 100, &errstr);
+			} else {
+				cflag = 1;
+				states_critical = strtonum(optarg, 0, UINT_MAX, &errstr);
+			}
 			if (errstr) {
 				printf("PF UNKNOWN - -c is %s: %s\n", errstr, optarg);
 				return (STATE_UNKNOWN);
@@ -107,48 +126,46 @@ main(int argc, char *argv[])
 	argc -= optind;
 	argv += optind;
 	
-	dev = open(pf_device, O_RDONLY);
-	if (dev == -1) {
+	dev = pfctl_open(pf_device);
+	if (dev == NULL) {
 		printf("PF UNKNOWN - open(\"%s\") failed\n", pf_device);
 		return (STATE_UNKNOWN);
 	}
 
-	memset(&ps, 0, sizeof(struct pf_status));
-	if (ioctl(dev, DIOCGETSTATUS, &ps) == -1) {
-		printf("PF UNKNOWN - ioctl failed (DIOCGETSTATUS)\n");
+	ps = pfctl_get_status_h(dev);
+	if (ps  == NULL) {
+		printf("pfctl_get_status failure.\n");
 		return (STATE_UNKNOWN);
 	}
 
-	memset(&pl, 0, sizeof(struct pfioc_limit));
-	pl.index = PF_LIMIT_STATES;
-	if (ioctl(dev, DIOCGETLIMIT, &pl) == -1) {
-		printf("PF UNKNOWN - ioctl failed (DIOCGETLIMIT)\n");
+	if (pfctl_get_limit(dev,PF_LIMIT_STATES, &pl) != 0) {
+		printf("PF UNKNOWN - pfctl_get_limit failed\n");
 		return (STATE_UNKNOWN);
 	}
 
 	/* default thresholds will be based on the current state limit */
 	if (!wflag)
-		states_warning = pl.limit * DEFAULT_WARN_PERCENT / 100;
+		states_warning = pl * default_warn_percent / 100;
 
 	if (!cflag)
-		states_critical = pl.limit * DEFAULT_CRIT_PERCENT / 100;
+		states_critical = pl * default_crit_percent / 100;
 
 	if (states_warning >= states_critical) {
 		printf("PF UNKNOWN - <warning> must be less than <critical>\n");
 		return (STATE_UNKNOWN);
 	}
 
-	percent = (float)ps.states / (float)pl.limit * 100.0;
+	percent = (float)ps->states / (float)pl * 100.0;
 
-	if (ps.running != 1) {
+	if (ps->running != 1) {
 		printf("PF CRITICAL - status: Disabled\n");
 		return (STATE_CRITICAL);
 	}
 
-	if (ps.states >= states_critical) {
+	if (ps->states >= states_critical) {
 		msg = "CRITICAL";
 		ret = STATE_CRITICAL;
-	} else if (ps.states >= states_warning) {
+	} else if (ps->states >= states_warning) {
 		msg = "WARNING";
 		ret = STATE_WARNING;
 	} else {
@@ -156,9 +173,12 @@ main(int argc, char *argv[])
 		ret = STATE_OK;
 	}
 
-	printf("PF %s - states: %u (%.1f%% - limit: %u) | states=%u;%u;%u;%u;%u\n",
-	    msg, ps.states, percent, pl.limit,
-	    ps.states, states_warning, states_critical, 0, pl.limit);
+	printf("PF %s - states: %lu (%.1f%% - limit: %u) | states=%lu;%lu;%lu;%u;%u\n",
+	    msg, ps->states, percent, pl,
+	    ps->states, states_warning, states_critical, 0, pl);
+	
+	pfctl_free_status(ps);
+	pfctl_close(dev);
 
 	return (ret);
 }
