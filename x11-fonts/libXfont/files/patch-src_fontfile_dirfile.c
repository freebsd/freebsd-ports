CVE-2014-0209

--- src/fontfile/dirfile.c.orig	2014-01-07 17:25:08.000000000 +0100
+++ src/fontfile/dirfile.c	2014-05-13 18:15:26.000000000 +0200
@@ -42,6 +42,7 @@ in this Software without prior written a
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <errno.h>
+#include <limits.h>
 
 static Bool AddFileNameAliases ( FontDirectoryPtr dir );
 static int ReadFontAlias ( char *directory, Bool isFile,
@@ -374,6 +375,9 @@ lexAlias(FILE *file, char **lexToken)
 	    int         nsize;
 	    char       *nbuf;
 
+	    if (tokenSize >= (INT_MAX >> 2))
+		/* Stop before we overflow */
+		return EALLOC;
 	    nsize = tokenSize ? (tokenSize << 1) : 64;
 	    nbuf = realloc(tokenBuf, nsize);
 	    if (!nbuf)
