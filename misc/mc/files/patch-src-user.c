--- src/user.c.orig	Fri Nov 29 09:03:53 2002
+++ src/user.c	Tue Jun 15 03:15:09 2004
@@ -138,19 +138,14 @@
 	}
 	
 	/* Copy the variable name */
-	var_name = g_malloc (dots - p);
-	strncpy (var_name, p+4, dots-2 - (p+3));
-	var_name [dots-2 - (p+3)] = 0;
-
+	var_name = g_strndup (p + 4, dots - p - 5);
 	value = getenv (var_name);
 	g_free (var_name);
 	if (value){
 	    *v = g_strdup (value);
 	    return q-p;
 	}
-	var_name = g_malloc (q - dots + 1);
-	strncpy (var_name, dots, q - dots + 1);
-	var_name [q-dots] = 0;
+	var_name = g_strndup (dots, q - dots);
 	*v = var_name;
 	return q-p;
     }
@@ -300,13 +295,15 @@
 
 /* Copies a whitespace separated argument from p to arg. Returns the
    point after argument. */
-static char *extract_arg (char *p, char *arg)
+static char *extract_arg (char *p, char *arg, size_t size)
 {
     while (*p && (*p == ' ' || *p == '\t' || *p == '\n'))
 	p++;
                 /* support quote space .mnu */
-    while (*p && (*p != ' ' || *(p-1) == '\\') && *p != '\t' && *p != '\n')
+    while (size > 1 && *p && (*p != ' ' || *(p-1) == '\\') && *p != '\t' && *p != '\n') {
 	*arg++ = *p++;
+	size--;
+    }
     *arg = 0;
     if (!*p || *p == '\n')
 	p --;
@@ -389,29 +386,29 @@
 	    p--;
 	    break;
 	case 'f': /* file name pattern */
-	    p = extract_arg (p, arg);
+	    p = extract_arg (p, arg, sizeof (arg));
 	    *condition = panel && regexp_match (arg, panel->dir.list [panel->selected].fname, match_file);
 	    break;
 	case 'y': /* syntax pattern */
             if (edit_widget && edit_widget->syntax_type) {
-	        p = extract_arg (p, arg);
+	        p = extract_arg (p, arg, sizeof (arg));
 	        *condition = panel &&
                     regexp_match (arg, edit_widget->syntax_type, match_normal);
 	    }
                 break;
 	case 'd':
-	    p = extract_arg (p, arg);
+	    p = extract_arg (p, arg, sizeof (arg));
 	    *condition = panel && regexp_match (arg, panel->cwd, match_file);
 	    break;
 	case 't':
-	    p = extract_arg (p, arg);
+	    p = extract_arg (p, arg, sizeof (arg));
 	    *condition = panel && test_type (panel, arg);
 	    break;
 	case 'x': /* executable */
 	{
 	    struct stat status;
 	    
-	    p = extract_arg (p, arg);
+	    p = extract_arg (p, arg, sizeof (arg));
 	    if (stat (arg, &status) == 0)
 		*condition = is_exe (status.st_mode);
 	    else
@@ -431,50 +428,43 @@
 static void
 debug_out (char *start, char *end, int cond)
 {
-    static char msg [256];
+    static char *msg;
     int len;
 
     if (start == NULL && end == NULL){
-	if (cond == 0){
-	    /* Init */
-	    msg [0] = 0;
-	} else {
-	    /* Show output */
-	    if (!debug_flag)
-		return;
+	/* Show output */
+	if (debug_flag && msg) {
 	    len = strlen (msg);
 	    if (len)
 		msg [len - 1] = 0;
 	    message (0, _(" Debug "), "%s", msg);
-	    debug_flag = 0;
 	}
+	debug_flag = 0;
+	g_free (msg);
+	msg = NULL;
     } else {
+	char *type, *p;
+
 	/* Save debug info for later output */
 	if (!debug_flag)
 	    return;
 	/* Save the result of the condition */
 	if (debug_error){
-	    strcat (msg, _(" ERROR: "));
+	    type = _(" ERROR: ");
 	    debug_error = 0;
 	}
 	else if (cond)
-	    strcat (msg, _(" True:  "));
+	    type = _(" True:  ");
 	else
-	    strcat (msg, _(" False: "));
-	/* Copy condition statement */
-	len = strlen (msg);
-	if (end == NULL){
-	    /* Copy one character */
-	    msg [len] = *start;
-	    msg [len + 1] = 0;
-	} else {
-	    /* Copy many characters */
-	    while (start < end){
-		msg [len++] = *start++;
-	    }
-	    msg [len] = 0;
-	}
-	strcat (msg, " \n");
+	    type = _(" False: ");
+	/* This is for debugging, don't need to be super efficient.  */
+	if (end == NULL)
+	    p = g_strdup_printf ("%s%s%c \n", msg ? msg : "", type, *start);
+	else
+	    p = g_strdup_printf ("%s%s%.*s \n", msg ? msg : "", type,
+				 (int) (end - start), start);
+        g_free (msg);
+        msg = p;
     }
 }
 
@@ -486,8 +476,6 @@
     char operator;
     char *debug_start, *debug_end;
 
-    /* Init debugger */
-    debug_out (NULL, NULL, 0);
     /* Repeat till end of line */
     while (*p && *p != '\n') {
         /* support quote space .mnu */
@@ -578,6 +566,8 @@
 		break;
 	    while (*commands == ' ' || *commands == '\t')
 	        commands++;
+	  if (*commands == '0')
+		break;
 	}
 	col++;
 	if (*commands == '\n')
@@ -734,7 +724,7 @@
 	    } else if (*p == '+'){
 		if (*(p+1) == '='){
 		    /* Combined adding and default */
-		    p = test_line (edit_widget, p, &accept_entry);
+		    p = test_line (edit_widget, p + 1, &accept_entry);
 		    if (selected == 0 && accept_entry)
 			selected = menu_lines;
 		} else {
@@ -744,7 +734,7 @@
 	    } else if (*p == '='){
 		if (*(p+1) == '+'){
 		    /* Combined adding and default */
-		    p = test_line (edit_widget, p, &accept_entry);
+		    p = test_line (edit_widget, p + 1, &accept_entry);
 		    if (selected == 0 && accept_entry)
 			selected = menu_lines;
 		} else {
