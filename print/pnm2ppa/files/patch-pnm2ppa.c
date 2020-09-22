--- pnm2ppa.c.orig	2009-12-12 19:14:55 UTC
+++ pnm2ppa.c
@@ -40,6 +40,7 @@
 #include "gamma.h"
 #include "lang.h"
 
+char syslog_message[128];
 
 double  Gamma_R, Gamma_G, Gamma_B;
 int adjust_coloffsx, adjust_coloffsy;
