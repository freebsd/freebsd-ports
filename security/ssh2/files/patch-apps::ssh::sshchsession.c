--- apps/ssh/sshchsession.c.orig	Thu Jul  3 00:19:57 2003
+++ apps/ssh/sshchsession.c	Thu Jul  3 00:21:12 2003
@@ -122,6 +122,11 @@
 
 
 
+#if defined (__FreeBSD__) && defined(HAVE_LOGIN_CAP_H)
+#include <login_cap.h>
+#include <sys/copyright.h>
+#endif /* __FreeBSD__ && HAVE_LOGIN_CAP_H */
+
 #define SSH_DEBUG_MODULE "Ssh2ChannelSession"
 
 #define SSH_SESSION_INTERACTIVE_WINDOW                 10000
@@ -487,6 +492,14 @@
   char *user_conf_dir = NULL;
   int i;
 
+#if defined (__FreeBSD__) && defined(HAVE_LOGIN_CAP_H)
+  extern char **environ;
+  char *path, *newpath, **saveenv;
+  struct passwd *pw;
+
+  pw = getpwuid(ssh_user_uid(session->common->user_data));
+#endif /* __FreeBSD__ && HAVE_LOGIN_CAP_H */
+
   user_name = session->common->user;
 
   if (ssh_user_needs_chroot(session->common->user_data, session->common))
@@ -502,7 +515,11 @@
   ssh_child_set_env(envp, envsizep, "HOME", user_dir);
   ssh_child_set_env(envp, envsizep, "USER", user_name);
   ssh_child_set_env(envp, envsizep, "LOGNAME", user_name);
+#ifdef __FreeBSD__
+  ssh_child_set_env(envp, envsizep, "PATH", _PATH_STDPATH SSH_BINDIR);
+#else
   ssh_child_set_env(envp, envsizep, "PATH", DEFAULT_PATH ":" SSH_BINDIR);
+#endif
 
 #ifdef MAIL_SPOOL_DIRECTORY
   ssh_snprintf(buf, sizeof(buf), "%s/%s", MAIL_SPOOL_DIRECTORY, user_name);
@@ -529,6 +546,39 @@
   if (getenv("TZ"))
     ssh_child_set_env(envp, envsizep, "TZ", getenv("TZ"));
 
