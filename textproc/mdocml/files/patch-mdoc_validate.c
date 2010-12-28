--- mdoc_validate.c
+++ mdoc_validate.c
@@ -2143,6 +2143,8 @@ post_os(POST_ARGS)
 			mdoc_nmsg(m, n, MANDOCERR_MEM);
 			return(0);
 		}
+		if (strncmp(utsname.sysname, "FreeBSD", sizeof("FreeBSD")) == 0)
+			strtok(utsname.release, "-");
 		if (strlcat(buf, utsname.release, BUFSIZ) >= BUFSIZ) {
 			mdoc_nmsg(m, n, MANDOCERR_MEM);
 			return(0);
