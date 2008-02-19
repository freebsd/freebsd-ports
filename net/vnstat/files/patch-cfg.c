--- src/cfg.c.orig	2008-02-01 23:11:50.000000000 +0100
+++ src/cfg.c	2008-02-18 18:23:22.000000000 +0100
@@ -36,8 +36,8 @@
 	printf("MaxBandwidth %d\n\n", cfg.maxbw);
 
 	printf("# interface specific limits\n");
-	printf("#  example 8Mbit limit for eth0 (remove # to activate):\n");
-	printf("#MaxBWeth0 8\n");
+	printf("#  example 8Mbit limit for fxp0 (remove # to activate):\n");
+	printf("#MaxBWfxp0 8\n");
 
 	while (p != NULL) {
 		printf("MaxBW%s %d\n", p->interface, p->limit);
@@ -86,7 +86,7 @@
 	/* load default config */
 	defaultcfg();
 
-	/* possible config files: 1) --config   2) $HOME/.vnstatrc   3) /etc/vnstat.conf   4) none */
+	/* possible config files: 1) --config   2) $HOME/.vnstatrc   3) /usr/local/etc/vnstat.conf   4) none */
 
 	if (cfgfile[0]!='\0') {
 	
@@ -112,7 +112,7 @@
 		if (tryhome && (fd=fopen(buffer, "r"))!=NULL) {
 			if (debug)
 				printf("Config file: $HOME/.vnstatrc\n");
-		} else if ((fd=fopen("/etc/vnstat.conf", "r"))!=NULL) {
+		} else if ((fd=fopen("/usr/local/etc/vnstat.conf", "r"))!=NULL) {
 			if (debug)
 				printf("Config file: /etc/vnstat.conf\n");
 		} else {
