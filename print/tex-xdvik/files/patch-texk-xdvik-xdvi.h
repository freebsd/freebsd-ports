--- texk/xdvik/xdvi.h.orig	2020-02-25 20:42:58 UTC
+++ texk/xdvik/xdvi.h
@@ -152,7 +152,7 @@ in xdvi.c.
 #include <X11/Intrinsic.h>
 
 #if HAVE_XI21
-# include <X11/extensions/XInput2.h>	/* for hi-res (smooth) scrolling */
+# include <X11/extensions/XInput2.h>   /* for hi-res (smooth) scrolling */
 #endif
 
 #ifndef MAXPATHLEN
@@ -262,6 +262,10 @@ extern unsigned long time_start, time_end;
 #  define OPEN_MODE_ARGS const char *, const char *
 #endif
 
+#ifdef PTEX
+#define	KTABLESIZE	0x10000
+#endif /* PTEX */
+
 #ifndef __LINE__
 #  define __LINE__ 0
 #endif
@@ -312,6 +316,9 @@ struct frame {
     struct framedata {
 	long dvi_h, dvi_v, w, x, y, z;
 	int pxl_v;
+#ifdef PTEX
+	int tdir;
+#endif /* PTEX */
     } data;
     struct frame *next, *prev;
 };
@@ -470,7 +477,7 @@ extern struct x_resources {
 #endif
     Boolean	freetype;
 #if HAVE_XI21
-    Boolean	xi2scrolling;
+    Boolean    xi2scrolling;
 #endif
     const char *src_pos;
     const char *find_string;
@@ -602,6 +609,9 @@ extern struct x_resources {
     /* bitmask of current search window settings */
     unsigned int    search_window_defaults;
     /*     char *    _scroll_pages; */
+#ifdef PTEX
+    char       *ptexmap;
+#endif /* PTEX */
     char       *help_general;
     char       *help_hypertex;
     char       *help_othercommands;
@@ -941,47 +951,46 @@ extern unsigned int color_list_max;	/* allocated size 
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
 
