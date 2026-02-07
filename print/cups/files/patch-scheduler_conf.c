--- scheduler/conf.c.orig	2025-11-27 15:21:54 UTC
+++ scheduler/conf.c
@@ -91,9 +91,7 @@ static const cupsd_var_t	cupsd_vars[] =
 #ifdef HAVE_GSSAPI
   { "GSSServiceName",		&GSSServiceName,	CUPSD_VARTYPE_STRING },
 #endif /* HAVE_GSSAPI */
-#ifdef HAVE_ONDEMAND
   { "IdleExitTimeout",		&IdleExitTimeout,	CUPSD_VARTYPE_TIME },
-#endif /* HAVE_ONDEMAND */
   { "JobKillDelay",		&JobKillDelay,		CUPSD_VARTYPE_TIME },
   { "JobRetryLimit",		&JobRetryLimit,		CUPSD_VARTYPE_INTEGER },
   { "JobRetryInterval",		&JobRetryInterval,	CUPSD_VARTYPE_TIME },
@@ -788,9 +786,7 @@ cupsdReadConfiguration(void)
   DefaultLeaseDuration       = 86400;
   MaxLeaseDuration           = 0;
 
-#ifdef HAVE_ONDEMAND
   IdleExitTimeout = 60;
-#endif /* HAVE_ONDEMAND */
 
   if (!strcmp(CUPS_DEFAULT_PEER_CRED, "off"))
     PeerCred = CUPSD_PEERCRED_OFF;
