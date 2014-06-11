--- check_pf.c.orig	2014-04-05 18:32:50.000000000 -0500
+++ check_pf.c	2014-04-05 18:44:27.000000000 -0500
@@ -65,10 +65,13 @@
 	const char          *errstr;
 	const char          *pf_device;
 	const char          *msg;
+	char                *pctindex;
 	float               percent;
 	int                 ch, wflag, cflag, dev;
 	int                 states_warning; 
 	int                 states_critical;
+	int                 default_warn_percent=DEFAULT_WARN_PERCENT;
+	int                 default_crit_percent=DEFAULT_CRIT_PERCENT;
 	int                 ret;
 
 	pf_device = "/dev/pf"; 
@@ -85,16 +88,30 @@
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
@@ -128,10 +145,10 @@
 
 	/* default thresholds will be based on the current state limit */
 	if (!wflag)
-		states_warning = pl.limit * DEFAULT_WARN_PERCENT / 100;
+		states_warning = pl.limit * default_warn_percent / 100;
 
 	if (!cflag)
-		states_critical = pl.limit * DEFAULT_CRIT_PERCENT / 100;
+		states_critical = pl.limit * default_crit_percent / 100;
 
 	if (states_warning >= states_critical) {
 		printf("PF UNKNOWN - <warning> must be less than <critical>\n");
