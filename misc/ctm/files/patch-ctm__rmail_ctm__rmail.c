--- ctm_rmail/ctm_rmail.c.orig	2018-12-23 07:00:45 UTC
+++ ctm_rmail/ctm_rmail.c
@@ -152,6 +152,7 @@ apply_complete()
     char fname[PATH_MAX];
     char here[PATH_MAX];
     char buf[PATH_MAX*2];
+    char *deltanamescheme[] = { "%s.%04d.gz", "%s.%04d.xz", "%s.%05d.gz", "%s.%05d.xz", NULL };
 
     /*
      * Grab a lock on the ctm mutex file so that we can be sure we are
@@ -200,10 +201,16 @@ apply_complete()
      */
     for (;;)
 	{
-	sprintf(delta, "%s.%04d.gz", class, ++dn);
-	mk_delta_name(fname, delta);
+	++dn;
+	for (i=0; deltanamescheme[i]; i++)
+	    {
+	    sprintf(delta, deltanamescheme[i], class, dn);
+	    mk_delta_name(fname, delta);
 
-	if (stat(fname, &sb) < 0)
+	    if (stat(fname, &sb) >= 0)
+	        break;
+	    }
+	if (!deltanamescheme[i])
 	    break;
 
 	sprintf(buf, "(cd %s && ctm %s%s%s%s%s%s) 2>&1", base_dir,
