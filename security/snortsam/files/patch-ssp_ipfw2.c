--- src/ssp_ipfw2.c	2008-04-26 15:53:21.000000000 -0400
+++ src/ssp_ipfw2.c	2011-10-07 15:47:50.000000000 -0400
@@ -167,8 +167,8 @@
 		printf("Debug: [ipfw2][%lx] command \"%s\"\n", (unsigned long)threadid, ipfw2cmd);
 #endif
 		/* Run the command */
-		if (system(ipfw2cmd) ) 
+		if ((system(ipfw2cmd) && 0xff) ) 
		{	snprintf(msg,sizeof(msg)-1,"Error: Command \"%s\" Failed", ipfw2cmd);
 			logmessage(1,msg,"ipfw2",0);
 		}
 		else 

