diff -ruN src/subshell.c.orig src/subshell.c
--- src/subshell.c.orig	Wed Jun 14 15:45:12 2006
+++ src/subshell.c	Wed Jun 14 15:45:39 2006
@@ -395,6 +395,8 @@
	    subshell_type = ZSH;
	else if (strstr (shell, "/tcsh"))
	    subshell_type = TCSH;
+	else if (strstr (shell, "/csh"))
+	    subshell_type = TCSH;
	else if (strstr (shell, "/bash") || getenv ("BASH"))
	    subshell_type = BASH;
	else {
@@ -701,30 +687,25 @@
  * executing any commands in the shell.  Escape all control characters.
  * Use following technique:
  *
- * for bash - echo with `-e', 3-digit octal numbers:
- *   cd "`echo -e '\ooo...\ooo'`"
+ * printf(1) with format string containing a single conversion specifier,
+ * "b", and an argument which contains a copy of the string passed to 
+ * subshell_name_quote() with all characters, except digits and letters,
+ * replaced by the backslash-escape sequence \0nnn, where "nnn" is the
+ * numeric value of the character converted to octal number.
+ * 
+ *   cd "`printf "%b" 'ABC\0nnnDEF\0nnnXYZ'`"
  *
- * for zsh - echo with `-e', 4-digit octal numbers:
- *   cd "`echo '\oooo...\oooo'`"
- *
- * for tcsh - echo without `-e', 4-digit octal numbers:
- *   cd "`echo '\oooo...\oooo'`"
  */
 static char *
 subshell_name_quote (const char *s)
 {
     char *ret, *d;
-    const char echo_cmd[] = "\"`echo '";
-    const char echo_e_cmd[] = "\"`echo -e '";
-    const char common_end[] = "'`\"";
-    const char *cmd_start;
-    int len;
+    const char quote_cmd_start[] = "\"`printf \"%b\" '";
+    const char quote_cmd_end[] = "'`\"";
 
-    /*
-     * Factor 5 because we need \, 0 and 3 other digits per character
-     * in the worst case (tcsh and zsh).
-     */
-    d = ret = g_malloc (5 * strlen (s) + 16);
+    /* Factor 5 because we need \, 0 and 3 other digits per character. */
+    d = ret = g_malloc (1 + (5 * strlen (s)) + (sizeof(quote_cmd_start) - 1)
+				+ (sizeof(quote_cmd_end) - 1));
     if (!d)
 	return NULL;
 
@@ -734,43 +715,25 @@
 	*d++ = '/';
     }
 
-    /* echo in tcsh doesn't understand the "-e" option */
-    if (subshell_type == TCSH)
-	cmd_start = echo_cmd;
-    else
-	cmd_start = echo_e_cmd;
-
     /* Copy the beginning of the command to the buffer */
-    len = strlen (cmd_start);
-    memcpy (d, cmd_start, len);
-    d += len;
+    strcpy (d, quote_cmd_start);
+    d += sizeof(quote_cmd_start) - 1;
 
     /*
-     * Print every character in octal format with the leading backslash.
-     * tcsh and zsh may require 4-digit octals, bash < 2.05b doesn't like them.
+     * Print every character except digits and letters as a backslash-escape
+     * sequence of the form \0nnn, where "nnn" is the numeric value of the
+     * character converted to octal number.
      */
-    if (subshell_type == BASH) {
-	for (; *s; s++) {
-	    /* Must quote numbers, so that they are not glued to octals */
-	    if (isalpha ((unsigned char) *s)) {
-		*d++ = (unsigned char) *s;
-	    } else {
-		sprintf (d, "\\%03o", (unsigned char) *s);
-		d += 4;
-	    }
-	}
-    } else {
-	for (; *s; s++) {
-	    if (isalnum ((unsigned char) *s)) {
-		*d++ = (unsigned char) *s;
-	    } else {
-		sprintf (d, "\\0%03o", (unsigned char) *s);
-		d += 5;
-	    }
+    for (; *s; s++) {
+	if (isalnum ((unsigned char) *s)) {
+	    *d++ = (unsigned char) *s;
+	} else {
+	    sprintf (d, "\\0%03o", (unsigned char) *s);
+	    d += 5;
 	}
     }
 
-    memcpy (d, common_end, sizeof (common_end));
+    strcpy (d, quote_cmd_end);
 
     return ret;
 }
