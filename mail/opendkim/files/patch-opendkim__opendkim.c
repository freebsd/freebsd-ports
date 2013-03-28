--- ./opendkim/opendkim.c.orig	2013-03-20 03:02:40.000000000 +0900
+++ ./opendkim/opendkim.c	2013-03-21 02:47:29.000000000 +0900
@@ -12421,7 +12421,7 @@
 			{
 				syslog(LOG_INFO,
 				       "%s: can't parse default sender value '%s'",
-				       dfc->mctx_jobid, from);
+				       dfc->mctx_jobid, conf->conf_defsender);
 			}
 #endif /* _FFR_DEFAULT_SENDER */
 		}
@@ -14945,8 +14945,8 @@
 				for (c = 0; c < nsigs && domain == NULL; c++)
 				{
 					if ((dkim_sig_getflags(sigs[c]) & DKIM_SIGFLAG_PASSED) == 0 ||
-					    (dkim_sig_getflags(sigs[c]) & DKIM_SIGFLAG_TESTKEY) != 0 &&
-					    dkim_sig_getbh(sigs[c]) != DKIM_SIGBH_MATCH)
+					    ((dkim_sig_getflags(sigs[c]) & DKIM_SIGFLAG_TESTKEY) != 0 &&
+					    dkim_sig_getbh(sigs[c]) != DKIM_SIGBH_MATCH))
 						continue;
 
 					cd = dkim_sig_getdomain(sigs[c]);
@@ -15121,8 +15121,8 @@
 				for (c = 0; c < nsigs; c++)
 				{
 					if ((dkim_sig_getflags(sigs[c]) & DKIM_SIGFLAG_PASSED) == 0 ||
-					    (dkim_sig_getflags(sigs[c]) & DKIM_SIGFLAG_TESTKEY) != 0 &&
-					    dkim_sig_getbh(sigs[c]) != DKIM_SIGBH_MATCH)
+					    ((dkim_sig_getflags(sigs[c]) & DKIM_SIGFLAG_TESTKEY) != 0 &&
+					    dkim_sig_getbh(sigs[c]) != DKIM_SIGBH_MATCH))
 						continue;
 
 					checked = TRUE;
