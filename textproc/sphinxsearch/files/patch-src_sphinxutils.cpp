--- src/sphinxutils.cpp.orig	2018-02-03 10:25:41 UTC
+++ src/sphinxutils.cpp
@@ -2103,11 +2103,11 @@ void sphBacktrace ( int iFD, bool bSafe )
 #endif
 
 #ifdef CONFIGURE_FLAGS
-	sphSafeInfo ( iFD, "Configured with flags: "CONFIGURE_FLAGS );
+	sphSafeInfo ( iFD, "Configured with flags: " CONFIGURE_FLAGS );
 #endif
 
 #ifdef OS_UNAME
-	sphSafeInfo ( iFD, "Host OS is "OS_UNAME );
+	sphSafeInfo ( iFD, "Host OS is " OS_UNAME );
 #endif
 
 	bool bOk = true;
