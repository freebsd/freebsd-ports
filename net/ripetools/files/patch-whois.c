--- whois.c.orig	Tue Nov 25 15:41:34 2003
+++ whois.c	Tue Nov 25 15:43:57 2003
@@ -88,7 +88,6 @@
 extern int	getopt(int argc, char * const *argv, const char *optstring);
 extern int	kill(pid_t pid, int sig);
 extern FILE	*fdopen(int fildes, const char *type); 
-extern int	gethostname(char *name, int namelen);
 #else /* !__STDC__ */
 extern int	gethostname();
 #endif /* __STDC__ */
