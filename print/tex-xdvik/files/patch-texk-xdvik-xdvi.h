--- texk/xdvik/xdvi.h.orig	2014-04-03 01:17:13 UTC
+++ texk/xdvik/xdvi.h
@@ -168,7 +168,7 @@ in xdvi.c.
 #include <X11/Intrinsic.h>
 
 #if HAVE_XI21
-# include <X11/extensions/XInput2.h>	/* for hi-res (smooth) scrolling */
+# include <X11/extensions/XInput2.h>   /* for hi-res (smooth) scrolling */
 #endif
 
 #ifndef MAXPATHLEN
@@ -285,6 +285,10 @@ extern unsigned long time_start, time_en
 #  define OPEN_MODE_ARGS const char *, const char *
 #endif
 
+#ifdef PTEX
+#define	KTABLESIZE	0x10000
+#endif /* PTEX */
+
 #ifndef __LINE__
 #  define __LINE__ 0
 #endif
@@ -335,6 +339,9 @@ struct frame {
     struct framedata {
 	long dvi_h, dvi_v, w, x, y, z;
 	int pxl_v;
+#ifdef PTEX
+	int tdir;
+#endif /* PTEX */
     } data;
     struct frame *next, *prev;
 };
@@ -493,7 +500,7 @@ extern struct x_resources {
 #endif
     Boolean	freetype;
 #if HAVE_XI21
-    Boolean	xi2scrolling;
+    Boolean    xi2scrolling;
 #endif
     const char *src_pos;
     const char *find_string;
@@ -625,6 +632,9 @@ extern struct x_resources {
     /* bitmask of current search window settings */
     unsigned int    search_window_defaults;
     /*     char *    _scroll_pages; */
+#ifdef PTEX
+    char       *ptexmap;
+#endif /* PTEX */
     char       *help_general;
     char       *help_hypertex;
     char       *help_othercommands;
@@ -964,47 +974,46 @@ extern unsigned int color_list_max;	/* a
 extern Boolean color_warned;
 #endif /* COLOR */
 
-
 #if HAVE_XI21
 struct xi2_valinfo {
-	int		number;
-	double		increment;
-	double		lastval;
-	double		lastexact;
-	double		factor;
-	unsigned long	serial;
+       int             number;
+       double          increment;
+       double          lastval;
+       double          lastexact;
+       double          factor;
+       unsigned long   serial;
 };
 
 struct xi2_slave {
-	int		id;			/* slave device id */
-	unsigned int	flags;
-	unsigned char	enabled;
-	unsigned char	btn_mask;	/* buttons corresponding to valuators */
-	struct xi2_valinfo vert, horiz;
-	struct xi2_slave *next;
+       int             id;                     /* slave device id */
+       unsigned int    flags;
+       unsigned char   enabled;
+       unsigned char   btn_mask;       /* buttons corresponding to valuators */
+       struct xi2_valinfo vert, horiz;
+       struct xi2_slave *next;
 };
 
-	/* flag bits */
-# define XI2_SLAVE_VERT			(1<<0)	/* if vert. valuator present */
-# define XI2_SLAVE_HORIZ		(1<<1)	/* if horiz. valuator present */
+       /* flag bits */
+# define XI2_SLAVE_VERT                        (1<<0)  /* if vert. valuator present */
+# define XI2_SLAVE_HORIZ               (1<<1)  /* if horiz. valuator present */
 
 struct xi2_master {
-	int		id;			/* master device id */
-	struct xi2_slave *slave;		/* currently active slave dev */
-	struct xi2_master *next;
+       int             id;                     /* master device id */
+       struct xi2_slave *slave;                /* currently active slave dev */
+       struct xi2_master *next;
 };
 
 
-extern	int		xi2_opcode;
-extern	Boolean		xi2_active;
-extern	struct xi2_master *xi2_masters;		/* linked list of master devs */
-extern	struct xi2_master *xi2_current;		/* current master device */
-extern	struct xi2_slave *xi2_slaves;		/* linked list of slave devs */
+extern int             xi2_opcode;
+extern Boolean         xi2_active;
+extern struct xi2_master *xi2_masters;         /* linked list of master devs */
+extern struct xi2_master *xi2_current;         /* current master device */
+extern struct xi2_slave *xi2_slaves;           /* linked list of slave devs */
 
-extern	struct xi2_slave xi2_no_slave;		/* if no slave assigned yet */
+extern struct xi2_slave xi2_no_slave;          /* if no slave assigned yet */
 
-extern	void	xi2_init_valuators(struct xi2_slave *, XIAnyClassInfo **, int);
-extern	void	xi2_activate(void);
+extern void    xi2_init_valuators(struct xi2_slave *, XIAnyClassInfo **, int);
+extern void    xi2_activate(void);
 
 #endif /* HAVE_XI21 */
 
