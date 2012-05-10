--- libv4lconvert/control/libv4lcontrol.c.orig	2012-05-02 21:17:37.000000000 +0200
+++ libv4lconvert/control/libv4lcontrol.c	2012-05-06 08:52:42.000000000 +0200
@@ -456,7 +456,12 @@
 	while (isspace(*start)) start++;
 	n = strlen(start);
 	while (n > 0 && isspace(start[n-1])) --n;
+#ifndef __FreeBSD__
 	trimmed_dmi = strndupa(start, n);
+#else
+	trimmed_dmi = (char *)alloca(n + 1);
+	strlcpy(trimmed_dmi, start, n + 1);
+#endif
 
 	/* find trimmed value */
 	for (entry_ptr = table_entries; *entry_ptr;  entry_ptr++) {
