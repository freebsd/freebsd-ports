--- cpdup.c.orig	2008-04-14 07:40:51.000000000 +0200
+++ cpdup.c	2008-09-25 12:44:04.011824830 +0200
@@ -634,6 +634,11 @@
 	r = 0;
 	goto done;
     }
+#ifdef SF_SNAPSHOT
+    /* skip snapshot files because they're sparse and _huge_ */
+    if (st1.st_flags & SF_SNAPSHOT)
+       return(0);
+#endif
     st2.st_mode = 0;	/* in case lstat fails */
     st2.st_flags = 0;	/* in case lstat fails */
     if (dpath && hc_lstat(&DstHost, dpath, &st2) == 0)
