--- ./t_cltsrv-down.sh.orig	2008-08-07 23:24:40.000000000 +0200
+++ ./t_cltsrv-down.sh	2008-08-07 23:28:40.000000000 +0200
@@ -0,0 +1,2 @@
+#! /bin/sh
+echo "${role}:${signal}" >&3
