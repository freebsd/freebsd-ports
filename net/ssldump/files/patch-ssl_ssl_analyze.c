--- ssl/ssl_analyze.c.orig	2002-01-22 00:46:13.000000000 +0600
+++ ssl/ssl_analyze.c	2008-01-29 21:14:13.000000000 +0600
@@ -133,7 +133,7 @@
           SSL_PRINT_DECODE
      },
      {
-          0,
+          'y',
           "nroff",
           SSL_PRINT_NROFF
      },
