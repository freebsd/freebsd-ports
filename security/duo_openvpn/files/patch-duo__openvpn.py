--- duo_openvpn.py.orig	2021-05-06 18:37:22 UTC
+++ duo_openvpn.py
@@ -1,8 +1,4 @@
-#!/bin/sh
-''''which python3  >/dev/null 2>&1 && exec python3  "$0" "$@" # '''
-''''which python  >/dev/null 2>&1 && exec python  "$0" "$@" # '''
-''''which python2 >/dev/null 2>&1 && exec python2 "$0" "$@" # '''
-''''exec echo "Error: No python module found in system"# '''
+#!%%SHEBANG%%
 #
 # duo_openvpn.py
 # Duo OpenVPN
