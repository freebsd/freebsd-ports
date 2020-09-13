--- src/ntpd.h.orig	2017-10-30 08:57:40 UTC
+++ src/ntpd.h
@@ -1,4 +1,4 @@
-/*	$OpenBSD: ntpd.h,v 1.135 2017/05/30 23:30:48 benno Exp $ */
+/*	$OpenBSD: ntpd.h,v 1.150 2020/08/30 16:21:29 otto Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -341,6 +341,8 @@ time_t	 scale_interval(time_t);
 time_t	 error_interval(void);
 extern struct ntpd_conf *conf;
 extern struct ctl_conns  ctl_conns;
+
+#define  SCALE_INTERVAL(x)	 MAXIMUM(5, (x) / 10)
 
 /* parse.y */
 int	 parse_config(const char *, struct ntpd_conf *);
