--- popper/pop_pass.c.orig	Sat Jun  2 02:24:13 2001
+++ popper/pop_pass.c	Sat Sep  8 00:26:27 2001
@@ -1226,6 +1226,18 @@
         return ( pop_msg ( p, POP_FAILURE, HERE, ERRMSG_PW, p->user ) );
     }
 
+#    ifdef FREEBSD
+
+    /*
+     * Nor from expired accounts
+     */
+    if (pw->pw_expire != 0 && pw->pw_expire <= time(NULL)) {
+        sleep  ( SLEEP_SECONDS );
+	return ( pop_msg ( p, POP_FAILURE, HERE, ERRMSG_ACEXP, p->user ) );
+    }
+
+#    endif /* FreeBSD */
+
     return ( POP_SUCCESS );
 }
 
