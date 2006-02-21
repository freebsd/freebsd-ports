--- mod_backhand.c.orig	Tue Feb 21 00:42:40 2006
+++ mod_backhand.c	Tue Feb 21 00:43:24 2006
@@ -427,6 +427,7 @@
   mbcfg *cfg = (mbcfg *) mconfig;
   struct cpd *newfunc;
   cfg->local = 1;
+  ap_os_dso_error();
   handle = ap_os_dso_load(szFilename);
   if(!handle)
     return ap_os_dso_error();
