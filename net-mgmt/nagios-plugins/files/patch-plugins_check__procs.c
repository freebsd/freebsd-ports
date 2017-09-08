--- plugins/check_procs.c.orig	2017-01-16 17:24:03 UTC
+++ plugins/check_procs.c
@@ -71,6 +71,7 @@ int options = 0; /* bitmask of filter cr
 #define ELAPSED 512
 #define EREG_ARGS 1024
 #define CGROUP_HIERARCHY 2048
+#define JID 4096
 
 #define KTHREAD_PARENT "kthreadd" /* the parent process of kernel threads:
 							ppid of procs are compared to pid of this proc*/
@@ -103,6 +104,7 @@ char *fails;
 char tmp[MAX_INPUT_BUFFER];
 int kthread_filter = 0;
 int usepid = 0; /* whether to test for pid or /proc/pid/exe */
+int jid;
 
 FILE *ps_input = NULL;
 
@@ -133,6 +135,7 @@ main (int argc, char **argv)
 	int procuid = 0;
 	pid_t procpid = 0;
 	pid_t procppid = 0;
+    int procjid = 0;
 	pid_t kthread_ppid = 0;
 	int procvsz = 0;
 	int procrss = 0;
@@ -236,9 +239,9 @@ main (int argc, char **argv)
 			procseconds = convert_to_seconds(procetime);
 
 			if (verbose >= 3) {
-				printf ("proc#=%d uid=%d vsz=%d rss=%d pid=%d ppid=%d pcpu=%.2f stat=%s etime=%s prog=%s args=%s",
++				printf ("proc#=%d uid=%d vsz=%d rss=%d pid=%d ppid=%d jid=%d pcpu=%.2f stat=%s etime=%s prog=%s args=%s\n", 
 					procs, procuid, procvsz, procrss,
-					procpid, procppid, procpcpu, procstat,
+					procpid, procppid, procjid, procpcpu, procstat,
 					procetime, procprog, procargs);
 				if (strstr(PS_COMMAND, "cgroup") != NULL) {
 					printf(" proc_cgroup_hierarchy=%s\n", proc_cgroup_hierarchy);
@@ -287,6 +290,8 @@ main (int argc, char **argv)
 				resultsum |= PROG;
 			if ((options & PPID) && (procppid == ppid))
 				resultsum |= PPID;
+            if ((options & JID) && (procjid == jid))
+                resultsum |= JID;
 			if ((options & USER) && (procuid == uid))
 				resultsum |= USER;
 			if ((options & VSZ)  && (procvsz >= vsz))
@@ -315,9 +320,9 @@ main (int argc, char **argv)
 
 			procs++;
 			if (verbose >= 2) {
-				printf ("Matched: uid=%d vsz=%d rss=%d pid=%d ppid=%d pcpu=%.2f stat=%s etime=%s prog=%s args=%s",
++				printf ("Matched: uid=%d vsz=%d rss=%d pid=%d ppid=%d jid=%d pcpu=%.2f stat=%s etime=%s prog=%s args=%s\n", 
 					procuid, procvsz, procrss,
-					procpid, procppid, procpcpu, procstat, 
+					procpid, procppid, procjid, procpcpu, procstat, 
 					procetime, procprog, procargs);
 				if (strstr(PS_COMMAND, "cgroup") != NULL) {
 					printf(" cgroup_hierarchy=%s\n", cgroup_hierarchy);
@@ -438,6 +443,7 @@ process_arguments (int argc, char **argv
 		{"no-kthreads", required_argument, 0, 'k'},
 		{"traditional-filter", no_argument, 0, 'T'},
 		{"cgroup-hierarchy", required_argument, 0, 'g'},
+		{"jid", required_argument, 0, 'j'},
 		{0, 0, 0, 0}
 	};
 
@@ -446,7 +452,7 @@ process_arguments (int argc, char **argv
 			strcpy (argv[c], "-t");
 
 	while (1) {
-		c = getopt_long (argc, argv, "Vvhkt:c:w:p:s:u:C:a:z:r:m:P:Tg:",
+		c = getopt_long (argc, argv, "Vvhkt:c:w:p:s:u:C:a:z:r:m:P:Tg:j:",
 			longopts, &option);
 
 		if (c == -1 || c == EOF)
@@ -477,6 +483,12 @@ process_arguments (int argc, char **argv
 				break;
 			}
 			usage4 (_("Parent Process ID must be an integer!"));
+        case 'j':                                   /* jail id */
+            if (sscanf (optarg, "%d%[^0-9]", &jid, tmp) == 1) {
+                asprintf (&fmt, "%s%sJID = %d", (fmt ? fmt : "") , (options ? ", " : ""), jid);
+                options |= JID;
+                break;
+            }
 		case 's':									/* status */
 			if (statopts)
 				break;
@@ -766,6 +778,8 @@ print_help (void)
   printf ("   %s\n", _("RSZDT, plus others based on the output of your 'ps' command)."));
   printf (" %s\n", "-p, --ppid=PPID");
   printf ("   %s\n", _("Only scan for children of the parent process ID indicated."));
+  printf (" %s\n", "-j, --jid=JID");
+  printf ("   %s\n", _("Only scan for process running in jail which ID is JID."));
   printf (" %s\n", "-z, --vsz=VSZ");
   printf ("   %s\n", _("Only scan for processes with VSZ higher than indicated."));
   printf (" %s\n", "-r, --rss=RSS");
@@ -818,7 +832,7 @@ void
 print_usage (void)
 {
   printf ("%s\n", _("Usage:"));
-	printf ("%s -w <range> -c <range> [-m metric] [-s state] [-p ppid]\n", progname);
+	printf ("%s -w <range> -c <range> [-m metric] [-s state] [-p ppid] [-j jid]\n", progname);
   printf (" [-u user] [-r rss] [-z vsz] [-P %%cpu] [-a argument-array]\n");
   printf (" [-C command] [-k] [-t timeout] [-v]\n");
 }
