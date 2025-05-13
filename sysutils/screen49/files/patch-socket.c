--- socket.c.orig	2025-05-13 14:58:03 UTC
+++ socket.c
@@ -171,8 +171,13 @@ bool *is_sock;
   xsetegid(real_gid);
 #endif
 
-  if ((dirp = opendir(SockPath)) == 0)
-    Panic(errno, "Cannot opendir %s", SockPath);
+  if ((dirp = opendir(SockPath)) == 0) {
+    if (eff_uid == real_uid) {
+      Panic(errno, "Cannot opendir %s", SockPath);
+    } else {
+      Panic(0, "Error accessing %s", SockPath);
+    }
+  }
 
   slist = 0;
   slisttail = &slist;
@@ -841,6 +846,11 @@ int pid;
   return UserStatus();
 }
 
+static void KillUnpriv(pid_t pid, int sig) {
+    UserContext();
+    UserReturn(kill(pid, sig));
+}
+
 #ifdef hpux
 /*
  * From: "F. K. Bruner" <napalm@ugcs.caltech.edu>
@@ -926,14 +936,14 @@ struct win *wi;
             {
 	      Msg(errno, "Could not perform necessary sanity checks on pts device.");
 	      close(i);
-	      Kill(pid, SIG_BYE);
+	      KillUnpriv(pid, SIG_BYE);
 	      return -1;
             }
           if (strcmp(ttyname_in_ns, m->m_tty))
             {
 	      Msg(errno, "Attach: passed fd does not match tty: %s - %s!", ttyname_in_ns, m->m_tty[0] != '\0' ? m->m_tty : "(null)");
 	      close(i);
-	      Kill(pid, SIG_BYE);
+	      KillUnpriv(pid, SIG_BYE);
 	      return -1;
 	    }
 	  /* m->m_tty so far contains the actual name of the pts device in the
@@ -950,19 +960,19 @@ struct win *wi;
 	{
 	  Msg(errno, "Attach: passed fd does not match tty: %s - %s!", m->m_tty, myttyname ? myttyname : "NULL");
 	  close(i);
-	  Kill(pid, SIG_BYE);
+	  KillUnpriv(pid, SIG_BYE);
 	  return -1;
 	}
     }
   else if ((i = secopen(m->m_tty, O_RDWR | O_NONBLOCK, 0)) < 0)
     {
       Msg(errno, "Attach: Could not open %s!", m->m_tty);
-      Kill(pid, SIG_BYE);
+      KillUnpriv(pid, SIG_BYE);
       return -1;
     }
 #ifdef MULTIUSER
   if (attach)
-    Kill(pid, SIGCONT);
+    KillUnpriv(pid, SIGCONT);
 #endif
 
 #if defined(ultrix) || defined(pyr) || defined(NeXT)
@@ -975,7 +985,7 @@ struct win *wi;
 	{
 	  write(i, "Attaching from inside of screen?\n", 33);
 	  close(i);
-	  Kill(pid, SIG_BYE);
+	  KillUnpriv(pid, SIG_BYE);
 	  Msg(0, "Attach msg ignored: coming from inside.");
 	  return -1;
 	}
@@ -986,7 +996,7 @@ struct win *wi;
 	  {
 	      write(i, "Access to session denied.\n", 26);
 	      close(i);
-	      Kill(pid, SIG_BYE);
+	      KillUnpriv(pid, SIG_BYE);
 	      Msg(0, "Attach: access denied for user %s.", user);
 	      return -1;
 	  }
@@ -1304,7 +1314,7 @@ ReceiveMsg()
             Msg(0, "Query attempt with bad pid(%d)!", m.m.command.apid);
           }
           else {
-            Kill(m.m.command.apid,
+            KillUnpriv(m.m.command.apid,
                (queryflag >= 0)
                    ? SIGCONT
                    : SIG_BYE); /* Send SIG_BYE if an error happened */
