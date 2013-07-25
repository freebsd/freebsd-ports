--- lib/tpm_utils.c.orig	2010-02-02 02:17:23.000000000 +0900
+++ lib/tpm_utils.c	2013-07-24 22:00:15.000000000 +0900
@@ -55,6 +55,7 @@
 	CmdHelpFunction  tCmdHelp = ( a_tCmdHelpFunction ) ? a_tCmdHelpFunction
 							   : logCmdHelp;
 
+#ifdef __GCC
 	char  szShortOpts[strlen( pszGenShortOpts )
 			  + ( ( a_pszShortOpts == NULL ) ? 0 : strlen( a_pszShortOpts ) )
 			  + 1];
@@ -64,12 +65,36 @@
 
 	int  iOpt;
 	int  rc;
+#else
+	int  iOpt;
+	int  rc;
+
+	char *szShortOpts;
+	int  iNumShortOpts, iNumGenLongOpts;
+	struct option *sLongOpts;
+
+	iNumShortOpts = strlen( pszGenShortOpts ) +
+		( ( a_pszShortOpts == NULL ) ? 0 : strlen( a_pszShortOpts ) );
+	iNumGenLongOpts = sizeof( sGenLongOpts ) / sizeof( struct option );
+
+	szShortOpts = malloc(iNumShortOpts + 1);
+	sLongOpts = malloc((iNumGenLongOpts + a_iNumOpts + 1) 
+                           * sizeof(struct option));
+	if( (szShortOpts == NULL) || (sLongOpts == NULL) ) {
+		perror("malloc");
+		return -1;
+	}
+#endif
 
 	strcpy( szShortOpts, pszGenShortOpts);
 	if ( a_pszShortOpts )
 		strcat( szShortOpts, a_pszShortOpts );
 
+#ifdef __GCC
 	memset( sLongOpts, 0, sizeof( sLongOpts ) );
+#else
+	memset( sLongOpts, 0, (iNumGenLongOpts + a_iNumOpts + 1) * sizeof(struct option));
+#endif
 	memcpy( sLongOpts, sGenLongOpts, sizeof( sGenLongOpts ) );
 	if ( a_sLongOpts ) {
 		memcpy( sLongOpts + iNumGenLongOpts,
