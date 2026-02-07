--- mode.h.orig	Mon Oct  2 15:16:25 2006
+++ mode.h	Mon Oct  2 15:17:01 2006
@@ -1,6 +1,10 @@
 #
 /*
  *	UNIX shell
+ *
+ *	S. R. Bourne
+ *	Bell Telephone Laboratories
+ *
  */
 
 
@@ -10,23 +14,38 @@
 TYPE char	BOOL;
 TYPE int	UFD;
 TYPE int	INT;
+TYPE unsigned	UINT;
 TYPE float	REAL;
 TYPE char	*ADDRESS;
-TYPE long int	L_INT;
-TYPE int	VOID;
-TYPE unsigned	POS;
+TYPE long	LONG;
+TYPE void	VOID;
+TYPE size_t	POS;
 TYPE char	*STRING;
+TYPE CONST char	*CSTRING;
 TYPE char	MSG[];
+TYPE CONST char	CMSG[];
 TYPE int	PIPE[];
 TYPE char	*STKPTR;
+TYPE const char	*CSTKPTR;
 TYPE char	*BYTPTR;
 
-STRUCT stat	STATBUF;	/* defined in /usr/sys/stat.h */
+TYPE clock_t	CLOCK;
+TYPE mode_t	MODE;
+TYPE off_t	OFFSET;
+TYPE sig_t	SIGPTR;
+TYPE size_t	SIZE;
+TYPE time_t	TIME;
+TYPE uid_t	UID;
+
+STRUCT dirent	*DIRPTR;	/* defined in dirent.h */
+STRUCT stat	STATBUF;	/* defined in sys/stat.h */
+STRUCT tms	TIMEBUF;	/* defined in sys/time.h */
+
 STRUCT blk	*BLKPTR;
 STRUCT fileblk	FILEBLK;
 STRUCT filehdr	FILEHDR;
-STRUCT fileblk	*FILE;
-STRUCT trenod	*TREPTR;
+STRUCT fileblk	*FILEPTR;
+UNION trenod	*TREPTR;
 STRUCT forknod	*FORKPTR;
 STRUCT comnod	*COMPTR;
 STRUCT swnod	*SWPTR;
@@ -43,8 +62,7 @@
 STRUCT namnod	*NAMPTR;
 STRUCT sysnod	SYSNOD;
 STRUCT sysnod	*SYSPTR;
-STRUCT sysnod	SYSTAB[];
-#define NIL	((char*)0)
+#define NIL	((void*)0)
 
 
 /* the following nonsense is required
@@ -52,8 +70,12 @@
  * into an Rvalue so two cheats
  * are necessary, one for each context.
  */
-union { int _cheat;};
-#define Lcheat(a)	((a)._cheat)
+#if defined(RENO)
+#define Lcheat(a)	(*(int *)&(a))
+#else /* V7 */
+union _cheat { int _cheat;};
+#define Lcheat(a)	((*(union _cheat *)&(a))._cheat)
+#endif
 #define Rcheat(a)	((int)(a))
 
 
@@ -69,11 +91,13 @@
 	BLKPTR	_blkptr;
 	NAMPTR	_namptr;
 	BYTPTR	_bytptr;
-	}	address;
+}	address;
 
 
+#if defined(V7)
 /* for functions that do not return values */
 struct void {INT vvvvvvvv;};
+#endif
 
 
 /* heap storage */
@@ -90,7 +114,7 @@
 	STRING	fnxt;
 	STRING	fend;
 	STRING	*feval;
-	FILE	fstak;
+	FILEPTR	fstak;
 	CHAR	fbuf[BUFSIZ];
 };
 
@@ -103,20 +127,16 @@
 	STRING	fnxt;
 	STRING	fend;
 	STRING	*feval;
-	FILE	fstak;
+	FILEPTR	fstak;
 	CHAR	_fbuf[1];
 };
 
 struct sysnod {
-	STRING	sysnam;
+	CSTRING	sysnam;
 	INT	sysval;
 };
 
-/* this node is a proforma for those that follow */
-struct trenod {
-	INT	tretyp;
-	IOPTR	treio;
-};
+STRUCT sysnod	SYSTAB[];
 
 /* dummy for access only */
 struct argnod {
@@ -203,3 +223,16 @@
 #define	PARTYPE		(sizeof(struct parnod))
 #define	LSTTYPE		(sizeof(struct lstnod))
 #define	IOTYPE		(sizeof(struct ionod))
+
+/* this node is a proforma for those that precede */
+union trenod {
+	struct { INT	tretyp; IOPTR	treio; } treio;
+	struct forknod	forknod;
+	struct comnod	comnod;
+	struct ifnod	ifnod;
+	struct whnod	whnod;
+	struct fornod	fornod;
+	struct swnod	swnod;
+	struct parnod	parnod;
+	struct lstnod	lstnod;
+};
