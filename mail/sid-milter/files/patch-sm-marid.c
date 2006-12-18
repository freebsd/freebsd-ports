--- libmarid/sm-marid.c.bak	Tue Aug 17 04:50:54 2004
+++ libmarid/sm-marid.c	Sun Dec 17 17:37:36 2006
@@ -22,7 +22,8 @@
 char const * const
 sm_marid_version_patterns_01[] = { "spf2.%d/pra%,%v", 	NULL };
 char const * const
-sm_marid_version_patterns_any[] = { "v=spf1", "spf2.%d/pra%,%v", NULL };
+sm_marid_version_patterns_any[] = { "v=spf1", "spf2.%d/pra%,%v", \
+				    "spf2.%d/mfrom,pra%,%v", NULL };
 
 /*
 **  MARID_DEFAULT_FREE -- default free callback if application passes NULL. 
