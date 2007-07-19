--- /dev/null	1 Jan 1970 00:00:00 -0000
+++ bgpctl/util.h	8 Feb 2007 10:32:19 -0000
@@ -0,0 +1,8 @@
+/*
+ * Written by Claudio Jeker, Public Domain
+ */
+
+#define FMT_SCALED_STRSIZE	7
+
+int		fmt_scaled(long long number, char *result);
+
