
$FreeBSD$

--- term.c.orig
+++ term.c
@@ -662,9 +662,9 @@
 #endif
     if (check_term) {
 # ifdef FIONREAD
-	long iocount;
+	int iocount;
 	ioctl(0, FIONREAD, &iocount);
-	return (int)iocount;
+	return iocount;
 # else /* !FIONREAD */
 #  ifdef HAS_RDCHK
 	return rdchk(0);
