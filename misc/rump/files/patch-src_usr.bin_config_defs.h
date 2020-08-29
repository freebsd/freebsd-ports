--- src/usr.bin/config/defs.h.orig	2016-08-02 11:51:10 UTC
+++ src/usr.bin/config/defs.h
@@ -428,80 +428,87 @@ struct devm {
  */
 struct hashtab;
 
-int lkmmode;
-const char *conffile;		/* source file, e.g., "GENERIC.sparc" */
-const char *machine;		/* machine type, e.g., "sparc" or "sun3" */
-const char *machinearch;	/* machine arch, e.g., "sparc" or "m68k" */
-struct	nvlist *machinesubarches;
+extern int lkmmode;
+extern const char *conffile;		/* source file, e.g., "GENERIC.sparc" */
+extern const char *machine;		/* machine type, e.g., "sparc" or "sun3" */
+extern const char *machinearch;	/* machine arch, e.g., "sparc" or "m68k" */
+extern struct	nvlist *machinesubarches;
 				/* machine subarches, e.g., "sun68k" or "hpc" */
-const char *ioconfname;		/* ioconf name, mutually exclusive to machine */
-const char *srcdir;		/* path to source directory (rel. to build) */
-const char *builddir;		/* path to build directory */
-const char *defbuilddir;	/* default build directory */
-const char *ident;		/* kernel "ident"ification string */
-int	errors;			/* counts calls to error() */
-int	minmaxusers;		/* minimum "maxusers" parameter */
-int	defmaxusers;		/* default "maxusers" parameter */
-int	maxmaxusers;		/* default "maxusers" parameter */
-int	maxusers;		/* configuration's "maxusers" parameter */
-int	maxpartitions;		/* configuration's "maxpartitions" parameter */
-int	version;		/* version of the configuration file */
-struct	nvlist *options;	/* options */
-struct	nvlist *fsoptions;	/* filesystems */
-struct	nvlist *mkoptions;	/* makeoptions */
-struct	nvlist *appmkoptions;	/* appending mkoptions */
-struct	nvlist *condmkoptions;	/* conditional makeoption table */
-struct	hashtab *devbasetab;	/* devbase lookup */
-struct	hashtab *devroottab;	/* attach at root lookup */
-struct	hashtab *devatab;	/* devbase attachment lookup */
-struct	hashtab *devitab;	/* device instance lookup */
-struct	hashtab *deaddevitab;	/* removed instances lookup */
-struct	hashtab *selecttab;	/* selects things that are "optional foo" */
-struct	hashtab *needcnttab;	/* retains names marked "needs-count" */
-struct	hashtab *opttab;	/* table of configured options */
-struct	hashtab *fsopttab;	/* table of configured file systems */
-struct	dlhash *defopttab;	/* options that have been "defopt"'d */
-struct	dlhash *defflagtab;	/* options that have been "defflag"'d */
-struct	dlhash *defparamtab;	/* options that have been "defparam"'d */
-struct	dlhash *defoptlint;	/* lint values for options */
-struct	nvhash *deffstab;	/* defined file systems */
-struct	dlhash *optfiletab;	/* "defopt"'d option .h files */
-struct	hashtab *attrtab;	/* attributes (locators, etc.) */
-struct	hashtab *attrdeptab;	/* attribute dependencies */
-struct	hashtab *bdevmtab;	/* block devm lookup */
-struct	hashtab *cdevmtab;	/* character devm lookup */
+extern const char *ioconfname;		/* ioconf name, mutually exclusive to machine */
+extern const char *srcdir;		/* path to source directory (rel. to build) */
+extern const char *builddir;		/* path to build directory */
+extern const char *defbuilddir;	/* default build directory */
+extern const char *ident;		/* kernel "ident"ification string */
+extern int	errors;			/* counts calls to error() */
+extern int	minmaxusers;		/* minimum "maxusers" parameter */
+extern int	defmaxusers;		/* default "maxusers" parameter */
+extern int	maxmaxusers;		/* default "maxusers" parameter */
+extern int	maxusers;		/* configuration's "maxusers" parameter */
+extern int	maxpartitions;		/* configuration's "maxpartitions" parameter */
+extern int	version;		/* version of the configuration file */
+extern struct	nvlist *options;	/* options */
+extern struct	nvlist *fsoptions;	/* filesystems */
+extern struct	nvlist *mkoptions;	/* makeoptions */
+extern struct	nvlist *appmkoptions;	/* appending mkoptions */
+extern struct	nvlist *condmkoptions;	/* conditional makeoption table */
+extern struct	hashtab *devbasetab;	/* devbase lookup */
+extern struct	hashtab *devroottab;	/* attach at root lookup */
+extern struct	hashtab *devatab;	/* devbase attachment lookup */
+extern struct	hashtab *devitab;	/* device instance lookup */
+extern struct	hashtab *deaddevitab;	/* removed instances lookup */
+extern struct	hashtab *selecttab;	/* selects things that are "optional foo" */
+extern struct	hashtab *needcnttab;	/* retains names marked "needs-count" */
+extern struct	hashtab *opttab;	/* table of configured options */
+extern struct	hashtab *fsopttab;	/* table of configured file systems */
+extern struct	dlhash *defopttab;	/* options that have been "defopt"'d */
+extern struct	dlhash *defflagtab;	/* options that have been "defflag"'d */
+extern struct	dlhash *defparamtab;	/* options that have been "defparam"'d */
+extern struct	dlhash *defoptlint;	/* lint values for options */
+extern struct	nvhash *deffstab;	/* defined file systems */
+extern struct	dlhash *optfiletab;	/* "defopt"'d option .h files */
+extern struct	hashtab *attrtab;	/* attributes (locators, etc.) */
+extern struct	hashtab *attrdeptab;	/* attribute dependencies */
+extern struct	hashtab *bdevmtab;	/* block devm lookup */
+extern struct	hashtab *cdevmtab;	/* character devm lookup */
 
-TAILQ_HEAD(, devbase)	allbases;	/* list of all devbase structures */
-TAILQ_HEAD(, deva)	alldevas;	/* list of all devbase attachments */
-TAILQ_HEAD(conftq, config) allcf;	/* list of configured kernels */
-TAILQ_HEAD(, devi)	alldevi,	/* list of all instances */
-			allpseudo;	/* list of all pseudo-devices */
-TAILQ_HEAD(, devm)	alldevms;	/* list of all device-majors */
-TAILQ_HEAD(, pspec)	allpspecs;	/* list of all parent specs */
-int	ndevi;				/* number of devi's (before packing) */
-int	npspecs;			/* number of parent specs */
-devmajor_t maxbdevm;			/* max number of block major */
-devmajor_t maxcdevm;			/* max number of character major */
-int	do_devsw;			/* 0 if pre-devsw config */
-int	oktopackage;			/* 0 before setmachine() */
-int	devilevel;			/* used for devi->i_level */
+TAILQ_HEAD(devbasetq, devbase);
+TAILQ_HEAD(devatq, deva);
+TAILQ_HEAD(conftq, config);
+TAILQ_HEAD(devitq, devi);
+TAILQ_HEAD(devmtq, devm);
+TAILQ_HEAD(pspectq, pspec);
 
-struct filelist		allfiles;	/* list of all kernel source files */
-struct filelist		allcfiles;	/* list of all .c files */
-struct filelist		allsfiles;	/* list of all .S files */
-struct filelist		allofiles;	/* list of all .o files */
+extern struct devbasetq allbases; /* list of all devbase structures */
+extern struct devatq alldevas; /* list of all devbase attachments */
+extern struct conftq allcf;/* list of configured kernels */
+extern struct devitq alldevi, /* list of all instances */
+		     allpseudo; /* list of all pseudo-devices */
+extern struct devmtq alldevms; /* list of all device-majors */
+extern struct pspectq allpspecs; /* list of all parent specs */
 
-struct prefixlist	prefixes,	/* prefix stack */
-			allprefixes;	/* all prefixes used (after popped) */
-struct prefixlist	buildprefixes,	/* build prefix stack */
-			allbuildprefixes;/* all build prefixes used (after popped) */
-SLIST_HEAD(, prefix)	curdirs;	/* curdir stack */
+extern int	ndevi;				/* number of devi's (before packing) */
+extern int	npspecs;			/* number of parent specs */
+extern devmajor_t maxbdevm;			/* max number of block major */
+extern devmajor_t maxcdevm;			/* max number of character major */
+extern int	do_devsw;			/* 0 if pre-devsw config */
+extern int	oktopackage;			/* 0 before setmachine() */
+extern int	devilevel;			/* used for devi->i_level */
 
+extern struct filelist		allfiles;	/* list of all kernel source files */
+extern struct filelist		allcfiles;	/* list of all .c files */
+extern struct filelist		allsfiles;	/* list of all .S files */
+extern struct filelist		allofiles;	/* list of all .o files */
+
+extern struct prefixlist	prefixes,	/* prefix stack */
+				allprefixes;	/* all prefixes used (after popped) */
+extern struct prefixlist	buildprefixes,	/* build prefix stack */
+				allbuildprefixes;/* all build prefixes used (after popped) */
+
 extern struct attr allattr;
-struct	devi **packed;		/* arrayified table for packed devi's */
-size_t	npacked;		/* size of packed table, <= ndevi */
+extern struct devi **packed;		/* arrayified table for packed devi's */
+extern size_t npacked;		/* size of packed table, <= ndevi */
 
-struct {			/* loc[] table for config */
+extern struct locators {			/* loc[] table for config */
 	const char **vec;
 	int	used;
 } locators;
