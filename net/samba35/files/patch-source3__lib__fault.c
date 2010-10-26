--- ./source3/lib/fault.c.orig	2010-04-01 15:26:22.000000000 +0200
+++ ./source3/lib/fault.c	2010-04-23 01:08:35.000000000 +0200
@@ -25,6 +25,10 @@
 #endif
 
 
+#ifdef HAVE_SYS_SYSCTL_H
+#include <sys/sysctl.h>
+#endif
+
 #ifdef HAVE_SYS_PRCTL_H
 #include <sys/prctl.h>
 #endif
@@ -143,52 +147,93 @@
  * before dump_core() calls abort.
  */
 #if (defined(FREEBSD) && defined(HAVE_SYSCTLBYNAME))
-static char *get_freebsd_corepath(void)
+/*
+ * Expand the name described in corefilename, using name, uid, and pid.
+ * corefilename is a printf-like string, with three format specifiers:
+ *	%N	name of process ("name")
+ *	%P	process id (pid)
+ *	%U	user id (uid)
+ * For example, "%N.core" is the default; they can be disabled completely
+ * by using "/dev/null", or all core files can be stored in "/cores/%U/%N-%P".
+ */
+static char *get_freebsd_corepath(const char *name)
 {
-	char *tmp_corepath = NULL;
-	char *end = NULL;
-	size_t len = 128;
+	TALLOC_CTX *tmp_ctx;
+	char format[MAXPATHLEN];
+	char *freebsd_corepath = NULL, *buffer = NULL;
+	char *start, *end;
+	size_t len;
 	int ret;
 
-	/* Loop with increasing sizes so we don't allocate too much. */
-	do {
-		if (len > 1024)  {
-			goto err_out;
-		}
-
-		tmp_corepath = (char *)talloc_realloc(NULL, tmp_corepath,
-						      char, len);
-		if (!tmp_corepath) {
-			return NULL;
-		}
-
-		ret = sysctlbyname("kern.corefile", tmp_corepath, &len, NULL,
-				   0);
-		if (ret == -1) {
-			if (errno != ENOMEM) {
-				DEBUG(0, ("sysctlbyname failed getting "
-					  "kern.corefile %s\n",
-					  strerror(errno)));
-				goto err_out;
-			}
-
-			/* Not a large enough array, try a bigger one. */
-			len = len << 1;
-		}
-	} while (ret == -1);
-
+	len = sizeof(format);
+	/* Read format string */
+	if((ret = sysctlbyname("kern.corefile", format, &len, NULL, 0)) == -1) {
+		return NULL;
+	}
 	/* Strip off the common filename expansion */
-	if ((end = strrchr_m(tmp_corepath, '/'))) {
+	if ((end=strrchr_m(format, '/')) != NULL) {
 		*end = '\0';
 	}
+	/* Core file is relative to the cwd */
+	if(!format[0] || format[0] != '/') {
+		return NULL;
+	}
 
-	return tmp_corepath;
-
- err_out:
-	if (tmp_corepath) {
-		talloc_free(tmp_corepath);
+	if((tmp_ctx = talloc_new(NULL)) == NULL) {
+		DEBUG(0, ("talloc_new failed\n"));
+		return NULL;
 	}
-	return NULL;
+	if((buffer = talloc_strdup(tmp_ctx, "")) == NULL) {
+		DEBUG(0, ("talloc_strdup: Out of memory!\n"));
+		goto failed;
+	}
+	/* Parse format string and expand variables */
+	start = format;
+	while((end=strchr_m(start, '%')) != NULL) {
+		/* Copy part of the string without format arguments */
+		if(end != start) {
+			buffer = talloc_strndup_append_buffer(buffer, start, end - start);
+			if(buffer == NULL) {
+				DEBUG(0, ("talloc_strdup: Out of memory!\n"));
+				goto failed;
+			}
+		}
+		start = end + 1;
+		switch (*start) {
+			case '%':
+				buffer = talloc_strdup_append_buffer(buffer, "%%");
+				break;
+			case 'N':	/* process name */
+				buffer = talloc_asprintf_append_buffer(buffer, "%s", name);
+				break;
+			case 'P':	/* process id */
+				buffer = talloc_asprintf_append_buffer(buffer, "%u", getpid());
+				break;
+			case 'U':	/* user id */
+				buffer = talloc_asprintf_append_buffer(buffer, "%u", getuid());
+				break;
+			default:
+				DEBUG(0,(
+				    "Unknown format character %c in "
+				    "corename `%s'\n", *start, format));
+		}
+		if(buffer == NULL) {
+			DEBUG(0, ("talloc_asprintf_append_buffer: Out of memory!\n"));
+			goto failed;
+		}
+		start++;
+	}
+	/* Copy remaining part, if any */
+	if((buffer = talloc_strdup_append_buffer(buffer, start)) == NULL) {
+		DEBUG(0, ("talloc_strdup_append_buffer: Out of memory!\n"));
+		goto failed;
+	}
+	/* Duplicate assembled string in the unattached contenxt */
+	freebsd_corepath = talloc_strdup(NULL, buffer);
+failed:
+	TALLOC_FREE(tmp_ctx);
+
+	return freebsd_corepath;
 }
 #endif
 
@@ -204,8 +249,7 @@
 	/* @todo: Add support for the linux corepath. */
 
 	char *tmp_corepath = NULL;
-	tmp_corepath = get_freebsd_corepath();
-
+	tmp_corepath = get_freebsd_corepath(progname);
 	/* If this has been set correctly, we're done. */
 	if (tmp_corepath) {
 		return tmp_corepath;
@@ -281,7 +325,7 @@
 	SAFE_FREE(logbase);
 }
 
- void dump_core(void)
+void dump_core(void)
 {
 	static bool called;
 
