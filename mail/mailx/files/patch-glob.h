--- glob.h.orig	1994-05-27 12:32:06 UTC
+++ glob.h
@@ -38,51 +38,57 @@
  * def.h must be included first.
  */
 
-int	msgCount;			/* Count of messages read in */
-int	rcvmode;			/* True if receiving mail */
-int	sawcom;				/* Set after first command */
-char	*Tflag;				/* -T temp file for netnews */
-int	senderr;			/* An error while checking */
-int	edit;				/* Indicates editing a file */
-int	readonly;			/* Will be unable to rewrite file */
-int	noreset;			/* String resets suspended */
-int	sourcing;			/* Currently reading variant file */
-int	loading;			/* Loading user definitions */
-int	cond;				/* Current state of conditional exc. */
-FILE	*itf;				/* Input temp file buffer */
-FILE	*otf;				/* Output temp file buffer */
-int	image;				/* File descriptor for image of msg */
-FILE	*input;				/* Current command input file */
-char	mailname[PATHSIZE];		/* Name of current file */
-char	prevfile[PATHSIZE];		/* Name of previous file */
-char	*homedir;			/* Path name of home directory */
-char	*myname;			/* My login name */
-off_t	mailsize;			/* Size of system mailbox */
-int	lexnumber;			/* Number of TNUMBER from scan() */
-char	lexstring[STRINGLEN];		/* String from TSTRING, scan() */
-int	regretp;			/* Pointer to TOS of regret tokens */
-int	regretstack[REGDEP];		/* Stack of regretted tokens */
-char	*string_stack[REGDEP];		/* Stack of regretted strings */
-int	numberstack[REGDEP];		/* Stack of regretted numbers */
-struct	message	*dot;			/* Pointer to current message */
-struct	message	*message;		/* The actual message structure */
-struct	var	*variables[HSHSIZE];	/* Pointer to active var list */
-struct	grouphead	*groups[HSHSIZE];/* Pointer to active groups */
-struct	ignoretab	ignore[2];	/* ignored and retained fields
-					   0 is ignore, 1 is retain */
-struct	ignoretab	saveignore[2];	/* ignored and retained fields
-					   on save to folder */
-struct	ignoretab	ignoreall[2];	/* special, ignore all headers */
-char	**altnames;			/* List of alternate names for user */
-int	debug;				/* Debug flag set */
-int	screenwidth;			/* Screen width, or best guess */
-int	screenheight;			/* Screen height, or best guess,
-					   for "header" command */
-int	realscreenheight;		/* the real screen height */
+#ifdef IN_MAIN
+#define EXTERN
+#else
+#define EXTERN extern
+#endif
 
+EXTERN int	msgCount;			/* Count of messages read in */
+EXTERN int	rcvmode;			/* True if receiving mail */
+EXTERN int	sawcom;				/* Set after first command */
+EXTERN char	*Tflag;				/* -T temp file for netnews */
+EXTERN int	senderr;			/* An error while checking */
+EXTERN int	edit;				/* Indicates editing a file */
+EXTERN int	readonly;			/* Will be unable to rewrite file */
+EXTERN int	noreset;			/* String resets suspended */
+EXTERN int	sourcing;			/* Currently reading variant file */
+EXTERN int	loading;			/* Loading user definitions */
+EXTERN int	cond;				/* Current state of conditional exc. */
+EXTERN FILE	*itf;				/* Input temp file buffer */
+EXTERN FILE	*otf;				/* Output temp file buffer */
+EXTERN int	image;				/* File descriptor for image of msg */
+EXTERN FILE	*input;				/* Current command input file */
+EXTERN char	mailname[PATHSIZE];		/* Name of current file */
+EXTERN char	prevfile[PATHSIZE];		/* Name of previous file */
+EXTERN char	*homedir;			/* Path name of home directory */
+EXTERN char	*myname;			/* My login name */
+EXTERN off_t	mailsize;			/* Size of system mailbox */
+EXTERN int	lexnumber;			/* Number of TNUMBER from scan() */
+EXTERN char	lexstring[STRINGLEN];		/* String from TSTRING, scan() */
+EXTERN int	regretp;			/* Pointer to TOS of regret tokens */
+EXTERN int	regretstack[REGDEP];		/* Stack of regretted tokens */
+EXTERN char	*string_stack[REGDEP];		/* Stack of regretted strings */
+EXTERN int	numberstack[REGDEP];		/* Stack of regretted numbers */
+EXTERN struct	message	*dot;			/* Pointer to current message */
+EXTERN struct	message	*message;		/* The actual message structure */
+EXTERN struct	var	*variables[HSHSIZE];	/* Pointer to active var list */
+EXTERN struct	grouphead	*groups[HSHSIZE];/* Pointer to active groups */
+EXTERN struct	ignoretab	ignore[2];	/* ignored and retained fields
+	 					   0 is ignore, 1 is retain */
+EXTERN struct	ignoretab	saveignore[2];	/* ignored and retained fields
+	 					   on save to folder */
+EXTERN struct	ignoretab	ignoreall[2];	/* special, ignore all headers */
+EXTERN char	**altnames;			/* List of alternate names for user */
+EXTERN int	debug;				/* Debug flag set */
+EXTERN int	screenwidth;			/* Screen width, or best guess */
+EXTERN int	screenheight;			/* Screen height, or best guess,
+						   for "header" command */
+EXTERN int	realscreenheight;		/* the real screen height */
+
 #include <setjmp.h>
 
-jmp_buf	srbuf;
+EXTERN jmp_buf	srbuf;
 
 
 /*
@@ -93,7 +99,7 @@ jmp_buf	srbuf;
  */
 
 #define	NSPACE	25			/* Total number of string spaces */
-struct strings {
+EXTERN struct strings {
 	char	*s_topFree;		/* Beginning of this area */
 	char	*s_nextFree;		/* Next alloctable place here */
 	unsigned s_nleft;		/* Number of bytes left here */
