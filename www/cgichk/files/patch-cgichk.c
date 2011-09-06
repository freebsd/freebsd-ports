--- cgichk.c.orig	2001-04-06 16:36:25.000000000 +0800
+++ cgichk.c	2011-09-06 11:29:49.000000000 +0800
@@ -58,7 +58,7 @@ void check_dir_only()
 		CPRINT("                                                         \r");
 		CPRINT("  Looking for /%s\r", r->v[count]);
 
-		if (result = http_has(temp,0))
+		if ((result = http_has(temp,0)))
 		{
 			CPRINT("                                                       \r");
 			PRINT("    Found /%s (%d)                        \n", r->v[count], result);
@@ -77,7 +77,7 @@ void check_hole(char *hole)
 	CPRINT("                                                       \r");
 	CPRINT("  Looking for %s\r", hole);
 
-	if (result = http_has(hole,0))
+	if ((result = http_has(hole,0)))
 	{
 		CPRINT("                                                   \r");
 		PRINT("  Found %s (%d)\n",hole, result);
@@ -131,7 +131,7 @@ void check_interest()
 
 		CPRINT("  Looking for /%s                          \r", r->v[y]);
 
-		if (result = http_has(temp,0))        // See if the directory exists, so no wasted time
+		if ((result = http_has(temp,0)))        // See if the directory exists, so no wasted time
 		{
 			PRINT("    Found %s (%d)                  \n", temp, result);
 			BEEP();
@@ -144,7 +144,7 @@ void check_interest()
 					CPRINT("                                         \r");
 					CPRINT("    Looking for /%s                       \r", temp);
 
-					if (result = http_has(temp,0))
+					if ((result = http_has(temp,0)))
 					{
 						PRINT("     ---> /%s (%d)\n", temp, result);
 						BEEP();
@@ -289,7 +289,7 @@ void get_commandline(int argc, char *arg
 
 	parms.URL = (char*) strdup(argv[optind]);
 
-	breakup_url(parms.URL, domain, 1024, &parms.port, 80, dir, 1024);
+	breakup_url(parms.URL, domain, 1024, (int *)&parms.port, 80, dir, 1024);
 }
 /*----------------------------------------------------------------*/
 void mainloop()
@@ -343,7 +343,7 @@ int main(int argc, char *argv[])
 	{
 		char *env = NULL;
 		
-		if (env = getenv(PROXY_ENV))
+		if ((env = getenv(PROXY_ENV)))
 		{
 			proxy.host = (char *) malloc(strlen(env));
 			breakup_url(env, proxy.host, strlen(env), &proxy.port, 8000, NULL, 0);
