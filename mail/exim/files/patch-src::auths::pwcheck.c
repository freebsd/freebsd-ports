--- src/auths/pwcheck.c.orig	Wed Sep 10 16:33:51 2003
+++ src/auths/pwcheck.c	Wed Sep 10 16:34:53 2003
@@ -210,7 +210,8 @@
                          CYRUS_SASLAUTHD_SOCKET, strerror(errno));
        if (reply)
            *reply = string_sprintf("cannot connect to saslauthd daemon at "
-                                   "%s: %s", strerror(errno));
+                                   "%s: %s", CYRUS_SASLAUTHD_SOCKET,
+                                   strerror(errno));
        return PWCHECK_FAIL;
     }
 
