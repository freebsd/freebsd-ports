--- htshd/htshd.c.orig	Fri Nov 24 15:46:01 2000
+++ htshd/htshd.c	Tue Nov 18 18:03:33 2003
@@ -97,10 +97,10 @@
 #define SERVICE_NAME "htsh"	/* Should be in /etc/services
                                    on login and http server hosts */
 
-#define CONFIG_FILE "/etc/htshd.conf"
+#define CONFIG_FILE "/usr/local/etc/wapsh/htshd.conf"
 				/* Default name of startup config file */
 
-#define GLOBAL_RC_FILE "/etc/htsh_profile"
+#define GLOBAL_RC_FILE "/usr/local/etc/wapsh/htsh_profile"
 				/* Default name of global user 
 				   initialisation file */
 #define RCFILE ".htshrc"	/* Name of user-specific initialisation file
@@ -3572,39 +3572,38 @@
 usage(void)
 {
     if (!weAreDaemon) {
-        fprintf(stderr, 
-"htsh options are:
--b numbytes         Specify upper limit for per-user shell output buffers
-		    (Default: %d bytes)
--c numbytes	    Maximum number of bytes to be transferred at a time 
-                    between Client Shell and HTTP Server.  
-		    (Default: %d bytes, minimum setting %d bytes)
--d		    Run in debug mode
--D [y|n]	    If argument is 'y' run as daemon, otherwise ('n')
-		    do not daemonise.  
-		    (If run from inetd, htsh is always a daemon.  If run from a 
-		    shell, htsh is a daemon by default)
--f config-file	    Use named file for startup configuration, instead of %s
--F		    Do not use standard configuration file (%s)
--h		    Display this help message
--g global-init-file Use named file as login initialisation file for all user
-		    logins.  (Default: %s)
--H http-server	    Specify HTTP server from which connections will 
-                    be accepted.  (Can be specified multiple times)
--L log-file-dir     Record script(1) style log of each login session
-                    in named directory
--o numsecs	    Timeout for shell output (Default: %3.1f seconds, 
-                    minimum: %3.1f, maximum: %4.1f seconds)
--p port-num	    Specify TCP port on which htsh should listen for 
-                    connections.  (Default is %s in /etc/services)
--P 'proto-name... ' Specify list of allowed login protocols 
-                    (can be '%s' and or '%s'
--t numsecs    	    Timeout for shell input (Default: %d seconds)
--u username	    Specify user who is allowed to login to htsh
-                    (Can be repeated multiple times)
-
-The -c, -D, -o, -p, and -t options override corresponding options in the
-configuration file.  The -h and -u options are additive with corresponding
+        fprintf(stderr, "htsh options are: \n\
+-b numbytes         Specify upper limit for per-user shell output buffers \n\
+		    (Default: %d bytes)\n\
+-c numbytes	    Maximum number of bytes to be transferred at a time \n\
+                    between Client Shell and HTTP Server.  \n\
+		    (Default: %d bytes, minimum setting %d bytes)\n\
+-d		    Run in debug mode\n\
+-D [y|n]	    If argument is 'y' run as daemon, otherwise ('n')\n\
+		    do not daemonise.  \n\
+		    (If run from inetd, htsh is always a daemon.  If run from a \n\
+		    shell, htsh is a daemon by default)\n\
+-f config-file	    Use named file for startup configuration, instead of %s\n\
+-F		    Do not use standard configuration file (%s)\n\
+-h		    Display this help message\n\
+-g global-init-file Use named file as login initialisation file for all user\n\
+		    logins.  (Default: %s)\n\
+-H http-server	    Specify HTTP server from which connections will \n\
+                    be accepted.  (Can be specified multiple times)\n\
+-L log-file-dir     Record script(1) style log of each login session\n\
+                    in named directory\n\
+-o numsecs	    Timeout for shell output (Default: %3.1f seconds, \n\
+                    minimum: %3.1f, maximum: %4.1f seconds)\n\
+-p port-num	    Specify TCP port on which htsh should listen for \n\
+                    connections.  (Default is %s in /etc/services)\n\
+-P 'proto-name... ' Specify list of allowed login protocols \n\
+                    (can be '%s' and or '%s'\n\
+-t numsecs    	    Timeout for shell input (Default: %d seconds)\n\
+-u username	    Specify user who is allowed to login to htsh\n\
+                    (Can be repeated multiple times)\n\
+\n\
+The -c, -D, -o, -p, and -t options override corresponding options in the\n\
+configuration file.  The -h and -u options are additive with corresponding\n\
 options in the configuration file\n", 
     		DEF_OUTPUT_BUFFER_LIMIT,
         	DEF_CS_MAX_TRANSFER_SIZE, CS_MAX_TRANSFER_SIZE_LOW_BOUND,
