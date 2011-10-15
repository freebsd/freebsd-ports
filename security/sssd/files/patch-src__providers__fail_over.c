--- ./src/providers/fail_over.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/providers/fail_over.c	2011-10-13 12:15:03.000000000 -0400
@@ -1191,7 +1191,7 @@
  *******************************************************************/
 struct resolve_get_domain_state {
     char *fqdn;
-    char hostname[HOST_NAME_MAX];
+    char hostname[_POSIX_HOST_NAME_MAX];
 };
 
 static void resolve_get_domain_done(struct tevent_req *subreq);
@@ -1211,13 +1211,13 @@
         return NULL;
     }
 
-    ret = gethostname(state->hostname, HOST_NAME_MAX);
+    ret = gethostname(state->hostname, _POSIX_HOST_NAME_MAX);
     if (ret) {
         ret = errno;
         DEBUG(2, ("gethostname() failed: [%d]: %s\n",ret, strerror(ret)));
         return NULL;
     }
-    state->hostname[HOST_NAME_MAX-1] = '\0';
+    state->hostname[_POSIX_HOST_NAME_MAX-1] = '\0';
     DEBUG(7, ("Host name is: %s\n", state->hostname));
 
     subreq = resolv_gethostbyname_send(state, ev, resolv,
