--- sendmail/headers.c	23 Sep 2002 23:42:02 -0000	8.266.4.2
+++ sendmail/headers.c	13 Jan 2003 06:29:05 -0000
@@ -15,7 +15,7 @@
 
 SM_RCSID("@(#)$Id: headers.c,v 8.266.4.2 2002/09/23 23:42:02 ca Exp $")
 
-static size_t	fix_mime_header __P((char *));
+static size_t	fix_mime_header __P((HDR *, ENVELOPE *));
 static int	priencode __P((char *));
 static void	put_vanilla_header __P((HDR *, char *, MCI *));
 
@@ -1412,7 +1412,7 @@
 		{
 			size_t len;
 
-			len = fix_mime_header(h->h_value);
+			len = fix_mime_header(h, e);
 			if (len > 0)
 			{
 				sm_syslog(LOG_ALERT, e->e_id,
@@ -1455,13 +1455,28 @@
 			if (shorten_rfc822_string(h->h_value,
 						  MaxMimeHeaderLength))
 			{
-				sm_syslog(LOG_ALERT, e->e_id,
-					  "Truncated long MIME %s header (length = %ld) (possible attack)",
-					  h->h_field, (unsigned long) len);
-				if (tTd(34, 11))
-					sm_dprintf("  truncated long MIME %s header (length = %ld) (possible attack)\n",
-						   h->h_field,
-						   (unsigned long) len);
+				if (len < MaxMimeHeaderLength)
+				{
+					/* we only rebalanced a bogus header */
+					sm_syslog(LOG_ALERT, e->e_id,
+						  "Fixed MIME %s header (possible attack)",
+						  h->h_field);
+					if (tTd(34, 11))
+						sm_dprintf("  fixed MIME %s header (possible attack)\n",
+							   h->h_field);
+				}
+				else
+				{
+					/* we actually shortened header */
+					sm_syslog(LOG_ALERT, e->e_id,
+						  "Truncated long MIME %s header (length = %ld) (possible attack)",
+						  h->h_field,
+						  (unsigned long) len);
+					if (tTd(34, 11))
+						sm_dprintf("  truncated long MIME %s header (length = %ld) (possible attack)\n",
+							   h->h_field,
+							   (unsigned long) len);
+				}
 			}
 		}
 
@@ -1856,7 +1871,8 @@
 **	to MaxMimeFieldLength.
 **
 **	Parameters:
-**		string -- the full header
+**		h -- the header to truncate/rebalance
+**		e -- the current envelope
 **
 **	Returns:
 **		length of last offending field, 0 if all ok.
@@ -1866,15 +1882,16 @@
 */
 
 static size_t
-fix_mime_header(string)
-	char *string;
+fix_mime_header(h, e)
+	HDR *h;
+	ENVELOPE *e;
 {
-	char *begin = string;
+	char *begin = h->h_value;
 	char *end;
 	size_t len = 0;
 	size_t retlen = 0;
 
-	if (string == NULL || *string == '\0')
+	if (begin == NULL || *begin == '\0')
 		return 0;
 
 	/* Split on each ';' */
@@ -1889,7 +1906,23 @@
 
 		/* Shorten individual parameter */
 		if (shorten_rfc822_string(begin, MaxMimeFieldLength))
-			retlen = len;
+		{
+			if (len < MaxMimeFieldLength)
+			{
+				/* we only rebalanced a bogus field */
+				sm_syslog(LOG_ALERT, e->e_id,
+					  "Fixed MIME %s header field (possible attack)",
+					  h->h_field);
+				if (tTd(34, 11))
+					sm_dprintf("  fixed MIME %s header field (possible attack)\n",
+						   h->h_field);
+			}
+			else
+			{
+				/* we actually shortened the header */
+				retlen = len;
+			}
+		}
 
 		/* Collapse the possibly shortened string with rest */
 		bp = begin + strlen(begin);
