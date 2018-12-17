--- gribex/csect4.F.orig	2018-12-17 15:56:26 UTC
+++ gribex/csect4.F
@@ -308,7 +308,7 @@ C     Calculate the scale and reference 
 #endif
 #if defined hpR32 || defined (__alpha) || defined hpR64 || defined hpiaR64
       ISCALE = MIN (INT(ZS),INT(ZS+DSIGN(1.0D0,ZS)))
-#elif defined (linux) || defined (darwin)
+#elif 1/*defined(__FreeBSD__) doesn't work for some reason: https://jira.ecmwf.int/browse/SUP-2687*/ || defined (linux) || defined(__FreeBSD__) || defined (darwin)
       ISCALE = MIN (INT(ZS),INT(ZS+SIGN(1.D0,ZS)))
 #else
       ISCALE = MIN (INT(ZS),INT(ZS+SIGN(1.,ZS)))
