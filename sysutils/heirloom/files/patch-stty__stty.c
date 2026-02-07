--- stty/stty.c
+++ stty/stty.c
@@ -79,7 +79,7 @@
 static void	lcase(int);
 #endif
 static void	ek(int);
-#ifdef	TABDLY
+#if 0
 static void	tty33(int);
 static void	tty37(int);
 static void	vt05(int);
@@ -410,7 +410,7 @@
 #ifdef	OFDEL
 	{ "fill",	fill,	0,	0,	040,	M_FUNCT },
 #endif
-#ifdef	TABDLY
+#if 0
 	{ "tty33",	tty33,	0,	0,	040,	M_FUNCT },
 	{ "tty37",	tty37,	0,	0,	040,	M_FUNCT },
 	{ "vt05",	vt05,	0,	0,	040,	M_FUNCT },
@@ -1125,7 +1125,7 @@
 	ts.c_cc[VKILL] = '\25';
 }
 
-#ifdef	TABDLY
+#if 0
 static void
 tty33(int not)
 {
