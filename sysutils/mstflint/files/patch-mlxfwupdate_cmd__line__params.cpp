--- mlxfwupdate/cmd_line_params.cpp.orig	2022-12-16 14:59:44 UTC
+++ mlxfwupdate/cmd_line_params.cpp
@@ -92,9 +92,9 @@ CmdLineParams::CmdLineParams()
 
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