+#if defined (__FreeBSD__) && defined(HAVE_LOGIN_CAP_H)
+  saveenv = environ;
+  environ = *envp;
+
+  if (setusercontext(NULL, pw, ssh_user_uid(session->common->user_data),
+                     LOGIN_SETPATH | LOGIN_SETENV) == 0)
+    {
+      if ((path = getenv("PATH")) == NULL)
+        newpath = ssh_xstrdup(SSH_BINDIR);
+      else if (strstr(path, SSH_BINDIR) == NULL)
+        ssh_dsprintf(&newpath, "%s:%s", path, SSH_BINDIR);
+      else
+        newpath = ssh_xstrdup(path);
+
+      *envp = environ;
+      environ = saveenv;
+      for (*envsizep = 0; (*envp)[*envsizep] != NULL; (*envsizep)++)
+        ; /* nothing */
+      *envsizep += 51;
+      (*envp) = ssh_xrealloc(*envp, (*envsizep) * sizeof(char *));
+
+      ssh_child_set_env(envp, envsizep, "PATH", newpath);
+      ssh_xfree(newpath);
+    }
+  else
+    {
+      *envp = environ;
+      environ = saveenv;
+      ssh_debug("setusercontext: unable to set user context");
+    }
+    endpwent();
+#endif /* __FreeBSD__ && HAVE_LOGIN_CAP_H */
+
   /* Set SSH_CLIENT. */
   ssh_snprintf(buf, sizeof(buf), "%s %s %s %s",
                session->common->remote_ip, session->common->remote_port,
@@ -632,6 +682,11 @@
   FILE *f;
   char *user_conf_dir = NULL;
 
+#if defined (__FreeBSD__) && defined(HAVE_LOGIN_CAP_H)
+  struct passwd *pw;
+  login_cap_t *lc;
+#endif /* __FreeBSD__ && HAVE_LOGIN_CAP_H */
+
 #ifdef SSH_CHANNEL_X11
   const char *auth_protocol;
   const char *auth_cookie;
@@ -643,6 +698,18 @@
 #endif /* SSH_CHANNEL_X11 */
 
   shell = ssh_user_shell(session->common->user_data);
+#if defined (__FreeBSD__) && defined(HAVE_LOGIN_CAP_H)
+  pw = getpwuid(ssh_user_uid(session->common->user_data));
+  lc = login_getpwclass(pw);
+  if (lc == NULL)
+    ssh_debug("Unable to get login class: %s", session->common->user);
+  else
+    {
+      shell = login_getcapstr(lc, "shell", (char *) shell, (char *) shell);
+      login_close(lc);
+    }
+  endpwent();
+#endif /* __FreeBSD__ && HAVE_LOGIN_CAP_H */
   user_conf_dir = ssh_user_conf_dir(session->common->user_data,
                                     session->common->config);
 
@@ -844,12 +911,24 @@
   extern char **environ;
   unsigned int envsize;
   int i;
-  FILE *f;
+  FILE *f = NULL;
   char *subsystem_path = NULL;
   Boolean needs_chroot = FALSE, run_internal_sftp_server = FALSE;
   const char *chroot_dir = NULL;
   SshUserFDCloseCB close_fds = NULL_FNPTR;
   SshConfig config = session->common->config;
+#if defined (__FreeBSD__) && defined(HAVE_LOGIN_CAP_H)
+  struct passwd *pw;
+  login_cap_t *lc;
+
+  pw = getpwuid(ssh_user_uid(session->common->user_data));
+  lc = login_getpwclass(pw);
+  if (lc == NULL)
+    {
+      ssh_debug("Unable to get login class: %s", session->common->user);
+      exit(254);
+    }
+#endif /* __FreeBSD__ && HAVE_LOGIN_CAP_H */
 
 
 
@@ -865,6 +944,11 @@
 #endif /* HAVE_IF */
   
   /* Check /etc/nologin. */
+#if defined (__FreeBSD__) && defined(HAVE_LOGIN_CAP_H)
+  if (pw->pw_uid != UID_ROOT && !login_getcapbool(lc, "ignorenologin", 0))
+    f = fopen(login_getcapstr(lc, "nologin", _PATH_NOLOGIN, _PATH_NOLOGIN),
+              "r");
+#else /* ! (__FreeBSD && HAVE_LOGIN_CAP_H) */
   if ((f = fopen("/etc/nologin", "r")) == NULL)
     {
       char hname[MAXHOSTNAMELEN];
@@ -877,12 +961,17 @@
       ssh_debug("%s %s.", nologin_path, f ? "exists" : "does not exist");
       ssh_xfree(nologin_path);
     }
+#endif /* __FreeBSD__ && HAVE_LOGIN_CAP_H */
 
   if (f)
     { /* /etc/nologin exists.  Print its contents and exit. */
       /* Print a message about /etc/nologin existing; I am getting
          questions because of this every week. */
+#ifdef __FreeBSD__
+      ssh_warning("Logins are currently denied with " _PATH_NOLOGIN ":");
+#else 
       ssh_warning("Logins are currently denied with /etc/nologin:");
+#endif
       while (fgets(buf, sizeof(buf), f))
         fputs(buf, stderr);
       fclose(f);
@@ -963,8 +1052,8 @@
     {
       if (chdir("/") < 0)
         {
-          ssh_debug("Chroot to user '%s' home directory failed!",
-                    session->common->user);
+          ssh_debug("Chroot to user '%s' home directory failed: %s",
+                    session->common->user, strerror(errno));
           exit(254);
         }
     }
@@ -975,6 +1064,10 @@
           ssh_warning("Could not chdir to home directory %s: %s",
                       ssh_user_dir(session->common->user_data),
                       strerror(errno));
+#if defined (__FreeBSD__) && defined(HAVE_LOGIN_CAP_H)
+          if (login_getcapbool(lc, "requirehome", 0))
+            exit(254);
+#endif /* __FreeBSD__ && HAVE_LOGIN_CAP_H */
           chdir("/");
         }
     }
