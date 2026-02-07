- workaround for invalid C/C++ code, see https://github.com/MDAnalysis/mdanalysis/issues/4589

--- MDAnalysis/lib/formats/src/xdrfile.c.orig	2024-05-06 20:07:19 UTC
+++ MDAnalysis/lib/formats/src/xdrfile.c
@@ -132,8 +132,8 @@ struct XDR
 		int (*x_getbytes) (XDR *__xdrs, char *__addr, unsigned int __len);
 		int (*x_putbytes) (XDR *__xdrs, char *__addr, unsigned int __len);
 		/* two next routines are not 64-bit IO safe - don't use! */
-		unsigned int (*x_getpostn) (XDR *__xdrs);
-		int (*x_setpostn) (XDR *__xdrs, unsigned int __pos);
+		off_t (*x_getpostn) (XDR *__xdrs);
+		off_t (*x_setpostn) (XDR *__xdrs, off_t __pos, int);
 		void (*x_destroy) (XDR *__xdrs);
 	}
     *x_ops;
@@ -2519,8 +2519,8 @@ static int xdrstdio_putbytes (XDR *, char *, unsigned 
 static int xdrstdio_putlong (XDR *, int32_t *);
 static int xdrstdio_getbytes (XDR *, char *, unsigned int);
 static int xdrstdio_putbytes (XDR *, char *, unsigned int);
-static int64_t xdrstdio_getpos (XDR *);
-static int xdrstdio_setpos (XDR *, int64_t, int);
+static off_t xdrstdio_getpos (XDR *);
+static off_t xdrstdio_setpos (XDR *, int64_t, int);
 static void xdrstdio_destroy (XDR *);
 
 /*
@@ -2602,7 +2602,7 @@ xdrstdio_putbytes (XDR *xdrs, char *addr, unsigned int
 }
 
 
-static int64_t
+static off_t
 xdrstdio_getpos (XDR *xdrs)
 {
     #ifdef _WIN32
@@ -2612,8 +2612,8 @@ xdrstdio_getpos (XDR *xdrs)
     #endif
 }
 
-static int
-xdrstdio_setpos (XDR *xdrs, int64_t pos, int whence)
+static off_t
+xdrstdio_setpos (XDR *xdrs, off_t pos, int whence)
 {
     /* A reason for failure can be filesystem limits on allocation units,
      * before the actual off_t overflow (ext3, with a 4K clustersize,
