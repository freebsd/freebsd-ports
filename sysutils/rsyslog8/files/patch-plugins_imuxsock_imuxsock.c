--- plugins/imuxsock/imuxsock.c.orig	2018-04-08 11:15:54 UTC
+++ plugins/imuxsock/imuxsock.c
@@ -180,6 +180,13 @@ static int sd_fds = 0;			/* number of sy
 #define DFLT_ratelimitInterval 0
 #define DFLT_ratelimitBurst 200
 #define DFLT_ratelimitSeverity 1			/* do not rate-limit emergency messages */
+
+#ifdef ENABLE_IMUXSOCK_RFC5424
+#define DFLT_bUseSpecialParser 0			/* assumes syslog(3) generates RFC5424 format */
+#else
+#define DFLT_bUseSpecialParser 1			/* assumes syslog(3) generates RFC3164 format */
+#endif
+
 /* config vars for the legacy config system */
 static struct configSettings_s {
 	int bOmitLocalLogging;
@@ -323,7 +330,7 @@ createInstance(instanceConf_t **pinst)
 	inst->ratelimitBurst = DFLT_ratelimitBurst;
 	inst->ratelimitSeverity = DFLT_ratelimitSeverity;
 	inst->bUseFlowCtl = 0;
-	inst->bUseSpecialParser = 1;
+	inst->bUseSpecialParser = DFLT_bUseSpecialParser;
 	inst->bParseHost = UNSET;
 	inst->bIgnoreTimestamp = 1;
 	inst->bCreatePath = DFLT_bCreatePath;
@@ -1243,7 +1250,7 @@ CODESTARTbeginCnfLoad
 	pModConf->bAnnotateSysSock = 0;
 	pModConf->bParseTrusted = 0;
 	pModConf->bParseHost = UNSET;
-	pModConf->bUseSpecialParser = 1;
+	pModConf->bUseSpecialParser = DFLT_bUseSpecialParser;
 	/* if we do not process internal messages, we will see messages
 	 * from ourselves, and so we need to permit this.
 	 */
