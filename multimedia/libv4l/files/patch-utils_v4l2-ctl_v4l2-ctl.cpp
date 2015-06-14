--- utils/v4l2-ctl/v4l2-ctl.cpp.orig	2015-06-14 00:23:03.316457000 -0400
+++ utils/v4l2-ctl/v4l2-ctl.cpp	2015-06-14 00:28:46.421843000 -0400
@@ -614,9 +614,50 @@ static std::string cap2s(unsigned cap)
 	return s;
 }
 
+#if __FreeBSD_version < 1000000
+/* from FreeBSD src/lib/libc/string/strchrnul.c: */
+
+char *strchrnul(const char *p, int ch);
+
+char *
+strchrnul(const char *p, int ch)
+{
+	char c;
+
+	c = ch;
+	for (;; ++p) {
+		if (*p == c || *p == '\0')
+			return ((char *)p);
+	}
+	/* NOTREACHED */
+}
+#endif
+
+int
+my_getsubopt(char **optionp, char *const *tokens, char **valuep)
+{
+	char *endp, *vstart;
+	int cnt;
+
+	if (**optionp == '\0')
+	  return -1;
+
+	/* Find end of next token. */
+	endp = strchrnul (*optionp, ',');
+
+	/* The current suboption does not match any option. */
+	*valuep = *optionp;
+
+	if (*endp != '\0')
+		*endp++ = '\0';
+	*optionp = endp;
+
+	return -1;
+}
+
 int parse_subopt(char **subs, const char * const *subopts, char **value)
 {
-	int opt = getsubopt(subs, (char * const *)subopts, value);
+	int opt = my_getsubopt(subs, (char * const *)subopts, value);
 
 	if (opt == -1) {
 		fprintf(stderr, "Invalid suboptions specified\n");
