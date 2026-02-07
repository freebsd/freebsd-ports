--- fig2dev/fig2dev.h.orig	2010-03-16 18:53:20 UTC
+++ fig2dev/fig2dev.h
@@ -126,7 +126,7 @@ extern int	PSisomap[];
 extern char	*prog, *from, *to;
 extern char	*name;
 extern double	font_size;
-Boolean	correct_font_size;	/* use correct font size */
+extern Boolean	correct_font_size;	/* use correct font size */
 extern double	mag, fontmag;
 extern FILE	*tfp;
 
@@ -214,7 +214,7 @@ struct Cmap {
 #endif /* MAXPATHLEN */
 #endif /* PATH_MAX */
 
-#if ( !defined(__NetBSD__) && !defined(__DARWIN__) && !defined(__FreeBSD) )
+#if ( !defined(__NetBSD__) && !defined(__DARWIN__) && !defined(__FreeBSD__) )
 extern int		sys_nerr, errno;
 #endif
 
