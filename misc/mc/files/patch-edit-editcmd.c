--- edit/editcmd.c.orig	Thu Dec 19 19:01:34 2002
+++ edit/editcmd.c	Tue Jun 15 03:16:08 2004
@@ -1546,51 +1546,56 @@
 
 #define is_digit(x) ((x) >= '0' && (x) <= '9')
 
-#define snprintf(v) { \
+#define snprint(v) { \
 		*p1++ = *p++; \
-		*p1++ = '%'; \
-		*p1++ = 'n'; \
 		*p1 = '\0'; \
-		sprintf(s,q1,v,&n); \
+		n = snprintf(s,e-s,q1,v); \
+		if (n >= e - s) goto nospc; \
 		s += n; \
 	    }
 
 /* this function uses the sprintf command to do a vprintf */
 /* it takes pointers to arguments instead of the arguments themselves */
-static int sprintf_p (char *str, const char *fmt,...)
-    __attribute__ ((format (printf, 2, 3)));
+/* The return value is the number of bytes written excluding '\0'
+   if successfull, -1 if the resulting string would be too long and
+   -2 if the format string is errorneous.  */
+static int snprintf_p (char *str, size_t size, const char *fmt,...)
+    __attribute__ ((format (printf, 3, 4)));
 
-static int sprintf_p (char *str, const char *fmt,...)
+static int snprintf_p (char *str, size_t size, const char *fmt,...)
 {
     va_list ap;
-    int n;
-    char *q, *p, *s = str;
-    char q1[32];
+    size_t n;
+    char *q, *p, *s = str, *e = str + size;
+    char q1[40];
     char *p1;
+    int nargs = 0;
 
     va_start (ap, fmt);
     p = q = (char *) fmt;
 
     while ((p = strchr (p, '%'))) {
 	n = p - q;
-	strncpy (s, q, n);	/* copy stuff between format specifiers */
+	if (n >= e - s)
+	  goto nospc;
+	memcpy (s, q, n);	/* copy stuff between format specifiers */
 	s += n;
-	*s = 0;
 	q = p;
 	p1 = q1;
 	*p1++ = *p++;
 	if (*p == '%') {
 	    p++;
 	    *s++ = '%';
+	    if (s == e)
+		goto nospc;
 	    q = p;
 	    continue;
 	}
-	if (*p == 'n') {
-	    p++;
-/* do nothing */
-	    q = p;
-	    continue;
-	}
+	if (*p == 'n')
+	    goto err;
+	/* We were passed only 16 arguments.  */
+	if (++nargs == 16)
+	    goto err;
 	if (*p == '#')
 	    *p1++ = *p++;
 	if (*p == '0')
@@ -1604,8 +1609,10 @@
 	    strcpy (p1, MY_itoa (*va_arg (ap, int *)));	/* replace field width with a number */
 	    p1 += strlen (p1);
 	} else {
-	    while (is_digit (*p))
+	    while (is_digit (*p) && p1 < q1 + 20)
 		*p1++ = *p++;
+	    if (is_digit (*p))
+		goto err;
 	}
 	if (*p == '.')
 	    *p1++ = *p++;
@@ -1614,37 +1621,49 @@
 	    strcpy (p1, MY_itoa (*va_arg (ap, int *)));	/* replace precision with a number */
 	    p1 += strlen (p1);
 	} else {
-	    while (is_digit (*p))
+	    while (is_digit (*p) && p1 < q1 + 32)
 		*p1++ = *p++;
+	    if (is_digit (*p))
+		goto err;
 	}
 /* flags done, now get argument */
 	if (*p == 's') {
-	    snprintf (va_arg (ap, char *));
+	    snprint (va_arg (ap, char *));
 	} else if (*p == 'h') {
 	    if (strchr ("diouxX", *p))
-		snprintf (*va_arg (ap, short *));
+		snprint (*va_arg (ap, short *));
 	} else if (*p == 'l') {
 	    *p1++ = *p++;
 	    if (strchr ("diouxX", *p))
-		snprintf (*va_arg (ap, long *));
+		snprint (*va_arg (ap, long *));
 	} else if (strchr ("cdiouxX", *p)) {
-	    snprintf (*va_arg (ap, int *));
+	    snprint (*va_arg (ap, int *));
 	} else if (*p == 'L') {
 	    *p1++ = *p++;
 	    if (strchr ("EefgG", *p))
-		snprintf (*va_arg (ap, double *));	/* should be long double */
+		snprint (*va_arg (ap, double *));	/* should be long double */
 	} else if (strchr ("EefgG", *p)) {
-	    snprintf (*va_arg (ap, double *));
+	    snprint (*va_arg (ap, double *));
 	} else if (strchr ("DOU", *p)) {
-	    snprintf (*va_arg (ap, long *));
+	    snprint (*va_arg (ap, long *));
 	} else if (*p == 'p') {
-	    snprintf (*va_arg (ap, void **));
-	}
+	    snprint (*va_arg (ap, void **));
+	} else
+	    goto err;
 	q = p;
     }
     va_end (ap);
