--- sid-filter/sid-filter.c.orig	Fri Dec  3 01:06:22 2004
+++ sid-filter/sid-filter.c	Sat Dec 18 22:08:31 2004
@@ -857,7 +857,7 @@
 				if (dolog)
 				{
 					syslog(LOG_ERR,
-					       "%s DNS reply garbled (%d %s)",
+					       "%s DNS reply garbled expand1 (%d %s)",
 					       sic->ctx_jobid, type, dd);
 				}
 
@@ -876,8 +876,11 @@
 			if (dolog)
 			{
 				syslog(LOG_ERR,
-				       "%s DNS reply garbled (%d %s)",
+				       "%s DNS reply garbled type1 (%d %s)",
 				       sic->ctx_jobid, type, dd);
+				syslog(LOG_ERR,
+				       "rtype=%d, type=%d, class=%d, expected=%d",
+				       rtype, type, class, (int)C_IN);
 			}
 
 			return -1;
@@ -905,7 +908,7 @@
 				if (dolog)
 				{
 					syslog(LOG_ERR,
-					       "%s DNS reply garbled (%d %s)",
+					       "%s DNS reply garbled expand2 (%d %s)",
 					       sic->ctx_jobid, type, dd);
 				}
 
@@ -918,7 +921,7 @@
 				if (dolog)
 				{
 					syslog(LOG_ERR,
-					       "%s DNS reply garbled (%d %s)",
+					       "%s DNS reply garbled cp1 (%d %s)",
 					       sic->ctx_jobid, type, dd);
 				}
 
@@ -932,7 +935,7 @@
 				if (dolog)
 				{
 					syslog(LOG_ERR,
-					       "%s DNS reply garbled (%d %s)",
+					       "%s DNS reply garbled type2 (%d %s)",
 					       sic->ctx_jobid, type, dd);
 				}
 
@@ -948,7 +951,7 @@
 				if (dolog)
 				{
 					syslog(LOG_ERR,
-					       "%s DNS reply garbled (%d %s)",
+					       "%s DNS reply garbled cp2 (%d %s)",
 					       sic->ctx_jobid, type, dd);
 				}
 
@@ -961,7 +964,7 @@
 				if (dolog)
 				{
 					syslog(LOG_ERR,
-					       "%s DNS reply garbled (%d %s)",
+					       "%s DNS reply garbled cp3 (%d %s)",
 					       sic->ctx_jobid, type, dd);
 				}
 
@@ -999,7 +1002,7 @@
 					if (dolog)
 					{
 						syslog(LOG_ERR,
-						       "%s DNS reply garbled (%d %s)",
+						       "%s DNS reply garbled mx (%d %s)",
 						       sic->ctx_jobid, type,
 						       dd);
 					}
@@ -1018,7 +1021,7 @@
 					if (dolog)
 					{
 						syslog(LOG_ERR,
-						       "%s DNS reply garbled (%d %s)",
+						       "%s DNS reply garbled mx expand (%d %s)",
 						       sic->ctx_jobid, type,
 						       dd);
 					}
@@ -1047,7 +1050,7 @@
 					if (dolog)
 					{
 						syslog(LOG_ERR,
-						       "%s DNS reply garbled (%d %s)",
+						       "%s DNS reply garbled ptr (%d %s)",
 						       sic->ctx_jobid, type,
 						       dd);
 					}
@@ -1073,7 +1076,7 @@
 		/* sort MX list */
 		for (n = 0; n < nmx; n++)
 		{
-			if (prec[n] > prec[n + 1])
+			if ((n + 1 < nmx) && prec[n] > prec[n + 1])
 			{
 				m = prec[n];
 				prec[n] = prec[n + 1];
@@ -1772,7 +1775,7 @@
 		}
 
 		sid_msgcleanup(ctx);
-		return SMFIS_TEMPFAIL;
+		return (testmode ? SMFIS_ACCEPT : SMFIS_TEMPFAIL);
 	}
 
 	/* construct the status header's content */
@@ -1801,7 +1804,7 @@
 			}
 
 			sid_msgcleanup(ctx);
-			return SMFIS_TEMPFAIL;
+			return (testmode ? SMFIS_ACCEPT : SMFIS_TEMPFAIL);
 		}
 
 		sm_strlcat(stathdr, "; spf=", sizeof stathdr);
