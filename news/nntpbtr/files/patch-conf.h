--- conf.h	1995/06/11 13:16:09	1.6
+++ conf.h	1996/07/02 06:08:08
@@ -4,16 +4,16 @@
  */
 
 /* It is defined for direct pipe to INND without disk batches */
-/* #define	RNEWS	"/usr/bin/rnews"   */
+#define	RNEWS	"/usr/local/bin/rnews"
 
 /*	if undef DBZ and NDBM, then history check will not use	*/
 /*	please use the definition from your CNEWS/INN distributive */
-#define	HISTORY_FILE	"/usr/lib/news/history"
+#define	HISTORY_FILE	"/usr/local/news/lib/history"
 #define	DBZ
 #undef	NDBM
 
 /*	the position of host data file - control info for nntpbtr	*/
-#define	HOSTDIR		"/usr/spool/news/nntpbtr-"
+#define	HOSTDIR		"/var/spool/news/nntpbtr-"
 
 #ifndef		RNEWS
 /*	This is the batch file definitions - where, size and cmd to input news 
@@ -24,22 +24,24 @@
 #define	BATCHINPUTCMD	"/usr/lib/newsbin/input/newsrun", "newsrun", 0
 #endif
 #define	BATCHSIZE	300000
-#define	BATCHTMP	"/usr/spool/news/in.coming/nntp.XXXXXX"
-#define BATCHDIR	"/usr/spool/news/in.coming/"
+#define	BATCHTMP	"/var/spool/news/in.coming/nntp.XXXXXX"
+#define BATCHDIR	"/var/spool/news/in.coming/"
 #endif
 
 /*	This is defined the only for the purpose of disk free check.
 	min free space is in the BLOCKS (1KB or 512 - depend from system).
 	dont't forget here about free space for expire process in CNEWS -
 	- it is need the second "history" file space */
-#define	NEWSSPOOL	"/usr/spool/news"
+#define	NEWSSPOOL	"/var/spool/news"
 #define	MINFREE		30000
 #define	MINFILES 2048 /* one 300KB batch = 150 files, 10 batches enough ? */
+
 #ifndef	RNEWS
-#define	NEWSINCOMING	"/usr/spool/news/in.coming"
+#define	NEWSINCOMING	"/var/spool/news/in.coming"
 	/*  max inputed files in BATCHDIR (-I) 	*/
-#define	MAXINFILES	0    /* max # files in BATCHDIR; 0 -> no check */
 #endif
+#define	MAXINFILES	0    /* max # files in BATCHDIR; 0 -> no check */
+
 	/*  wait time slot to re-check disk space (-m) or batch process (-I)
 	    if not define, when exit(2) without wait */
 /* #define	MINFTIME	60*10	/* time to sleep between new check */
