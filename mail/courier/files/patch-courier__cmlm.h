--- courier/cmlm.h.orig	2007-04-29 11:59:40.000000000 -0400
+++ courier/cmlm.h	2007-04-29 11:59:40.000000000 -0400
@@ -56,7 +56,7 @@
 
 #include	"bindir.h"
 
-#define	SENDMAIL	BINDIR "/sendmail"
+#define	SENDMAIL	"/usr/sbin/sendmail"
 #define	REFORMIME	BINDIR "/reformime"
 #define	MAXRCPTS	20
 
