--- src/conf.c	Mon Dec 19 16:25:35 2005
+++ src/conf.c	Fri Mar 31 20:56:39 2006
@@ -6,6 +6,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include "headers/defs.h"
 #include "headers/conf.h"
@@ -15,15 +16,35 @@
 	int ctr, tmp;
 	int flag = 0;
 	FILE *fp;
+	char *homedir;
 	char ch;
+	char home_directory[255];
 	char pre[255];                                  /* Temp Buffer for config lines */
 	char _confstr[MAX_NO_LINES][MAX_LINE_LENGTH];   /* Temp buffer for valid config lines */
+	
+	homedir = getenv("HOME");
+        if (homedir == NULL)
+        {
+                homedir = getenv("USER");
+                if (homedir == NULL)
+                {
+                        homedir = getenv("USERNAME");
+                        if (homedir == NULL)
+                        {
+                                cli_msg( stderr, "Could not find user's home directory!\n" );
+                        }
+                }
+		strcpy(home_directory,"/home/");
+        }
+	
+	strcpy(home_directory,homedir);
+	strcat(home_directory,"/.msn/msn.conf");
 
-	if ( (fp = fopen(CONF_LOCATION, "r")) != NULL ){
+	if ( (fp = fopen(home_directory, "r")) != NULL ){
 		cli_msg("Reading msn.conf...\n");
 	}
 	else {
-		cli_msg("No config file found at: %s\n", CONF_LOCATION);
+		cli_msg("No config file found at: %s\n", home_directory);
 		cli_msg("Continuing with command line args and defaults\n");
 		return;
 		}