@@ -1128,6 +1221,12 @@
 
 
           shell = ssh_user_shell(session->common->user_data);
+#if defined (__FreeBSD__) && defined(HAVE_LOGIN_CAP_H)
+          shell = login_getcapstr(lc, "shell", (char *) shell, (char *) shell);
+          login_close(lc);
+          endpwent();
+#endif /* __FreeBSD__ && HAVE_LOGIN_CAP_H */
+
           argv[0] = (char *)shell;
           argv[1] = "-c";
           argv[2] = (char *)session->common->forced_command;
@@ -1158,6 +1257,9 @@
 
   /* Get the user's shell, and the last component of it. */
   shell = ssh_user_shell(session->common->user_data);
+#if defined (__FreeBSD__) && defined(HAVE_LOGIN_CAP_H)
+  shell = login_getcapstr(lc, "shell", (char *) shell, (char *) shell);
+#endif /* __FreeBSD__ && HAVE_LOGIN_CAP_H */
 
   shell_no_path = strrchr(shell, '/');
   if (shell_no_path)
@@ -1188,6 +1290,9 @@
                      (needs_chroot ? "" :
                       ssh_user_dir(session->common->user_data)));
         quiet_login = stat(linebuf, &st) >= 0;
+#if defined (__FreeBSD__) && defined(HAVE_LOGIN_CAP_H)
+        quiet_login |= login_getcapbool(lc, "hushlogin", 0);
+#endif /* __FreeBSD__ && HAVE_LOGIN_CAP_H */
 
         if (!quiet_login)
           {
@@ -1217,11 +1322,28 @@
                 ssh_xfree(time_string);
               }
 #endif /* HAVE_SIA */
+#if defined (__FreeBSD__) && defined(HAVE_LOGIN_CAP_H)
+            SSH_DEBUG(7, ("Printing copyright."));
+            f = fopen(login_getcapstr(lc, "copyright", NULL, NULL), "r");
+            if (f)
+              {
+                while (fgets(linebuf, sizeof(linebuf), f) != NULL)
+                  fputs(linebuf, stdout);
+                fclose(f);
+              }
+            else
+              fputs(COPYRIGHT_UCB "\n", stdout);
+#endif /* __FreeBSD__ && HAVE_LOGIN_CAP_H */
             /* print motd, if "PrintMotd yes" and it exists */
             if (config->print_motd)
               {
                 SSH_DEBUG(7, ("Printing MOTD."));
+#if defined (__FreeBSD__) && defined(HAVE_LOGIN_CAP_H)
+                f = fopen(login_getcapstr(lc, "welcome", "/etc/motd",
+                                          "/etc/motd"), "r");
+#else /* ! (__FreeBSD && HAVE_LOGIN_CAP_H) */
                 f = fopen("/etc/motd", "r");
+#endif /* __FreeBSD__ && HAVE_LOGIN_CAP_H */
                 if (f)
                   {
                     while (fgets(linebuf, sizeof(linebuf), f))
@@ -1239,7 +1361,11 @@
                   {
                     struct stat mailbuf;
                     if (stat(mailbox, &mailbuf) == -1 || mailbuf.st_size == 0)
+#ifndef __FreeBSD__
                       printf("No mail.\n");
+#else
+                      ; /* nothing */
+#endif
                     else if (mailbuf.st_atime > mailbuf.st_mtime)
                       printf("You have mail.\n");
                     else
@@ -1248,6 +1374,11 @@
               }
           }
       }
+
+#if defined (__FreeBSD__) && defined(HAVE_LOGIN_CAP_H)
+      login_close(lc);
+      endpwent();
+#endif /* __FreeBSD__ && HAVE_LOGIN_CAP_H */
 
       execve(shell, argv, env);
       /* Executing the shell failed. */
