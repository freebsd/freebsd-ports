--- api/wrappers/generic_wrapper.sh.orig	2026-01-07 12:49:39.640154000 -0400
+++ api/wrappers/generic_wrapper.sh	2026-01-07 12:52:17.155158000 -0400
@@ -3,6 +3,8 @@
 # Created by Wazuh, Inc. <info@wazuh.com>.
 # This program is a free software; you can redistribute it and/or modify it under the terms of GPLv2
 
+CRYPTOGRAPHY_OPENSSL_NO_LEGACY=1; export CRYPTOGRAPHY_OPENSSL_NO_LEGACY
+
 WPYTHON_BIN="framework/python/bin/python3"
 
 SCRIPT_PATH_NAME="$0"
@@ -35,4 +37,4 @@
 esac
 
 
-${WAZUH_PATH}/${WPYTHON_BIN} ${PYTHON_SCRIPT} $@
\ No newline at end of file
+${WAZUH_PATH}/${WPYTHON_BIN} ${PYTHON_SCRIPT} $@
