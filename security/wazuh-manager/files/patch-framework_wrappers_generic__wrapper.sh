--- framework/wrappers/generic_wrapper.sh.orig	2026-01-07 12:49:52.861330000 -0400
+++ framework/wrappers/generic_wrapper.sh	2026-01-07 12:52:35.979138000 -0400
@@ -3,6 +3,8 @@
 # Created by Wazuh, Inc. <info@wazuh.com>.
 # This program is free software; you can redistribute it and/or modify it under the terms of GPLv2
 
+CRYPTOGRAPHY_OPENSSL_NO_LEGACY=1; export CRYPTOGRAPHY_OPENSSL_NO_LEGACY
+
 WPYTHON_BIN="framework/python/bin/python3"
 
 SCRIPT_PATH_NAME="$0"
