--- conf.h.orig	Mon Nov  4 04:55:08 2002
+++ conf.h	Mon Nov  4 04:55:43 2002
@@ -8,10 +8,12 @@
  */
   
 
-#undef	ALONE		/* True if we're running without inetd */
+#define	ALONE		/* True if we're running without inetd */
 
 #ifdef ALONE
-#undef	FASTFORK        /* True if we don't want to read active file on start*/
+#define	FASTFORK        /* True if we don't want to read active file on start*/
+#define NEWS_GID 8
+#define NEWS_UID 8
 #endif
 
 #define LOAD 5	        /* Loadav above which server refuses connections */
@@ -40,23 +42,23 @@
 #undef TLI		/* Define this if you want to use TLI instead of */
 			/* sockets */
 
-#define NDBM		/* Use new-style (4.3) ndbm(3x) libraries */
+#undef NDBM		/* Use new-style (4.3) ndbm(3x) libraries */
 
 #undef	DBM		/* True if we want to use the old dbm(3x) libraries */
 			/* IF YOU DEFINE THIS, change CFLAGS in makefile to */
 			/* be -ldbm */
 
-#undef	DBZ		/* True if we want to use dbz libraries */
+#define	DBZ		/* True if we want to use dbz libraries */
 			/* IF YOU DEFINE THIS, change CFLAGS in makefile to */
 			/* be /usr/lib/dbz.o and install dbz.h */
 
 #undef	USGHIST		/* Use USG style history file (no DBM) */
 			/* IF YOU DO NOT DEFINE NDBM or DBM, this is DEFAULT!*/
 
-#undef CNEWS		/* define this if you are running C News */
-#undef CNEWS_CLEARTEXT	/* define this if you have a modern C News that handles
+#define CNEWS		/* define this if you are running C News */
+#define CNEWS_CLEARTEXT	/* define this if you have a modern C News that handles
 				input files ending in ".t" as cleartext */
-#undef BATCHED_INPUT	/* define if you want to support C News style 
+#define BATCHED_INPUT	/* define if you want to support C News style 
 				batched input (not supported by B-NEWS)  */
 #undef MSGID		/* define this if you want to run msgidd to keep
 				track of recent msgids via daemon */
@@ -70,9 +72,9 @@
 			/* typedefs for u_long */
 #define VOIDSIG		/* Newfangled signal() returns void, old returns int */
 
-#undef MMAP		/* if your OS supports mmap() */
+#define MMAP		/* if your OS supports mmap() */
 
-#undef DIRENT		/* If you have <dirent.h> define this */
+#define DIRENT		/* If you have <dirent.h> define this */
 
 /*
  * If you DON'T have vfork, make this "#define vfork fork"
@@ -89,7 +91,8 @@
 /*#define MINFILES  MINFREE/4*/
 			/* NNTP will not allow an XFER if there is less */
 			/* than this many inodes on the SPOOLDIR filesystem */
-#undef SETPROCTITLE	/* if you want status visable via ps */
+#define SETPROCTITLE	/* if you want status visable via ps */
+#define HAVE_PROCTITLE	/* if the OS has setproctitle() */
 
 #undef	IHAVE_DEBUG	/* Copious debugging output from ihave */
 
@@ -110,7 +113,7 @@
  * if you are running BNEWS. At least, not yet. :-)
  */
 
-/* #define UMASK 022 */
+#define UMASK 022
 
 /*
  * If you have the syslog library routine, define SYSLOG to
@@ -177,13 +180,13 @@
 #define XOVER		/* xover -- Return .overview data */
 #define OVER_XREFS	/* overview files have xref data in them */
 #define OVER_XREF_PREFIX /* the xref field (if present) includes xref: */
-#define OVER_FMT_FILE	"/usr/lib/news/overview.fmt"
+#define OVER_FMT_FILE	"/usr/local/news/lib/overview.fmt"
 
 /* Leave this undefined to indicate that overview files go in the spool
  * directory.  However, if you want a separate hierarchy of overview
  * files, define it here.
  */
