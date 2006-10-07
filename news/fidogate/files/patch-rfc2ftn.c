--- src/gate/rfc2ftn.c.orig	Sun Aug 22 22:19:12 2004
+++ src/gate/rfc2ftn.c	Sat Oct  7 21:06:14 2006
@@ -99,7 +99,7 @@
 static char *o_flag = NULL;		/* -o --out-packet-file		    */
 static char *w_flag = NULL;		/* -w --write-outbound 		    */
 static int   W_flag = FALSE;		/* -W --write-crash    		    */
-static int   i_flag = FALSE;		/* -i --ignore-hosts   		    */
+int   i_flag = FALSE;		/* -i --ignore-hosts   		    */
 
 static int maxmsg = 0;			/* Process maxmsg messages */
 
