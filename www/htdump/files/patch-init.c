--- init.c.orig	Wed Dec 20 00:26:47 2000
+++ init.c	Mon Jul  7 04:39:00 2003
@@ -121,7 +121,7 @@
 CONFIG.new_argv = CONFIG.argv;
 
 
-while ((t = getopt_long_only(CONFIG.new_argc
+while ((t = getopt_long(CONFIG.new_argc
                             ,CONFIG.new_argv
                             ,"h"
                             ,long_options
