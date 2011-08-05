--- a/sleeptimer.c
+++ b/sleeptimer.c
@@ -165,6 +165,8 @@ bool cPluginSleeptimer::ProcessArgs(int 
 {
   // Implement command line argument processing here if applicable.
 	int c;
+	if (!strcmp(*argv, "sleeptimer"))
+		++argv, --argc;
 	while((c = getopt(argc, argv, "e:")) != -1 ) {
 		switch(c) {
 			case 'e': 
