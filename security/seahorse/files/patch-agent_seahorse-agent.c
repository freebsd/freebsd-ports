--- agent/seahorse-agent.c.orig	Sun Feb 13 19:43:53 2005
+++ agent/seahorse-agent.c	Fri Mar 11 22:20:26 2005
@@ -265,7 +265,6 @@
     int ch = 0;
     const char *sockname;
 
-    secmem_init (65536);
 
     /* We need to drop privileges completely for security */
 #if defined(HAVE_SETRESUID) && defined(HAVE_SETRESGID)
@@ -273,10 +272,12 @@
     /* Not in header files for all OSs, even where present */
     int setresuid(uid_t ruid, uid_t euid, uid_t suid);
     int setresgid(gid_t rgid, gid_t egid, gid_t sgid);
+    secmem_init (65536);
   
     if (setresuid (getuid (), getuid (), getuid ()) == -1 ||
         setresgid (getgid (), getgid (), getgid ()) == -1)
 #else
+    secmem_init (65536);
     if (setuid (getuid ()) == -1 || setgid (getgid ()) == -1)
 #endif
         err (1, _("couldn't drop privileges properly"));
@@ -320,7 +321,6 @@
      * All functions after this point have to print messages 
      * nicely and not just called exit() 
      */
-    daemonize (sockname);
 
     /* Handle some signals */
     signal (SIGINT, on_quit);
@@ -333,6 +333,8 @@
     /* Initialize our sub systems */
     seahorse_agent_actions_init ();
     seahorse_agent_cache_init ();
+
+    daemonize (sockname);
 
     if (seahorse_agent_io_init () == -1)
         return 1;               /* message already printed */
