--- names.c.intermediate	2015-03-09 09:59:41 UTC
+++ names.c
@@ -502,7 +502,7 @@ unpack(np)
 		extra++;
 	top = (char **) salloc((t + extra) * sizeof *top);
 	ap = top;
-	*ap++ = "send-mail";
+	*ap++ = "sendmail";
 #if MAILX
 	*ap++ = "-t";
 #else
