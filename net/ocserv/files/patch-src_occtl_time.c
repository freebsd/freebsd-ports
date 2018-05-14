--- src/occtl/time.c.orig	2017-09-09 08:34:02 UTC
+++ src/occtl/time.c
@@ -36,7 +36,7 @@ void print_time_ival7(char output[MAX_TMPSTR_SIZE], ti
 {
 	time_t t = t1 - t2;
 
-	if ((long)t < (long)0) {
+	if ((long long)t < (long long)0) {
 		/* system clock changed? */
 		snprintf(output, MAX_TMPSTR_SIZE, "   ?   ");
 		return;
@@ -44,17 +44,17 @@ void print_time_ival7(char output[MAX_TMPSTR_SIZE], ti
 	
 	if (t >= 48 * 60 * 60)
 		/* 2 days or more */
-		snprintf(output, MAX_TMPSTR_SIZE, _("%2ludays"), (long)t / (24 * 60 * 60));
+		snprintf(output, MAX_TMPSTR_SIZE, _("%2lludays"), (long long)t / (24 * 60 * 60));
 	else if (t >= 60 * 60)
 		/* 1 hour or more */
 	        /* Translation Hint: Hours:Minutes */
-		snprintf(output, MAX_TMPSTR_SIZE, _("%2luh:%02um"), (long)t / (60 * 60),
+		snprintf(output, MAX_TMPSTR_SIZE, _("%2lluh:%02um"), (long long)t / (60 * 60),
 			(unsigned)((t / 60) % 60));
 	else if (t > 60)
 		/* 1 minute or more */
 	        /* Translation Hint: Minutes:Seconds */
-		snprintf(output, MAX_TMPSTR_SIZE, "%2lum:%02us", (long)t / 60, (unsigned)t % 60);
+		snprintf(output, MAX_TMPSTR_SIZE, "%2llum:%02us", (long long)t / 60, (unsigned)t % 60);
 	else
 	        /* Translation Hint: Seconds:Centiseconds */
-		snprintf(output, MAX_TMPSTR_SIZE, _("%5lus"), (long)t);
+		snprintf(output, MAX_TMPSTR_SIZE, _("%5llus"), (long long)t);
 }
