--- sid-filter/sid-filter.c.orig	Fri Jul 15 21:15:19 2005
+++ sid-filter/sid-filter.c	Wed Jul 27 19:20:27 2005
@@ -1866,7 +1866,7 @@
 		}
 
 		sid_msgcleanup(ctx);
-		return SMFIS_TEMPFAIL;
+		return (testmode ? SMFIS_ACCEPT : SMFIS_TEMPFAIL);
 	}
 
 	/* construct the status header's content */
@@ -1896,7 +1896,7 @@
 			}
 
 			sid_msgcleanup(ctx);
-			return SMFIS_TEMPFAIL;
+			return (testmode ? SMFIS_ACCEPT : SMFIS_TEMPFAIL);
 		}
 
 		sm_strlcat(stathdr, "; spf=", sizeof stathdr);
