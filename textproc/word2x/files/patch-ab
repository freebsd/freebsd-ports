--- col-align.cc.orig	Fri Jul 24 06:59:12 1998
+++ col-align.cc	Mon Sep 14 10:30:36 1998
@@ -50,7 +50,7 @@
 	}
 	if (strlen(cdp)>(unsigned) max_wd[2])
 	    max_wd[2]=strlen(cdp);
-	for (lt_sp=0, sc=cdp; isspace(*sc); sc++, lt_sp++)
+	for (lt_sp=0, sc=cdp; isspace((unsigned char)*sc); sc++, lt_sp++)
 	{
 	    if (*sc==CH_SUSPECT)
 		align_set=1;
@@ -62,7 +62,7 @@
 	{
 	    if (*sc==CH_SUSPECT)
 		align_set=1;
-	    if (isspace(*sc))
+	    if (isspace((unsigned char)*sc))
 		rt_sp++;
 	    else
 		rt_sp=0;
