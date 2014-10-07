--- ntpd/ntpd.c.orig	2011-12-24 15:27:15.000000000 -0800
+++ ntpd/ntpd.c	2014-10-06 17:04:57.760219124 -0700
@@ -853,8 +853,8 @@
 	init_proto();		/* Call at high priority */
 	init_io();
 	init_loopfilter();
-	mon_start(MON_ON);	/* monitor on by default now	  */
-				/* turn off in config if unwanted */
+	mon_start(MON_OFF);	/* monitor off by default now	  */
+				/* turn on in config if wanted */
 
 	/*
 	 * Get the configuration.  This is done in a separate module
