--- ldap/servers/slapd/getsocketpeer.c.orig	2026-06-29 19:19:59 UTC
+++ ldap/servers/slapd/getsocketpeer.c
@@ -77,7 +77,7 @@ slapd_get_socket_peer(PRFileDesc *nspr_fd, uid_t *uid,
 
 #elif defined(HAVE_GETPEEREID) /* osx / some BSDs */
 
-    if (0 == getpeereid(fd, &uid, &gid))
+    if (0 == getpeereid(fd, uid, gid))
         ret = 0;
 
 #else /* hpux / Solaris9 / some BSDs - file descriptor cooperative auth */
