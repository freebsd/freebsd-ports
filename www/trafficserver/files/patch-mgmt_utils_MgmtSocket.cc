--- mgmt/utils/MgmtSocket.cc.orig	2016-07-11 23:03:32 UTC
+++ mgmt/utils/MgmtSocket.cc
@@ -89,7 +89,7 @@ mgmt_fopen(const char *filename, const c
     // no leak here as f will be returned if it is > 0
     // coverity[overwrite_var]
     f = ::fopen(filename, mode);
-    if (f > 0)
+    if (f)
       return f;
     if (!mgmt_transient_error())
       break;
