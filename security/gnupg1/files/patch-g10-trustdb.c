Index: security/gnupg1/files/patch-g10-trustdb.c
===================================================================
--- security/gnupg1/files/patch-g10-trustdb.c	(revision 0)
+++ security/gnupg1/files/patch-g10-trustdb.c	(working copy)
@@ -0,0 +1,10 @@
+--- g10/trustdb.c.orig	2013-12-13 08:28:22.000000000 +0100
++++ g10/trustdb.c	2014-05-17 19:47:21.125216457 +0200
+@@ -927,6 +927,7 @@
+   TRUSTREC rec;
+   int rc;
+ 
++  init_trustdb();
+   if (trustdb_args.no_trustdb && opt.trust_model == TM_ALWAYS)
+     return 0;
+ 
