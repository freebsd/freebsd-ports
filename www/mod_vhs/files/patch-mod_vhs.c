--- ./mod_vhs.c.orig	2010-06-03 00:47:05.980134731 -0400
+++ ./mod_vhs.c	2010-06-03 00:48:23.301960660 -0400
@@ -216,16 +216,7 @@
 	const char     *real;
 	const char     *fake;
 	char           *handler;
-
-#if APR_MAJOR_VERSION > 0
-	ap_regex_t     *regexp;
-#else
-#ifdef DEBIAN
 	ap_regex_t     *regexp;
-#else
-	regex_t        *regexp;
-#endif				/* DEBIAN */
-#endif
 	int		redir_status;	/* 301, 302, 303, 410, etc... */
 }		alias_entry;
 
@@ -334,11 +325,7 @@
 	/* XX r can NOT be relative to DocumentRoot here... compat bug. */
 
 	if (use_regex) {
-#ifdef DEBIAN
 		new->regexp = ap_pregcomp(cmd->pool, f, AP_REG_EXTENDED);
-#else
-		new->regexp = ap_pregcomp(cmd->pool, f, REG_EXTENDED);
-#endif /* DEBIAN */
 		if (new->regexp == NULL)
 			return "Regular expression could not be compiled.";
 		new->real = r;
@@ -403,15 +390,7 @@
 	vhs_config_rec *serverconf = ap_get_module_config(s->module_config,
 							  &vhs_module);
 	int		status = (int)(long)cmd->info;
-#if APR_MAJOR_VERSION > 0
 	ap_regex_t     *r = NULL;
-#else
-#ifdef DEBIAN
-	ap_regex_t     *r = NULL;
-#else
-	regex_t        *r = NULL;
-#endif				/* DEBIAN */
-#endif
 	const char     *f = arg2;
 	const char     *url = arg3;
 
@@ -431,11 +410,7 @@
 	}
 
 	if (use_regex) {
-#ifdef DEBIAN
 		r = ap_pregcomp(cmd->pool, f, AP_REG_EXTENDED);
-#else
-		r = ap_pregcomp(cmd->pool, f, REG_EXTENDED);
-#endif /* DEBIAN */
 		if (r == NULL)
 			return "Regular expression could not be compiled.";
 	}
@@ -531,11 +506,7 @@
 	       int doesc, int *status)
 {
 	alias_entry    *entries = (alias_entry *) aliases->elts;
-#ifdef DEBIAN
 	ap_regmatch_t	regm [AP_MAX_REG_MATCH];
-#else
-	regmatch_t	regm [AP_MAX_REG_MATCH];
-#endif  /* DEBIAN */
 	char           *found = NULL;
 	int		i;
 
