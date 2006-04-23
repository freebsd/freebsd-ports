--- sid-filter/sid-filter.c.orig	Tue Apr 18 09:36:23 2006
+++ sid-filter/sid-filter.c	Sun Apr 23 16:48:06 2006
@@ -1893,7 +1893,7 @@
 		else
 		{
 			sid_msgcleanup(ctx);
-			return SMFIS_TEMPFAIL;
+			return (testmode ? SMFIS_ACCEPT : SMFIS_TEMPFAIL);
 		}
 	}
 
@@ -1934,7 +1934,7 @@
 			else
 			{
 				sid_msgcleanup(ctx);
-				return SMFIS_TEMPFAIL;
+				return (testmode ? SMFIS_ACCEPT : SMFIS_TEMPFAIL);
 			}
 		}
 
@@ -1985,7 +1985,7 @@
 		}
 
 		sid_msgcleanup(ctx);
-		return SMFIS_TEMPFAIL;
+		return (testmode ? SMFIS_ACCEPT : SMFIS_TEMPFAIL);
 	}
 
 
