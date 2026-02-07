--- cf/feature/sts.m4.orig	2023-02-09 18:24:38 UTC
+++ cf/feature/sts.m4
@@ -15,5 +15,5 @@ ifelse(_ARG2_,`NO_SAN_TST',`',`define(`_STS_SAN', `1')
 LOCAL_CONFIG
 O StrictTransportSecurity=true
 ifelse(_ARG2_,`NO_SAN_TST',`',`O SetCertAltnames=true')
-Ksts ifelse(defn(`_ARG_'), `', socket -d5 -T<TMPF> inet:5461@127.0.0.1,
+Ksts ifelse(defn(`_ARG_'), `', socket -d5 -T<TMPF> inet:8461@127.0.0.1,
 	       defn(`_NARG_'), `', `_ARG_', `_NARG_')