-/*#define OVERVIEW_DIR "/usr/spool/overviews"	/* base directory */
+#define OVERVIEW_DIR "/var/news/over.view"	/* base directory */
 
 #define XROVER		/* xrover -- Return reference overview data */
 
@@ -191,10 +194,10 @@
  * spool directory.  However, if you want a separate hierarchy of rover
  * files, define it here.
  */
-/*#define ROVER_DIR "/usr/spool/overviews"	/* base directory */
+/*define ROVER_DIR "/var/news/r.over"	/* base directory */
 
 #undef XINDEX		/* Optional support for tin's index files */
-#define XINDEX_DIR	"/usr/spool/news/.index"
+#define XINDEX_DIR	"/var/news/.index"
 
 /* XTHREAD defines:  if XTHREAD is defined, THREAD_DIR controls where the
  * thread files will be read from.
@@ -244,27 +247,27 @@
 /*
  * This file is where access information is stored
  */
-#define ACCESS_FILE	"/usr/lib/news/nntp_access"
+#define ACCESS_FILE	"/usr/local/news/lib/nntp_access"
 
 /*
  * The file where the newgroup creation times are kept.  If you don't
  * have C News or INN, you can run acttimes (see the support directory)
  * to maintain an active.times file.
  */
-#define ACTIVE_TIMES_FILE	"/usr/lib/news/active.times"
+#define ACTIVE_TIMES_FILE	"/usr/local/news/lib/active.times"
 
 /*
  * Some commonly used programs and files.
  */
 
-#define	ACTIVE_FILE	"/usr/lib/news/active"
-#define DISTRIBUTIONS_FILE	"/usr/lib/news/distributions"
-#define SUBSCRIPTIONS_FILE	"/usr/lib/news/subscriptions"
-#define NEWSGROUPS_FILE	"/usr/lib/news/newsgroups"
-#define HISTORY_FILE	"/usr/lib/news/history"
-#define	SPOOLDIR	"/usr/spool/news"
-#define INEWS		"/usr/lib/news/inews"
-#define RNEWS		"/usr/bin/rnews"		/* Link to inews? */
+#define	ACTIVE_FILE	"/usr/local/news/lib/active"
+#define DISTRIBUTIONS_FILE	"/usr/local/news/lib/distributions"
+#define SUBSCRIPTIONS_FILE	"/usr/local/news/lib/subscriptions"
+#define NEWSGROUPS_FILE	"/usr/local/news/lib/newsgroups"
+#define HISTORY_FILE	"/usr/local/news/lib/history"
+#define	SPOOLDIR	"/var/news"
+#define INEWS		"/usr/local/news/lib/inews"
+#define RNEWS		"/usr/local/bin/rnews"		/* Link to inews? */
 
 /*
  * Support for C News style batching 
@@ -277,15 +280,15 @@
 #else
 #define TOOBIG 300000L		/* batch > TOOBIG bytes, kick rnews */
 #define TOOMANY 1024		/* batch > TOOMANY articles, kick rnews */
-#define NEWSRUN			"/usr/lib/newsbin/input/newsrun"
+#define NEWSRUN			"/usr/local/news/cnewsbin/input/newsrun"
 #endif
 #define TOOOLD (5*60)		/* batch > TOOOLD seconds old, kick rnews */
 #define COPYSIZE 8192		/* bytes to copy at one time */
 #define MAXDIGITS 25		/* lg(maxlongint) + epsilon */
 #define MAXSTR 1024
-#define INDIR			"/usr/spool/news/in.coming"
+#define INDIR			"/var/news/in.coming"
 /* You may wish to delete the pathname from the front of BATCH_FILE */
-#define BATCH_FILE		"/usr/spool/news/in.coming/nntp.XXXXXX"
+#define BATCH_FILE		"/var/news/in.coming/nntp.XXXXXX"
 
 /************************************************************************/
 /* We don't recommend that you make changes in anything after this line */
