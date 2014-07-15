--- ./command.h.orig	2010-12-13 04:42:49.000000000 +0100
+++ ./command.h	2014-06-29 12:15:04.244544161 +0200
@@ -13,3 +13,5 @@
     char	*c_name;
     int		(*c_func)( SNET *, int, char *[] );
 };
+
+#define RADMIND_STAT_FMT "%s %s %o %d %d %" PRItimet "d %" PRIofft "d %s\r\n"
