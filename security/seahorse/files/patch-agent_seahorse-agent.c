--- agent/seahorse-agent.c.orig	Mon Jan 31 11:14:02 2005
+++ agent/seahorse-agent.c	Mon Jan 31 11:14:48 2005
@@ -309,7 +309,6 @@
      * All functions after this point have to print messages 
      * nicely and not just called exit() 
      */
-    daemonize (sockname);
 
     /* Handle some signals */
     signal (SIGINT, on_quit);
@@ -322,6 +321,8 @@
     /* Initialize our sub systems */
     seahorse_agent_actions_init ();
     seahorse_agent_cache_init ();
+
+    daemonize (sockname);
 
     if (seahorse_agent_io_init () == -1)
         return 1;               /* message already printed */
