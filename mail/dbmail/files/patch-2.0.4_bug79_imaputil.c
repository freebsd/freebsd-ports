Index: imaputil.c
===================================================================
--- imaputil.c	(revision 1726)
+++ imaputil.c	(revision 1793)
@@ -65,7 +65,7 @@
     "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
 
 /* returned by date_sql2imap() */
-#define IMAP_STANDARD_DATE "03-Nov-1979 00:00:00 +0000"
+#define IMAP_STANDARD_DATE "Sat, 03-Nov-1979 00:00:00 +0000"
 char _imapdate[IMAP_INTERNALDATE_LEN] = IMAP_STANDARD_DATE;
 
 /* returned by date_imap2sql() */
@@ -1776,50 +1776,35 @@
 
 /*
  * convert a mySQL date (yyyy-mm-dd hh:mm:ss) to a valid IMAP internal date:
- *                       0123456789012345678
- * dd-mon-yyyy hh:mm:ss with mon characters (i.e. 'Apr' for april)
- * 01234567890123456789
+ * [Mon, 30 May 2005 10:01:55 +0100] with mon characters (i.e. 'Apr' for april)
  * return value is valid until next function call.
  * NOTE: if date is not valid, IMAP_STANDARD_DATE is returned
  */
 char *date_sql2imap(const char *sqldate)
 {
-	char *last_char;
-	struct tm tm_localtime, tm_sqldate;
-	time_t td;
+        struct tm tm_sql_date;
+	struct tm *tm_imap_date;
+	
+	time_t ltime;
+        char *last;
 
-	/* we need to get the localtime to get the current timezone */
-	if (time(&td) == -1) {
-		trace(TRACE_ERROR, "%s,%s: error getting time()",
-		      __FILE__, __func__);
-		return IMAP_STANDARD_DATE;
-	}
-	tm_localtime = *localtime(&td);
+        last = strptime(sqldate,"%Y-%m-%d %T", &tm_sql_date);
+        if ( (last == NULL) || (*last != '\0') ) {
+                strcpy(_imapdate, IMAP_STANDARD_DATE);
+                return _imapdate;
+        }
 
-	/* parse sqldate */
-	last_char = strptime(sqldate, "%Y-%m-%d %T", &tm_sqldate);
-	if (last_char == NULL || *last_char != '\0') {
-		trace(TRACE_DEBUG, "%s,%s, error parsing date [%s]",
-		      __FILE__, __func__, sqldate);
-		strcpy(_imapdate, IMAP_STANDARD_DATE);
-		return _imapdate;
-	}
-	/* copy DST information from localtime */
-	tm_sqldate.tm_gmtoff = tm_localtime.tm_gmtoff;
-	tm_sqldate.tm_isdst = tm_localtime.tm_isdst;
+	/* FIXME: this works fine on linux, but may cause dst offsets in netbsd. */
+	ltime = mktime (&tm_sql_date);
+	tm_imap_date = localtime(&ltime);
 
-	(void) strftime(_imapdate, IMAP_INTERNALDATE_LEN, 
-			"%d-%b-%Y %T %z", &tm_sqldate);
-
-	return _imapdate;
+        strftime(_imapdate, sizeof(_imapdate), "%a, %d %b %Y %H:%M:%S %z", tm_imap_date);
+        return _imapdate;
 }
 
-
 /*
  * convert TO a mySQL date (yyyy-mm-dd) FROM a valid IMAP internal date:
- *                          0123456789
  * dd-mon-yyyy with mon characters (i.e. 'Apr' for april)
- * 01234567890
  * OR
  * d-mon-yyyy
  * return value is valid until next function call.
