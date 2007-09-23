--- async/suio_vuprintf.C.orig	2000-10-08 19:18:10.000000000 -0400
+++ async/suio_vuprintf.C	2007-09-15 17:02:44.000000000 -0400
@@ -139,7 +139,7 @@
   int dprec;			/* a copy of prec if [diouxX], 0 otherwise */
   int realsz;			/* field size expanded by dprec */
   int size;			/* size of converted field or string */
-  char *xdigs = "";		/* digits for [xX] conversion */
+  char *xdigs = const_cast<char *> ("");	/* digits for [xX] conversion */
 
   char buf[BUF];                /* space for %c, %[diouxX], %[eEfgG] */
   char ox[2];                   /* space for 0x hex-prefix */
@@ -392,7 +392,7 @@
       /* NOSTRICT */
       _uquad = (u_long) va_arg (ap, void *);
       base = HEX;
-      xdigs = "0123456789abcdef";
+      xdigs = const_cast<char *> ("0123456789abcdef");
       flags |= HEXPREFIX;
       ch = 'x';
       goto nosign;
@@ -403,7 +403,7 @@
       cp = va_arg (ap, char *);
     gotcp:
       if (cp == NULL)
-	  cp = "(null)";
+	  cp = const_cast<char *> ("(null)");
       if (prec >= 0) {
 	/*
 	 * can't use strlen; can only look for the
@@ -434,10 +434,10 @@
       base = DEC;
       goto nosign;
     case 'X':
-      xdigs = "0123456789ABCDEF";
+      xdigs = const_cast<char *> ("0123456789ABCDEF");
       goto hex;
     case 'x':
-      xdigs = "0123456789abcdef";
+      xdigs = const_cast<char *> ("0123456789abcdef");
     hex:
       _uquad = UARG ();
       base = HEX;
@@ -497,7 +497,7 @@
 	  break;
 
 	default:
-	  cp = "bug in vfprintf: bad base";
+	  cp = const_cast<char *> ("bug in vfprintf: bad base");
 	  size = strlen (cp);
 	  goto skipsize;
 	}
