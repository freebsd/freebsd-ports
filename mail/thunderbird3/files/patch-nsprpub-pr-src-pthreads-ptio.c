--- nsprpub/pr/src/pthreads/ptio.c.orig	Mon Jul 14 17:59:47 2003
+++ nsprpub/pr/src/pthreads/ptio.c	Fri Aug 29 15:39:46 2003
@@ -189,7 +189,7 @@
 #endif
 #endif
 
-#ifdef DARWIN
+#if defined(DARWIN) || defined(FREEBSD)
 static PRBool _pr_ipv6_v6only_on_by_default;
 /* The IPV6_V6ONLY socket option is not defined on Mac OS X 10.1. */
 #ifndef IPV6_V6ONLY
@@ -1154,7 +1154,7 @@
     _pr_stderr = pt_SetMethods(2, PR_DESC_FILE, PR_FALSE, PR_TRUE);
     PR_ASSERT(_pr_stdin && _pr_stdout && _pr_stderr);
 
-#ifdef DARWIN
+#if defined(DARWIN) || defined(FREEBSD)
     /* In Mac OS X v10.3 Panther Beta the IPV6_V6ONLY socket option
      * is turned on by default, contrary to what RFC 3493, Section
      * 5.3 says.  So we have to turn it off.  Find out whether we
@@ -3462,7 +3462,7 @@
     if (osfd == -1) pt_MapError(_PR_MD_MAP_SOCKET_ERROR, errno);
     else
     {
-#ifdef DARWIN
+#if defined(DARWIN) || defined(FREEBSD)
         if ((domain == AF_INET6) && _pr_ipv6_v6only_on_by_default)
         {
             int on = 0;
