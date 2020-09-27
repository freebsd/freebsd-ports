--- source3/lib/util.c.orig	2019-05-07 08:38:21 UTC
+++ source3/lib/util.c
@@ -1916,7 +1916,10 @@ bool any_nt_status_not_ok(NTSTATUS err1,
 
 int timeval_to_msec(struct timeval t)
 {
-	return t.tv_sec * 1000 + (t.tv_usec+999) / 1000;
+	unsigned long result;
+
+	result = t.tv_sec * 1000 + (t.tv_usec+999) / 1000;
+	return result > INT_MAX ? INT_MAX : result;
 }
 
 /*******************************************************************
