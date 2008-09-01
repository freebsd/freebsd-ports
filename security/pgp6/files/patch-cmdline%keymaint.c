--- clients/pgp/cmdline/keymaint.c.orig	1999-05-12 14:01:04.000000000 -0700
+++ clients/pgp/cmdline/keymaint.c	2008-08-31 01:36:27.000000000 -0700
@@ -264,7 +264,7 @@ PGPError markSignatureChainDepths(struct
             pgpAssertNoErr(err);
 
             if ( (PGPUInt32)traceValue == 0) {
-                (PGPUInt32)traceValue = depth;
+                traceValue = depth;
 
                 err = PGPSetKeyUserVal( key, traceValue);
                 pgpAssertNoErr(err);
