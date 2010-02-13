--- ./check_pf.c.orig	2007-03-08 07:19:40.000000000 +0100
+++ ./check_pf.c	2010-01-03 00:24:23.000000000 +0100
@@ -70,12 +70,13 @@
 	int                 ch, wflag, cflag, dev;
 	int                 states_warning; 
 	int                 states_critical;
+	int                 show_perf=0;
 
 	pf_device = "/dev/pf"; 
 
 	wflag = cflag = 0;
 
-	while ((ch = getopt(argc, argv, "Vhw:c:")) != -1) {
+	while ((ch = getopt(argc, argv, "Vhpw:c:")) != -1) {
 		switch (ch) {
 		case 'V':
 			version();
@@ -84,6 +85,9 @@
 		case 'h':
 			help();
 			break;
+		case 'p':
+			show_perf = 1;
+			break;
 		case 'w':
 			wflag = 1;
 			states_warning = strtonum(optarg, 0, ULONG_MAX, 
@@ -151,19 +155,34 @@
 	}
 
 	if (ps.states >= states_critical) {
-		(void)printf("PF CRITICAL - states: %u (%.1f%% - limit: %u)\n",
+		(void)printf("PF CRITICAL - states: %u (%.1f%% - limit: %u)",
 		    ps.states, percent, pl.limit);
+		if(!show_perf)
+			(void)printf("\n");
+		else
+			(void)printf("|current=%u;%u;%u; percent=%.1f%%; limit=%u;\n",
+			    ps.states, states_warning, states_critical, percent, pl.limit);
 		return (STATE_CRITICAL);
 	}
 	
 	if (ps.states >= states_warning) {
-		(void)printf("PF WARNING - states: %u (%.1f%% - limit: %u)\n",
+		(void)printf("PF WARNING - states: %u (%.1f%% - limit: %u)",
 		    ps.states, percent, pl.limit);
+		if(!show_perf)
+			(void)printf("\n");
+		else
+			(void)printf("|current=%u;%u;%u; percent=%.1f%%; limit=%u;\n",
+			    ps.states, states_warning, states_critical, percent, pl.limit);
 		return (STATE_WARNING);
 	}
 
-	(void)printf("PF OK - states: %u (%.1f%% - limit: %u)\n",
+	(void)printf("PF OK - states: %u (%.1f%% - limit: %u)",
 	    ps.states, percent, pl.limit);
+	if(!show_perf)
+		(void)printf("\n");
+	else
+		(void)printf("|current=%u;%u;%u; percent=%.1f%%; limit=%u;\n",
+		    ps.states, states_warning, states_critical, percent, pl.limit);
 	return (STATE_OK);
 }
 
@@ -183,6 +202,8 @@
 	(void)fprintf(stderr, "        ");
 	(void)fprintf(stderr, "-h        - Print the plugin help\n");
 	(void)fprintf(stderr, "        ");
+	(void)fprintf(stderr, "-p        - Display additional nagios performance data\n");
+	(void)fprintf(stderr, "        ");
 	(void)fprintf(stderr, "-w number - Warning when <number> states"
 	    " (default: %u%% of state limit)\n", DEFAULT_WARN_PERCENT);
 	(void)fprintf(stderr, "        ");
