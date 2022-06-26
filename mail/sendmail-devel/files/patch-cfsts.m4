--- cf/feature/sts.m4.orig	2021-06-08 04:03:56.000000000 +0900
+++ cf/feature/sts.m4	2022-02-24 21:30:48.072162000 +0900
@@ -15,5 +15,5 @@
 LOCAL_CONFIG
 O StrictTransportSecurity=true
 ifelse(_ARG2_,`NO_SAN_TST',`',`O SetCertAltnames=true')
-Ksts ifelse(defn(`_ARG_'), `', socket -d5 -T<TMPF> inet:5461@127.0.0.1,
+Ksts ifelse(defn(`_ARG_'), `', socket -d5 -T<TMPF> inet:8461@127.0.0.1,
 	       defn(`_NARG_'), `', `_ARG_', `_NARG_')
