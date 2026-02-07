--- src/mod_iptables.c.orig	2003-04-17 11:18:16 UTC
+++ src/mod_iptables.c
@@ -21,6 +21,8 @@
 /* Yee ole includes (I put this all in one file for my sanity) */
 #include "includes.h"
 
+IPTABLES it;
+
 /*
  * a module to process iptables messages into something sane to read with the naked eye
  */
