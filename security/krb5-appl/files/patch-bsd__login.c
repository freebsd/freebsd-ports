--- bsd/login.c.orig	2009-11-21 12:29:19.000000000 -0800
+++ bsd/login.c	2011-08-31 21:56:02.581035877 -0700
@@ -86,7 +86,12 @@
 #include <netdb.h>
 
 #include <time.h>
+#ifdef HAVE_UTMP_H
 #include <utmp.h>
+#endif
+#ifdef HAVE_UTMPX_H
+#include <utmpx.h>
+#endif
 #include <signal.h>
 
 #include <assert.h>
@@ -225,8 +230,13 @@
 #endif
 #ifndef UT_NAMESIZE
 /* linux defines it directly in <utmp.h> */
+#ifdef HAVE_UTMP_H
 #define	UT_NAMESIZE	sizeof(((struct utmp *)0)->ut_name)
 #endif
+#ifdef HAVE_UTMPX_H
+#define	UT_NAMESIZE	sizeof(((struct utmpx *)0)->ut_user)
+#endif
+#endif
 
 #ifndef HAVE_SETPRIORITY
 /* if we don't have it, punt it cleanly */
@@ -964,19 +974,6 @@
 		setpriority(PRIO_PROCESS, 0, 0 + PRIO_OFFSET);
 	    }
 
-	    /* Policy: If local password is good, user is good.
-	       We really can't trust the Kerberos password,
-	       because somebody on the net could spoof the
-	       Kerberos server (not easy, but possible).
-	       Some sites might want to use it anyways, in
-	       which case they should change this line
-	       to:
-	       if (kpass_ok)
-	    */
-
-	    if (lpass_ok)
-		break;
-
 	    if (got_v5_tickets) {
 		retval = krb5_verify_init_creds(kcontext, &my_creds, NULL,
 						NULL, &xtra_creds,
@@ -993,6 +990,9 @@
 		}
 	    }
 
+	    if (lpass_ok)
+		break;
+
 	bad_login:
 	    setpriority(PRIO_PROCESS, 0, 0 + PRIO_OFFSET);
 
@@ -1250,21 +1250,23 @@
 	/* set up credential cache -- obeying KRB5_ENV_CCNAME 
 	   set earlier */
 	/* (KRB5_ENV_CCNAME == "KRB5CCNAME" via osconf.h) */
-	if ((retval = krb5_cc_default(kcontext, &ccache))) {
+	if ((retval = krb5_cc_default(kcontext, &ccache)))
 	    com_err(argv[0], retval, "while getting default ccache");
-	} else if ((retval = krb5_cc_initialize(kcontext, ccache, me))) {
-	    com_err(argv[0], retval, "when initializing cache");
-	} else if ((retval = krb5_cc_store_cred(kcontext, ccache, 
-						&my_creds))) {
-	    com_err(argv[0], retval, "while storing credentials");
-	} else if (xtra_creds &&
-		   (retval = krb5_cc_copy_creds(kcontext, xtra_creds,
-						ccache))) {
-	    com_err(argv[0], retval, "while storing credentials");
+	else {
+	    if (retval = krb5_cc_initialize(kcontext, ccache, me))
+		com_err(argv[0], retval, "when initializing cache");
+	    else {
+		if (retval = krb5_cc_store_cred(kcontext, ccache, &my_creds))
+		    com_err(argv[0], retval, "while storing credentials");
+		else  {
+		    if (xtra_creds &&
+				(retval = krb5_cc_copy_creds(kcontext, xtra_creds, ccache))) {
+			com_err(argv[0], retval, "while storing credentials");
+			krb5_cc_destroy(kcontext, xtra_creds);
+		    }
+		}
+	    }
 	}
-
-	if (xtra_creds)
-	    krb5_cc_destroy(kcontext, xtra_creds);
     } else if (forwarded_v5_tickets && rewrite_ccache) {
 	if ((retval = krb5_cc_initialize (kcontext, ccache, me))) {
 	    syslog(LOG_ERR,
@@ -1322,6 +1324,7 @@
 
     if (ccname)
 	setenv("KRB5CCNAME", ccname, 1);
+    krb5_cc_set_default_name(kcontext, ccname);
 
     setenv("HOME", pwd->pw_dir, 1);
     setenv("PATH", LPATH, 0);
@@ -1652,6 +1655,7 @@
      int quiet;
      char *tty;
 {
+#if !(defined(__FreeBSD_version)) || (defined(__FreeBSD_version) && (__FreeBSD_version <= 900007))
 #if defined(HAVE_LASTLOG_H) || (defined(BSD) && (BSD >= 199103))
     struct lastlog ll;
     time_t lltime;
@@ -1692,6 +1696,7 @@
 	(void)close(fd);
     }
 #endif
+#endif
 }
 
 #undef	UNKNOWN
