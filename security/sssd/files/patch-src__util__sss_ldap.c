--- ./src/util/sss_ldap.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/util/sss_ldap.c	2011-10-13 12:15:03.000000000 -0400
@@ -267,7 +267,7 @@
                   strerror(ret)));
     }
 
-    ret = setsockopt(fd, SOL_TCP, TCP_NODELAY, &dummy, sizeof(dummy));
+    ret = setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &dummy, sizeof(dummy));
     if (ret != 0) {
         ret = errno;
         DEBUG(5, ("setsockopt TCP_NODELAY failed.[%d][%s].\n", ret,
@@ -340,7 +340,7 @@
     DEBUG(9, ("Using file descriptor [%d] for LDAP connection.\n", state->sd));
 
     subreq = sdap_async_sys_connect_send(state, ev, state->sd,
-                                         (struct sockaddr *) addr, addr_len);
+                                         (struct sockaddr *) addr, sizeof(struct sockaddr));
     if (subreq == NULL) {
         ret = ENOMEM;
         DEBUG(1, ("sdap_async_sys_connect_send failed.\n"));
