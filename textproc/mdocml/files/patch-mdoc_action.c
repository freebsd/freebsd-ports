--- mdoc_action.c
+++ mdoc_action.c
@@ -609,6 +609,8 @@ post_os(POST_ARGS)
 			mdoc_nmsg(m, n, MANDOCERR_MEM);
 			return(0);
 		}
+		if (strncmp(utsname.sysname, "FreeBSD", sizeof("FreeBSD")) == 0)
+			strtok(utsname.release, "-");
 		if (strlcat(buf, utsname.release, BUFSIZ) >= BUFSIZ) {
 			mdoc_nmsg(m, n, MANDOCERR_MEM);
 			return(0);
