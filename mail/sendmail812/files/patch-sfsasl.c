--- sendmail/sfsasl.c	27 Aug 2002 01:35:17 -0000	8.91.2.1
+++ sendmail/sfsasl.c	12 Sep 2002 21:07:50 -0000	8.91.2.2
@@ -182,7 +182,7 @@
 	int result;
 	ssize_t len;
 # if SASL >= 20000
-	const char *outbuf = NULL;
+	static const char *outbuf = NULL;
 # else /* SASL >= 20000 */
 	static char *outbuf = NULL;
 # endif /* SASL >= 20000 */
@@ -199,7 +199,11 @@
 	**  if necessary.
 	*/
 
+# if SASL >= 20000
+	while (outlen == 0)
+# else /* SASL >= 20000 */
 	while (outbuf == NULL && outlen == 0)
+# endif /* SASL >= 20000 */
 	{
 		len = sm_io_read(so->fp, SM_TIME_DEFAULT, buf, size);
 		if (len <= 0)
