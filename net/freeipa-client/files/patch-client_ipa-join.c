--- client/ipa-join.c.orig	2025-01-15 10:52:51.570724638 +0100
+++ client/ipa-join.c	2026-08-12 23:05:48.986059000 +0200
@@ -1197,7 +1197,7 @@
 
     if (childpid == 0) {
         char *argv[12];
-        char *path = "/usr/sbin/ipa-getkeytab";
+        char *path = "/usr/local/sbin/ipa-getkeytab";
         int arg = 0;
         int err;
 
@@ -1372,7 +1372,7 @@
     }
     krb5_cc_close(krbctx, ccache);
     ccache = NULL;
-    putenv("KRB5CCNAME=MEMORY:ipa-join");
+    setenv("KRB5CCNAME", "MEMORY:ipa-join", 1);
 
 #ifdef WITH_IPA_JOIN_XML
     rval = xmlrpc_unenroll_host(ipaserver, hostname, quiet);
