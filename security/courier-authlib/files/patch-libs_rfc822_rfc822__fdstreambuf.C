--- libs/rfc822/rfc822_fdstreambuf.C.orig	2026-05-18 09:00:04 UTC
+++ libs/rfc822/rfc822_fdstreambuf.C
@@ -32,12 +32,26 @@ rfc822::fdstreambuf rfc822::fdstreambuf::tmpfile()
 	return tmpfilebuf;
 }
 
+#ifdef __FreeBSD__
 rfc822::fdstreambuf rfc822::fdstreambuf::tmpfile(const char *tmpdir)
 {
+	char *tmpname = tempnam(tmpdir, NULL);
+
+	rfc822::fdstreambuf tmpfilebuf{
+		open(tmpname, O_RDWR|O_EXCL, 0600)
+	};
+
+	free(tmpname);
+	return tmpfilebuf;
+}
+#else
+rfc822::fdstreambuf rfc822::fdstreambuf::tmpfile(const char *tmpdir)
+{
 	return rfc822::fdstreambuf{
 		open(tmpdir, O_TMPFILE|O_RDWR|O_EXCL, 0600)
 	};
 }
+#endif
 
 rfc822::fdstreambuf &rfc822::fdstreambuf::operator=(fdstreambuf &&o) noexcept
 {
