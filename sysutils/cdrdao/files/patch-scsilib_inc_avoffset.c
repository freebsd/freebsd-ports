--- scsilib/inc/avoffset.c.orig	2018-05-16 10:46:58 UTC
+++ scsilib/inc/avoffset.c
@@ -61,7 +61,7 @@ main(ac, av)
 {
 	int		stdir;
 #ifdef	HAVE_SCANSTACK
-	register struct frame *fp;
+	volatile struct frame *fp;
 	register int	i = 0;
 	register int	o = 0;
 
