--- utmp.c.orig	2014-04-26 09:22:09.000000000 -0700
+++ utmp.c	2014-04-29 19:42:22.660642853 -0700
@@ -409,12 +409,6 @@
   register slot_t slot;
   struct utmp u;
   int saved_ut;
-#ifdef UTHOST
-  char *p;
-  char host[sizeof(D_loginhost) + 15];
-#else
-  char *host = 0;
-#endif /* UTHOST */
 
   wi->w_slot = (slot_t)0;
   if (!utmpok || wi->w_type != W_TYPE_PTY)
@@ -435,51 +429,12 @@
     makeuser(&u, stripdev(wi->w_tty), LoginName, wi->w_pid);
 
 #ifdef UTHOST
-  host[sizeof(host) - 15] = '\0';
-  if (display)
-    {
-      strncpy(host, D_loginhost, sizeof(host) - 15);
-      if (D_loginslot != (slot_t)0 && D_loginslot != (slot_t)-1 && host[0] != '\0')
-	{
-	  /*
-	   * we want to set our ut_host field to something like
-	   * ":ttyhf:s.0" or
-	   * "faui45:s.0" or
-	   * "132.199.81.4:s.0" (even this may hurt..), but not
-	   * "faui45.informati"......:s.0
-	   * HPUX uses host:0.0, so chop at "." and ":" (Eric Backus)
-	   */
-	  for (p = host; *p; p++)
-	    if ((*p < '0' || *p > '9') && (*p != '.'))
-	      break;
-	  if (*p)
-	    {
-	      for (p = host; *p; p++)
-		if (*p == '.' || (*p == ':' && p != host))
-		  {
-		    *p = '\0';
-		    break;
-		  }
-	    }
-	}
-      else
-	{
-	  strncpy(host + 1, stripdev(D_usertty), sizeof(host) - 15 - 1);
-	  host[0] = ':';
-	}
-    }
-  else
-    strncpy(host, "local", sizeof(host) - 15);
-
-  sprintf(host + strlen(host), ":S.%d", wi->w_number);
-  debug1("rlogin hostname: '%s'\n", host);
-
 # if !defined(_SEQUENT_) && !defined(sequent)
-  strncpy(u.ut_host, host, sizeof(u.ut_host));
+  strncpy(u.ut_host, D_loginhost, sizeof(u.ut_host));
 # endif
 #endif /* UTHOST */
 
-  if (pututslot(slot, &u, host, wi) == 0)
+  if (pututslot(slot, &u, D_loginhost, wi) == 0)
     {
       Msg(errno,"Could not write %s", UtmpName);
       UT_CLOSE;
@@ -598,7 +553,7 @@
 struct utmp *u;
 {
   u->ut_type = DEAD_PROCESS;
-#if (!defined(linux) || defined(EMPTY)) && !defined(__CYGWIN__)
+#if (!defined(linux) || defined(EMPTY)) && !defined(__CYGWIN__) && !defined(__FreeBSD__)
   u->ut_exit.e_termination = 0;
   u->ut_exit.e_exit = 0;
 #endif
