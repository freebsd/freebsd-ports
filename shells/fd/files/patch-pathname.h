[FDclone-users:00266]
  Properly expand globs like <"/usr/"*> and </usr\/*>.
--- pathname.h.orig	Sat Apr 24 03:37:06 2004
+++ pathname.h	Fri May 21 00:23:15 2004
@@ -104,6 +104,12 @@
 #define	CM_RECALC	0100
 #define	CM_REHASH	0200
 
+typedef struct _strbuf_t {
+	char *s;
+	ALLOC_T size;
+	ALLOC_T len;
+} strbuf_t;
+
 #ifndef	NODIRLOOP
 typedef struct _devino_t {
 	dev_t dev;
@@ -111,6 +117,18 @@
 } devino_t;
 #endif
 
+typedef struct _wild_t {
+	char *s;
+	strbuf_t fixed;
+	strbuf_t path;
+	int quote;
+#ifndef	NODIRLOOP
+	int nino;
+	devino_t *ino;
+#endif
+	u_char flags;
+} wild_t;
+
 #ifdef	NOUID_T
 typedef u_short	uid_t;
 typedef u_short	gid_t;
@@ -202,7 +220,7 @@
 extern int regexp_exec __P_((reg_t *, char *, int));
 extern VOID regexp_free __P_((reg_t *));
 extern int cmppath __P_((CONST VOID_P, CONST VOID_P));
-extern char **evalwild __P_((char *));
+extern char **evalwild __P_((char *, int));
 #ifndef	_NOUSEHASH
 hashlist **duplhash __P_((hashlist **));
 #endif
