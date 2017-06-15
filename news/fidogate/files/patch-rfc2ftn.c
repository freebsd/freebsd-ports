--- src/gate/rfc2ftn.c.orig	2004-08-22 20:19:12 UTC
+++ src/gate/rfc2ftn.c
@@ -99,7 +99,7 @@ void	usage			(void);
 static char *o_flag = NULL;		/* -o --out-packet-file		    */
 static char *w_flag = NULL;		/* -w --write-outbound 		    */
 static int   W_flag = FALSE;		/* -W --write-crash    		    */
-static int   i_flag = FALSE;		/* -i --ignore-hosts   		    */
+int   i_flag = FALSE;		/* -i --ignore-hosts   		    */
 
 static int maxmsg = 0;			/* Process maxmsg messages */
 
