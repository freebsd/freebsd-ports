--- ./plugins/check_procs.c.orig	2010-07-28 05:47:16.000000000 +0900
+++ ./plugins/check_procs.c	2012-11-15 16:22:30.000000000 +0900
@@ -67,6 +67,7 @@
 #define PCPU 256
 #define ELAPSED 512
 #define EREG_ARGS 1024
+#define JID 2048
 /* Different metrics */
 char *metric_name;
 enum metric {
@@ -92,6 +93,7 @@
 char *fmt;
 char *fails;
 char tmp[MAX_INPUT_BUFFER];
+int jid;
 
 FILE *ps_input = NULL;
 
@@ -107,6 +109,7 @@
 	int procuid = 0;
 	pid_t procpid = 0;
 	pid_t procppid = 0;
+        int procjid = 0;
 	int procvsz = 0;
 	int procrss = 0;
 	int procseconds = 0;
@@ -196,9 +199,9 @@
 			procseconds = convert_to_seconds(procetime);
 
 			if (verbose >= 3)
-				printf ("proc#=%d uid=%d vsz=%d rss=%d pid=%d ppid=%d pcpu=%.2f stat=%s etime=%s prog=%s args=%s\n", 
+				printf ("proc#=%d uid=%d vsz=%d rss=%d pid=%d ppid=%d jid=%d pcpu=%.2f stat=%s etime=%s prog=%s args=%s\n", 
 					procs, procuid, procvsz, procrss,
-					procpid, procppid, procpcpu, procstat, 
+					procpid, procppid, procjid, procpcpu, procstat, 
 					procetime, procprog, procargs);
 
 			/* Ignore self */
@@ -214,6 +217,8 @@
 				resultsum |= PROG;
 			if ((options & PPID) && (procppid == ppid))
 				resultsum |= PPID;
+			if ((options & JID) && (procjid == jid))
+				resultsum |= JID;
 			if ((options & USER) && (procuid == uid))
 				resultsum |= USER;
 			if ((options & VSZ)  && (procvsz >= vsz))
@@ -231,9 +236,9 @@
 
 			procs++;
 			if (verbose >= 2) {
-				printf ("Matched: uid=%d vsz=%d rss=%d pid=%d ppid=%d pcpu=%.2f stat=%s etime=%s prog=%s args=%s\n", 
+				printf ("Matched: uid=%d vsz=%d rss=%d pid=%d ppid=%d jid=%d pcpu=%.2f stat=%s etime=%s prog=%s args=%s\n", 
 					procuid, procvsz, procrss,
-					procpid, procppid, procpcpu, procstat, 
+					procpid, procppid, procjid, procpcpu, procstat, 
 					procetime, procprog, procargs);
 			}
 
@@ -325,6 +330,7 @@
 		{"timeout", required_argument, 0, 't'},
 		{"status", required_argument, 0, 's'},
 		{"ppid", required_argument, 0, 'p'},
+		{"jid", required_argument, 0, 'j'},
 		{"command", required_argument, 0, 'C'},
 		{"vsz", required_argument, 0, 'z'},
 		{"rss", required_argument, 0, 'r'},
@@ -344,7 +350,7 @@
 			strcpy (argv[c], "-t");
 
 	while (1) {
-		c = getopt_long (argc, argv, "Vvht:c:w:p:s:u:C:a:z:r:m:P:", 
+		c = getopt_long (argc, argv, "Vvht:c:w:p:j:s:u:C:a:z:r:m:P:", 
 			longopts, &option);
 
 		if (c == -1 || c == EOF)
@@ -396,6 +402,13 @@
 				break;
 			}
 			usage4 (_("Parent Process ID must be an integer!"));
+                case 'j':									/* jail id */
+			if (sscanf (optarg, "%d%[^0-9]", &jid, tmp) == 1) {
+				asprintf (&fmt, "%s%sJID = %d", (fmt ? fmt : "") , (options ? ", " : ""), jid);
+				options |= JID;
+				break;
+			}
+			usage4 (_("Jail ID must be an integer!"));
 		case 's':									/* status */
 			if (statopts)
 				break;
@@ -712,6 +725,8 @@
   printf ("   %s\n", _("RSZDT, plus others based on the output of your 'ps' command)."));
   printf (" %s\n", "-p, --ppid=PPID");
   printf ("   %s\n", _("Only scan for children of the parent process ID indicated."));
+  printf (" %s\n", "-j, --jid=JID");
+  printf ("   %s\n", _("Only scan for process running in jail which ID is JID."));
   printf (" %s\n", "-z, --vsz=VSZ");
   printf ("   %s\n", _("Only scan for processes with VSZ higher than indicated."));
   printf (" %s\n", "-r, --rss=RSS");
@@ -758,7 +773,7 @@
 print_usage (void)
 {
   printf ("%s\n", _("Usage:"));
-	printf ("%s -w <range> -c <range> [-m metric] [-s state] [-p ppid]\n", progname);
+	printf ("%s -w <range> -c <range> [-m metric] [-s state] [-p ppid] [-j jid]\n", progname);
   printf (" [-u user] [-r rss] [-z vsz] [-P %%cpu] [-a argument-array]\n");
   printf (" [-C command] [-t timeout] [-v]\n");
 }
