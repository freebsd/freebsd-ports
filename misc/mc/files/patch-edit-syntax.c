--- edit/syntax.c.orig	Mon Dec 16 00:55:53 2002
+++ edit/syntax.c	Tue Jun 15 03:15:09 2004
@@ -99,7 +99,8 @@
     for (p = (unsigned char *) text, q = p + strlen ((char *) p); p < q; p++, i++) {
 	switch (*p) {
 	case '\001':
-	    p++;
+	    if (++p > q)
+		return -1;
 	    for (;;) {
 		c = edit_get_byte (edit, i);
 		if (!*p)
@@ -114,7 +115,8 @@
 	    }
 	    break;
 	case '\002':
-	    p++;
+	    if (++p > q)
+		return -1;
 	    j = 0;
 	    for (;;) {
 		c = edit_get_byte (edit, i);
@@ -150,12 +152,13 @@
 	    }
 	    break;
 	case '\003':
-	    p++;
+	    if (++p > q)
+		return -1;
 	    c = -1;
 	    for (;; i++) {
 		d = c;
 		c = edit_get_byte (edit, i);
-		for (j = 0; p[j] != '\003'; j++)
+		for (j = 0; p[j] != '\003' && p[j]; j++)
 		    if (c == p[j])
 			goto found_char2;
 		break;
@@ -163,20 +166,23 @@
 		j = c;		/* dummy command */
 	    }
 	    i--;
-	    while (*p != '\003')
+	    while (*p != '\003' && p <= q)
 		p++;
+	    if (p > q)
+		return -1;
 	    if (p[1] == d)
 		i--;
 	    break;
 	case '\004':
-	    p++;
+	    if (++p > q)
+		return -1;
 	    c = edit_get_byte (edit, i);
-	    for (; *p != '\004'; p++)
+	    for (; *p != '\004' && *p; p++)
 		if (c == *p)
 		    goto found_char3;
 	    return -1;
 	  found_char3:
-	    for (; *p != '\004'; p++);
+	    for (; *p != '\004' && *p; p++);
 	    break;
 	default:
 	    if (*p != edit_get_byte (edit, i))
@@ -534,14 +540,14 @@
 	if (!*fg)
 	    fg = 0;
     if (fg) {
-	strcpy (f, fg);
+	g_strlcpy (f, fg, sizeof (f));
 	p = strchr (f, '/');
 	if (p)
 	    *p = '\0';
 	fg = f;
     }
     if (bg) {
-	strcpy (b, bg);
+	g_strlcpy (b, bg, sizeof (b));
 	p = strchr (b, '/');
 	if (p)
 	    *p = '\0';
@@ -588,13 +594,16 @@
     int num_words = -1, num_contexts = -1;
     int argc, result = 0;
     int i, j;
+    int alloc_contexts = MAX_CONTEXTS,
+    	alloc_words_per_context = MAX_WORDS_PER_CONTEXT,
+	max_alloc_words_per_context = MAX_WORDS_PER_CONTEXT;
 
     args[0] = 0;
 
     strcpy (whole_left, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_01234567890");
     strcpy (whole_right, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_01234567890");
 
-    r = edit->rules = g_malloc0 (MAX_CONTEXTS * sizeof (struct context_rule *));
+    r = edit->rules = g_malloc (alloc_contexts * sizeof (struct context_rule *));
 
     for (;;) {
 	char **a;
@@ -637,13 +646,13 @@
 	    check_a;
 	    if (!strcmp (*a, "left")) {
 		a++;
-		strcpy (whole_left, *a);
+		g_strlcpy (whole_left, *a, sizeof (whole_left));
 	    } else if (!strcmp (*a, "right")) {
 		a++;
-		strcpy (whole_right, *a);
+		g_strlcpy (whole_right, *a, sizeof (whole_right));
 	    } else {
-		strcpy (whole_left, *a);
-		strcpy (whole_right, *a);
+		g_strlcpy (whole_left, *a, sizeof (whole_left));
+		g_strlcpy (whole_right, *a, sizeof (whole_right));
 	    }
 	    a++;
 	    check_not_a;
@@ -659,6 +668,8 @@
 		c->right = g_strdup (" ");
 		num_contexts = 0;
 	    } else {
+		/* Terminate previous context.  */
+		r[num_contexts - 1]->keyword[num_words] = NULL;
 		c = r[num_contexts] = g_malloc0 (sizeof (struct context_rule));
 		if (!strcmp (*a, "exclusive")) {
 		    a++;
@@ -693,10 +704,7 @@
 		c->first_left = *c->left;
 		c->first_right = *c->right;
 	    }
-	    c->keyword = g_malloc0 (MAX_WORDS_PER_CONTEXT * sizeof (struct key_word *));
-#if 0
-	    c->max_words = MAX_WORDS_PER_CONTEXT;
-#endif
+	    c->keyword = g_malloc (alloc_words_per_context * sizeof (struct key_word *));
 	    num_words = 1;
 	    c->keyword[0] = g_malloc0 (sizeof (struct key_word));
 	    fg = *a;
@@ -705,12 +713,20 @@
 	    bg = *a;
 	    if (*a)
 		a++;
-	    strcpy (last_fg, fg ? fg : "");
-	    strcpy (last_bg, bg ? bg : "");
+	    g_strlcpy (last_fg, fg ? fg : "", sizeof (last_fg));
+	    g_strlcpy (last_bg, bg ? bg : "", sizeof (last_bg));
 	    c->keyword[0]->color = this_try_alloc_color_pair (fg, bg);
 	    c->keyword[0]->keyword = g_strdup (" ");
 	    check_not_a;
-	    num_contexts++;
+
+	    alloc_words_per_context = MAX_WORDS_PER_CONTEXT;
+	    if (++num_contexts >= alloc_contexts) {
+	    	struct context_rule **tmp;
+
+		alloc_contexts += 128;
+		tmp = g_realloc (r, alloc_contexts * sizeof (struct context_rule *));
+		r = tmp;
+	    }
 	} else if (!strcmp (args[0], "spellcheck")) {
 	    if (!c) {
 		result = line;
@@ -757,7 +773,18 @@
 		bg = last_bg;
 	    k->color = this_try_alloc_color_pair (fg, bg);
 	    check_not_a;
-	    num_words++;
+
+	    if (++num_words >= alloc_words_per_context) {
+	    	struct key_word **tmp;
+
+		alloc_words_per_context += 1024;
+
+		if (alloc_words_per_context > max_alloc_words_per_context)
+		    max_alloc_words_per_context = alloc_words_per_context;
+
+		tmp = g_realloc (c->keyword, alloc_words_per_context * sizeof (struct key_word *));
+		c->keyword = tmp;
+	    }
 	} else if (*(args[0]) == '#') {
 	    /* do nothing for comment */
 	} else if (!strcmp (args[0], "file")) {
@@ -771,6 +798,12 @@
     free_args (args);
     syntax_g_free (l);
 
+    /* Terminate context array.  */
+    if (num_contexts > 0) {
+	r[num_contexts - 1]->keyword[num_words] = NULL;
+	r[num_contexts] = NULL;
+    }
+
     if (!edit->rules[0])
 	syntax_g_free (edit->rules);
 
@@ -783,7 +816,10 @@
     }
 
     {
-	char first_chars[MAX_WORDS_PER_CONTEXT + 2], *p;
+	char *first_chars, *p;
+
+	first_chars = g_malloc (max_alloc_words_per_context + 2);
+
 	for (i = 0; edit->rules[i]; i++) {
 	    c = edit->rules[i];
 	    p = first_chars;
@@ -794,6 +830,8 @@
 	    c->keyword_first_chars = g_malloc0 (strlen (first_chars) + 2);
 	    strcpy (c->keyword_first_chars, first_chars);
 	}
+
+	g_free (first_chars);
     }
 
     return result;
