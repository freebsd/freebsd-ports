Index: security/gnupg1/files/patch-g10-trustdb.c
===================================================================
--- security/gnupg1/files/patch-g10-trustdb.c.orig	2016-06-17 21:55:32 UTC
+++ security/gnupg1/files/patch-g10-trustdb.c
@@ -0,0 +1,10 @@
+--- g10/trustdb.c.orig	2013-12-13 08:28:22.000000000 +0100
++++ g10/trustdb.c
+@@ -927,6 +927,7 @@
+   TRUSTREC rec;
+   int rc;
+ 
++  init_trustdb();
+   if (trustdb_args.no_trustdb && opt.trust_model == TM_ALWAYS)
+     return 0;
+ 
