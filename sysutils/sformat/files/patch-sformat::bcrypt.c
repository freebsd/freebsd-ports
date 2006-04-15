--- sformat/bcrypt.c.orig	Fri Oct  9 21:13:57 1998
+++ sformat/bcrypt.c	Thu Apr 13 19:09:55 2006
@@ -27,10 +27,9 @@
 #include <unixstd.h>
 #include <stdxlib.h>
 #include <strdefs.h>
+#include <utypes.h>
 #include "fmt.h"
 
-typedef	unsigned long	Ulong;
-
 EXPORT	char	*getnenv	 __PR((const char *, int));
 EXPORT	Ulong	my_gethostid	__PR((void));
 EXPORT	BOOL	bsecurity	__PR((int));
@@ -104,17 +103,17 @@
 Ulong bcrypt(i)
 	Ulong	i;
 {
-	register Ulong	k;
-	register Ulong	erg;
+	register Uint	k;
+	register Uint	erg;
 
-	k = i + 19991;
+	k = ((Uint)i) + 19991;
 	erg = 0;
 	do {
 		erg += 1 + k / 19;
 		erg *= 1 + k % 19;
 		k /= 11;
 	} while (k != 0);
-	return (erg);
+	return ((Ulong)erg);
 }
 
 
@@ -128,22 +127,24 @@
 char *bmap(i)
 	register Ulong	i;
 {
+	register Uint	l;
 	register int	c;
 	static	char	buf[8];
 	register char	*bp;
 
+	l = (Uint)i;
 	bp = &buf[7];
 	*bp = '\0';
 	do {
-		c = i % 64;
-		i /= 64;
+		c = l % 64;
+		l /= 64;
 		c += '.';
 		if(c > '9')
 			c += 7;
 		if(c > 'Z')
 			c += 6;
 		*--bp = c;
-	} while (i);
+	} while (l);
 	return (bp);
 }
 
@@ -158,10 +159,10 @@
 Ulong bunmap(s)
 	register const char	*s;
 {
-	register Ulong	l;
+	register Uint	l;
 	register int	c;
 
-	l = 0L;
+	l = 0;
 	while (*s) {
 		c = *s++;
 		if(c > 'Z')
@@ -172,5 +173,5 @@
 		l *= 64;
 		l += c;
 	}
-	return (l);
+	return ((Ulong)l);
 }
