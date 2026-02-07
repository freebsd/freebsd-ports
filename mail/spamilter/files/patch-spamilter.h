--- spamilter.h.orig	2004-12-12 22:14:16 UTC
+++ spamilter.h
@@ -95,7 +95,7 @@
 
 	#define MLFIPRIV ((mlfiPriv *) smfi_getpriv(ctx))
 
-	struct smfiDesc mlfi;		/* forward declaration */
+	extern struct smfiDesc mlfi;		/* forward declaration */
 
 	extern int gDebug;
 	extern char *gPolicyUrl;		/* policy url */
