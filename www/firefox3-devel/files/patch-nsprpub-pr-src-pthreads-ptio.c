--- nsprpub/pr/src/pthreads/ptio.c.orig	Tue Jul  8 23:37:46 2003
+++ nsprpub/pr/src/pthreads/ptio.c	Wed Jul 23 00:53:15 2003
@@ -3370,7 +3370,7 @@
 PR_EXTERN(PRStatus) _pr_push_ipv6toipv4_layer(PRFileDesc *fd);
 #if defined(_PR_INET6_PROBE)
 PR_EXTERN(PRBool) _pr_ipv6_is_present;
-#ifdef DARWIN
+#if defined(DARWIN) || defined(FREEBSD)
 static PRBool _pr_ipv6_v6only_on_by_default;
 #endif
 PR_IMPLEMENT(PRBool) _pr_test_ipv6_socket()
@@ -3385,7 +3385,7 @@
      */
     osfd = socket(AF_INET6, SOCK_STREAM, 0);
     if (osfd != -1) {
-#ifdef DARWIN
+#if defined(DARWIN) || defined(FREEBSD)
         /* In Mac OS X v10.3 Panther Beta the IPV6_V6ONLY socket option
          * is turned on by default, contrary to what RFC 3493, Section
          * 5.3 says.  So we have to turn it off.  Find out whether we
@@ -3452,7 +3452,7 @@
     if (osfd == -1) pt_MapError(_PR_MD_MAP_SOCKET_ERROR, errno);
     else
     {
-#ifdef DARWIN
+#if defined(DARWIN) || defined(FREEBSD)
         if ((domain == AF_INET6) && _pr_ipv6_v6only_on_by_default)
         {
             int on = 0;
