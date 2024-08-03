https://lists.sr.ht/~leon_plickat/public-inbox/patches/54271

--- src/wlclock.c.orig	2021-12-30 16:22:36 UTC
+++ src/wlclock.c
@@ -330,7 +330,7 @@ static bool handle_command_flags (int argc, char *argv
 	int opt, args;
 	extern int optind;
 	extern char *optarg;
-	while ( (opt = getopt_long(argc, argv, "hvV", opts, &optind)) != -1 ) switch (opt)
+	while ( (opt = getopt_long(argc, argv, "hvV", opts, NULL)) != -1 ) switch (opt)
 	{
 		case 'h':
 			fputs(usage, stderr);
