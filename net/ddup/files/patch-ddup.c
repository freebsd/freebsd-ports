--- ddup.c.orig	Tue Oct 31 01:13:23 2000
+++ ddup.c	Thu Jul 25 07:25:54 2002
@@ -26,25 +26,29 @@
 void usage(void)
 {
   printf("DD-UP version %s by Thomas Gandy and Tom Groves (ddupwww@ddup.org)\n", AGENT_VER);
-  printf("Usage:  ddup --host host.domain.ext (multiple hosts separated by ,)\n");
-  printf("        (host.domain.ext,host2.domain.ext) [--ip address] [--wildcard]\n");
-  printf("        [--proxyserv server] [--proxyport port] [--help] [--debug] [--mx mxhost]\n");
-  printf("        [--backmx] [--static]\n");
-  printf("        --host host.domain.ext : REQUIRED to update.\n"); 
-  printf("                                 Where host.domain.ext is your domain.\n"); 
-  printf("                                 eg. gandy.dyndns.org, gandy.ath.cx\n");
-  printf("        --ip address : Forces manual ip specification\n");
-  printf("                       Where address is your IP address.\n");
-  printf("        --wildcard : Enables wildcards.\n");
+  printf("Usage:  ddup --host host.domain.ext [--ip address] [--wildcard]\n");
+  printf("	     [--mx mxhost] [--backmx] [--static | --dynamic | --custom]\n");
+  printf("	     [--proxyserv server] [--proxyport port] [--debug]\n");
+  printf("	ddup [--help | --makeconf]\n");
+  printf("\n");
+  printf("	--host host.domain.ext : REQUIRED to update.\n"); 
+  printf("		Where host.domain.ext is your domain.\n"); 
+  printf("		Multiple hosts separated by a `,' (comma) may be specified.\n");
+  printf("		e.g. gandy.dyndns.org,gandy.ath.cx\n");
+  printf("	--ip address : Forces manual ip specification\n");
+  printf("		Where address is your IP address.\n");
+  printf("	--wildcard : Enables wildcards.\n");
   printf("	--mx mxhost : Sets your MX to mxhost.\n");
   printf("	--backmx : Needs --mx and sets mxhost to be a backup MX.\n");
-  printf("        --proxyserv server : Uses server as proxy.\n");
-  printf("        --proxyport port : connects to proxy with port.\n");
-  printf("        --help : Prints this message.\n");
-  printf("	--debug : Prints debug output of what is sent to server.\n");
   printf("	--static : Use the Static DNS service. (Added by Patrick D.)\n");
-  printf("\n");
-  printf("	--makeconf : Creates the config file for you. (Base64 Encodes your password)\n");
+  printf("	--dynamic : Use the Dyanmic DNS service. (Added by rwc.)\n");
+  printf("	--custom : Use the Custom DNS service. (Added by rwc.)\n");
+  printf("	--proxyserv server : Uses server as proxy.\n");
+  printf("	--proxyport port : connects to proxy with port.\n");
+  printf("	--debug : Prints debug output of what is sent to server.\n");
+  printf("	--help : Prints this message.\n");
+  printf("	--makeconf : Creates the config file for you.\n");
+  printf("		Base64 Encodes your password.\n");
   exit(0);
 }
 
