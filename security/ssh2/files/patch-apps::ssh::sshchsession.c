--- apps/ssh/sshchsession.c.orig	Thu Jul  3 00:19:57 2003
+++ apps/ssh/sshchsession.c	Thu Jul  3 00:21:12 2003
@@ -218,8 +218,8 @@
 #ifdef _PATH_USERPATH
 #define DEFAULT_PATH            _PATH_USERPATH
 #else
-#ifdef _PATH_DEFPATH
-#define DEFAULT_PATH            _PATH_DEFPATH
+#ifdef _PATH_STDPATH
+#define DEFAULT_PATH            _PATH_STDPATH
 #else
 #define DEFAULT_PATH    "/bin:/usr/bin:/usr/ucb:/usr/bin/X11:/usr/local/bin"
 #endif
@@ -502,7 +502,7 @@
   ssh_child_set_env(envp, envsizep, "HOME", user_dir);
   ssh_child_set_env(envp, envsizep, "USER", user_name);
   ssh_child_set_env(envp, envsizep, "LOGNAME", user_name);
-  ssh_child_set_env(envp, envsizep, "PATH", DEFAULT_PATH ":" SSH_BINDIR);
+  ssh_child_set_env(envp, envsizep, "PATH", DEFAULT_PATH SSH_BINDIR);
 
 #ifdef MAIL_SPOOL_DIRECTORY
   ssh_snprintf(buf, sizeof(buf), "%s/%s", MAIL_SPOOL_DIRECTORY, user_name);
