--- xpcom/io/nsAppFileLocationProvider.cpp.orig	2011-09-30 15:52:07.000000000 +0200
+++ xpcom/io/nsAppFileLocationProvider.cpp	2011-09-30 15:52:40.000000000 +0200
@@ -238,7 +238,7 @@
 #if defined(HAVE_USR_LIB64_DIR) && defined(__LP64__)
           "/usr/lib64/mozilla/plugins";
 #else
-          "/usr/lib/mozilla/plugins";
+          "%%LOCALBASE%%/lib/npapi/symlinks/firefox";
 #endif
         rv = NS_NewNativeLocalFile(nsDependentCString(sysLPlgDir),
                                    PR_FALSE, getter_AddRefs(localFile));
