--- server/active.c.orig	Tue Nov  1 06:40:09 1994
+++ server/active.c	Mon Nov  4 05:38:42 2002
@@ -34,7 +34,9 @@
 	register int	i;
 	register int	act_fd;
 	register char	*cp, *end;
+#ifndef __FreeBSD__
 	char		*malloc();
+#endif
 	struct stat	statbuf;
 
 	/*
