--- lib/krb5/os/an_to_ln.c.orig	Tue Sep  3 12:29:34 2002
+++ lib/krb5/os/an_to_ln.c	Fri Jun  4 09:19:24 2004
@@ -270,9 +270,14 @@
  * If no regcomp() then just return the input string verbatim in the output
  * string.
  */
-static void
+#define use_bytes(x) \
+    out_used += (x); \
+    if (out_used > MAX_FORMAT_BUFFER) goto mem_err
+
+static int
 do_replacement(char *regexp, char *repl, int doall, char *in, char *out)
 {
+    size_t out_used = 0;
 #if	HAVE_REGCOMP
     regex_t	match_exp;
     regmatch_t	match_match;
@@ -287,17 +292,22 @@
 	do {
 	    if (!regexec(&match_exp, cp, 1, &match_match, 0)) {
 		if (match_match.rm_so) {
+		    use_bytes(match_match.rm_so);
 		    strncpy(op, cp, match_match.rm_so);
 		    op += match_match.rm_so;
 		}
+		use_bytes(strlen(repl));
 		strncpy(op, repl, MAX_FORMAT_BUFFER - 1 - (op - out));
 		op += strlen(op);
 		cp += match_match.rm_eo;
-		if (!doall)
+		if (!doall) {
+		    use_bytes(strlen(cp));
 		    strncpy(op, cp, MAX_FORMAT_BUFFER - 1 - (op - out));
+		}
 		matched = 1;
 	    }
 	    else {
+		use_bytes(strlen(cp));
 		strncpy(op, cp, MAX_FORMAT_BUFFER - 1 - (op - out));
 		matched = 0;
 	    }
@@ -322,17 +332,22 @@
 	    sdispl = (size_t) (loc1 - cp);
 	    edispl = (size_t) (loc2 - cp);
 	    if (sdispl) {
+		use_bytes(sdispl);
 		strncpy(op, cp, sdispl);
 		op += sdispl;
 	    }
+	    use_bytes(strlen(repl));
 	    strncpy(op, repl, MAX_FORMAT_BUFFER - 1 - (op - out));
 	    op += strlen(repl);
 	    cp += edispl;
-	    if (!doall)
+	    if (!doall) {
+		use_bytes(strlen(cp));
 		strncpy(op, cp, MAX_FORMAT_BUFFER - 1 - (op - out));
+	    }
 	    matched = 1;
 	}
 	else {
+	    use_bytes(strlen(cp));
 	    strncpy(op, cp, MAX_FORMAT_BUFFER - 1 - (op - out));
 	    matched = 0;
 	}
@@ -340,7 +355,15 @@
 #else	/* HAVE_REGEXP_H */
     memcpy(out, in, MAX_FORMAT_BUFFER);
 #endif	/* HAVE_REGCOMP */
+    return 1;
+ mem_err:
+#ifdef HAVE_REGCMP
+    	regfree(&match_exp);
+#endif
+	return 0;
+	
 }
+#undef use_bytes
 
 /*
  * aname_replacer()	- Perform the specified substitutions on the input
@@ -412,7 +435,12 @@
 
 		    /* Do the replacemenbt */
 		    memset(out, '\0', MAX_FORMAT_BUFFER);
-		    do_replacement(rule, repl, doglobal, in, out);
+		    if (!do_replacement(rule, repl, doglobal, in, out)) {
+			free(rule);
+		    free(repl);
+			kret = KRB5_LNAME_NOTRANS;
+			break;
+		    }
 		    free(rule);
 		    free(repl);
 
@@ -459,6 +487,7 @@
     char		*fprincname;
     char		*selstring = 0;
     int			num_comps, compind;
+    size_t selstring_used;
     char		*cout;
     krb5_data		*datap;
     char		*outstring;
@@ -479,6 +508,7 @@
 		     */
 		    current = strchr(current, ':');
 		    selstring = (char *) malloc(MAX_FORMAT_BUFFER);
+		    selstring_used = 0;
 		    if (current && selstring) {
 			current++;
 			cout = selstring;
@@ -497,6 +527,14 @@
 								  aname,
 								  compind-1))
 				    ) {
+				    if ((datap->length < MAX_FORMAT_BUFFER)
+					&&  (selstring_used+datap->length
+					     < MAX_FORMAT_BUFFER)) {
+					selstring_used += datap->length;
+				    } else {
+					kret = ENOMEM;
+					goto errout;
+				    }
 				    strncpy(cout,
 					    datap->data,
 					    (unsigned) datap->length);
@@ -527,7 +565,7 @@
 			else
 			    kret = KRB5_CONFIG_BADFORMAT;
 
-			if (kret)
+			errout: if (kret)
 			    free(selstring);
 		    }
 		}
@@ -643,7 +681,7 @@
     const char		*hierarchy[5];
     char		**mapping_values;
     int			i, nvalid;
-    char		*cp;
+    char		*cp, *s;
     char		*typep, *argp;
     unsigned int        lnsize;
 
@@ -677,11 +715,14 @@
 
 		    /* Just use the last one. */
 		    /* Trim the value. */
-		    cp = &mapping_values[nvalid-1]
-			[strlen(mapping_values[nvalid-1])];
-		    while (isspace((int) (*cp))) cp--;
-		    cp++;
-		    *cp = '\0';
+		    s = mapping_values[nvalid-1];
+		    cp = s + strlen(s);
+		    while (cp > s) {
+			cp--;
+			if (!isspace((int)(*cp)))
+			    break;
+			*cp = '\0';
+		    }
 
 		    /* Copy out the value if there's enough room */
 		    if (strlen(mapping_values[nvalid-1])+1 <= (size_t) lnsize)
