--- mlxfwupdate/cmd_line_params.cpp.orig	2019-11-16 07:49:07 UTC
+++ mlxfwupdate/cmd_line_params.cpp
@@ -97,9 +97,9 @@ CmdLineParams::CmdLineParams()
 
 #else
     #ifdef MSTFLINT
-    certificate = (string)ROOT_PATH + "etc/mstflint/ca-bundle.crt";
+    certificate = (string)ROOT_PATH + "/etc/ssl/cert.pem";
     #else
-    certificate = (string)ROOT_PATH + "etc/mft/ca-bundle.crt";
+    certificate = (string)ROOT_PATH + "/etc/ssl/cert.pem";
     #endif
 #endif
 }