-    sprintf (s, q);		/* print trailing leftover */
-    return s - str + strlen (s);
+    n = strlen (q);
+    if (n >= e - s)
+	return -1;
+    memcpy (s, q, n + 1);
+    return s + n - str;
+nospc:
+    va_end (ap);
+    return -1;
+err:
+    va_end (ap);
+    return -2;
 }
 
 static void regexp_error (WEdit *edit)
@@ -1737,7 +1756,7 @@
 	for (i = 0; i < NUM_REPL_ARGS; i++) {
 	    if (s != (char *) 1 && *s) {
 		ord = atoi (s);
-		if ((ord > 0) && (ord < NUM_REPL_ARGS))
+		if ((ord > 0) && (ord <= NUM_REPL_ARGS))
 		    argord[i] = ord - 1;
 		else
 		    argord[i] = i;
@@ -1821,6 +1840,7 @@
 	    if (replace_yes) {	/* delete then insert new */
 		if (replace_scanf || replace_regexp) {
 		    char repl_str[MAX_REPL_LEN + 2];
+		    int ret = 0;
 
 		    /* we need to fill in sargs just like with scanf */
 		    if (replace_regexp) {
@@ -1829,6 +1849,11 @@
 			     k < NUM_REPL_ARGS && pmatch[k].rm_eo >= 0;
 			     k++) {
 			    unsigned char *t;
+
+			    if (pmatch[k].rm_eo - pmatch[k].rm_so > 255) {
+				ret = -1;
+				break;
+			    }
 			    t = (unsigned char *) &sargs[k - 1][0];
 			    for (j = 0;
 				 j < pmatch[k].rm_eo - pmatch[k].rm_so
@@ -1849,7 +1874,9 @@
 			for (; k <= NUM_REPL_ARGS; k++)
 			    sargs[k - 1][0] = 0;
 		    }
-		    if (sprintf_p (repl_str, exp2, PRINTF_ARGS) >= 0) {
+		    if (!ret)
+			ret = snprintf_p (repl_str, MAX_REPL_LEN + 2, exp2, PRINTF_ARGS);
+		    if (ret >= 0) {
 			times_replaced++;
 			while (i--)
 			    edit_delete (edit);
@@ -1857,8 +1884,9 @@
 			    edit_insert (edit, repl_str[i]);
 		    } else {
 			edit_error_dialog (_(" Replace "),
-					   _
-					   (" Error in replacement format string. "));
+					   ret == -2
+					   ? _(" Error in replacement format string. ")
+					   : _(" Replacement too long. "));
 			replace_continue = 0;
 		    }
 		} else {
@@ -2711,7 +2739,7 @@
     int word_len = 0, i, num_compl = 0, max_len;
     long word_start = 0;
     char *bufpos;
-    char match_expr[MAX_REPL_LEN];
+    char *match_expr;
     struct selection compl[MAX_WORD_COMPLETIONS];	/* completions */
 
     /* don't want to disturb another search */
@@ -2728,9 +2756,7 @@
     /* prepare match expression */
     bufpos = &edit->buffers1[word_start >> S_EDIT_BUF_SIZE]
 	[word_start & M_EDIT_BUF_SIZE];
-    strncpy (match_expr, bufpos, word_len);
-    match_expr[word_len] = '\0';
-    strcat (match_expr, "[a-zA-Z_0-9]+");
+    match_expr = g_strdup_printf ("%.*s[a-zA-Z_0-9]+", word_len, bufpos);
 
     /* init search: backward, regexp, whole word, case sensitive */
     edit_set_search_parameters (0, 1, 1, 1, 1);
@@ -2762,6 +2788,8 @@
     }
 
     /* release memory before return */
+    g_free (match_expr);
+
     for (i = 0; i < num_compl; i++)
 	g_free (compl[i].text);
 
