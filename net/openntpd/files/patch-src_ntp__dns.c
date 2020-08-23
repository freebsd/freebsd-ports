--- src/ntp_dns.c.orig	2017-06-19 13:23:10 UTC
+++ src/ntp_dns.c
@@ -33,7 +33,7 @@
 #include "ntpd.h"
 
 volatile sig_atomic_t	 quit_dns = 0;
-struct imsgbuf		*ibuf_dns;
+static struct imsgbuf	*ibuf_dns;
 
 void	sighdlr_dns(int);
 int	dns_dispatch_imsg(void);
