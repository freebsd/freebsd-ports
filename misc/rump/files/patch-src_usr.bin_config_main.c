--- src/usr.bin/config/main.c.orig	2020-08-29 04:33:06 UTC
+++ src/usr.bin/config/main.c
@@ -86,6 +86,78 @@ COPYRIGHT("@(#) Copyright (c) 1992, 1993\
 #define LINE_MAX 1024
 #endif
 
+struct devbasetq allbases;
+struct devatq alldevas;
+struct conftq allcf;
+struct devitq alldevi, allpseudo;
+struct devmtq alldevms;
+struct pspectq allpspecs;
+
+struct devi **packed;
+size_t npacked;
+
+struct locators locators;
+
+int lkmmode;
+const char *conffile;		/* source file, e.g., "GENERIC.sparc" */
+const char *machine;		/* machine type, e.g., "sparc" or "sun3" */
+const char *machinearch;	/* machine arch, e.g., "sparc" or "m68k" */
+struct	nvlist *machinesubarches;
+				/* machine subarches, e.g., "sun68k" or "hpc" */
+const char *ioconfname;		/* ioconf name, mutually exclusive to machine */
+const char *srcdir;		/* path to source directory (rel. to build) */
+const char *builddir;		/* path to build directory */
+const char *defbuilddir;	/* default build directory */
+const char *ident;		/* kernel "ident"ification string */
+int	errors;			/* counts calls to error() */
+int	minmaxusers;		/* minimum "maxusers" parameter */
+int	defmaxusers;		/* default "maxusers" parameter */
+int	maxmaxusers;		/* default "maxusers" parameter */
+int	maxusers;		/* configuration's "maxusers" parameter */
+int	maxpartitions;		/* configuration's "maxpartitions" parameter */
+int	version;		/* version of the configuration file */
+struct	nvlist *options;	/* options */
+struct	nvlist *fsoptions;	/* filesystems */
+struct	nvlist *mkoptions;	/* makeoptions */
+struct	nvlist *appmkoptions;	/* appending mkoptions */
+struct	nvlist *condmkoptions;	/* conditional makeoption table */
+struct	hashtab *devbasetab;	/* devbase lookup */
+struct	hashtab *devroottab;	/* attach at root lookup */
+struct	hashtab *devatab;	/* devbase attachment lookup */
+struct	hashtab *deaddevitab;	/* removed instances lookup */
+struct	hashtab *selecttab;	/* selects things that are "optional foo" */
+struct	hashtab *needcnttab;	/* retains names marked "needs-count" */
+struct	hashtab *opttab;	/* table of configured options */
+struct	hashtab *fsopttab;	/* table of configured file systems */
+struct	dlhash *defopttab;	/* options that have been "defopt"'d */
+struct	dlhash *defflagtab;	/* options that have been "defflag"'d */
+struct	dlhash *defparamtab;	/* options that have been "defparam"'d */
+struct	dlhash *defoptlint;	/* lint values for options */
+struct	nvhash *deffstab;	/* defined file systems */
+struct	dlhash *optfiletab;	/* "defopt"'d option .h files */
+struct	hashtab *attrtab;	/* attributes (locators, etc.) */
+struct	hashtab *attrdeptab;	/* attribute dependencies */
+struct	hashtab *bdevmtab;	/* block devm lookup */
+struct	hashtab *cdevmtab;	/* character devm lookup */
+
+int	ndevi;				/* number of devi's (before packing) */
+int	npspecs;			/* number of parent specs */
+devmajor_t maxbdevm;			/* max number of block major */
+devmajor_t maxcdevm;			/* max number of character major */
+int	do_devsw;			/* 0 if pre-devsw config */
+int	oktopackage;			/* 0 before setmachine() */
+int	devilevel;			/* used for devi->i_level */
+
+struct filelist		allfiles;	/* list of all kernel source files */
+struct filelist		allcfiles;	/* list of all .c files */
+struct filelist		allsfiles;	/* list of all .S files */
+struct filelist		allofiles;	/* list of all .o files */
+
+struct prefixlist	prefixes,	/* prefix stack */
+			allprefixes;	/* all prefixes used (after popped) */
+struct prefixlist	buildprefixes,	/* build prefix stack */
+			allbuildprefixes;/* all build prefixes used (after popped) */
+
 int	vflag;				/* verbose output */
 int	Pflag;				/* pack locators */
 int	Lflag;				/* lint config generation */
