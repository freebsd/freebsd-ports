- workaround for invalid C/C++ code, see https://github.com/MDAnalysis/mdanalysis/issues/4589

--- MDAnalysis/lib/formats/src/xdrfile.c.orig	2025-10-17 00:00:00 UTC
+++ MDAnalysis/lib/formats/src/xdrfile.c
@@ -132,8 +132,8 @@ struct XDR
 		int (*x_getbytes) (XDR *__xdrs, char *__addr, unsigned int __len);
 		int (*x_putbytes) (XDR *__xdrs, char *__addr, unsigned int __len);
 		/* two next routines are not 64-bit IO safe - don't use! */
-		int64_t (*x_getpostn) (XDR *__xdrs);
-		int (*x_setpostn) (XDR *__xdrs, int64_t __pos, int __whence);
+		off_t (*x_getpostn) (XDR *__xdrs);
+		off_t (*x_setpostn) (XDR *__xdrs, off_t __pos, int __whence);
 		void (*x_destroy) (XDR *__xdrs);
 	}
     *x_ops;
