#
# Re-enable "!"s in .cvsignore files
# https://bugzilla.samba.org/show_bug.cgi?id=1873
#
--- exclude.c.orig	Wed Sep 22 06:11:15 2004
+++ exclude.c	Wed Oct  6 19:04:55 2004
@@ -235,8 +235,9 @@
 /* Get the next include/exclude arg from the string.  The token will not
  * be '\0' terminated, so use the returned length to limit the string.
  * Also, be sure to add this length to the returned pointer before passing
- * it back to ask for the next token.  This routine parses the +/- prefixes
- * and the "!" token unless xflags contains XFLG_WORDS_ONLY.  The *flag_ptr
+ * it back to ask for the next token.  This routine parses the "!" (list-
+ * clearing) token and (if xflags does NOT contain XFLG_WORDS_ONLY) the
+ * +/- prefixes for overriding the include/exclude mode.  The *flag_ptr
  * value will also be set to the MATCHFLG_* bits for the current token.
  */
 static const char *get_exclude_tok(const char *p, unsigned int *len_ptr,
@@ -273,7 +274,7 @@
 	} else
 		len = strlen(s);
 
-	if (*p == '!' && len == 1 && !(xflags & XFLG_WORDS_ONLY))
+	if (*p == '!' && len == 1)
 		mflags |= MATCHFLG_CLEAR_LIST;
 
 	*len_ptr = len;
