--- slang/sltermin.c.orig	Mon Oct  7 18:08:16 2002
+++ slang/sltermin.c	Tue Jun 15 03:15:09 2004
@@ -267,9 +267,12 @@
 
    if (NULL != (home = getenv ("HOME")))
      {
-	strncpy (home_ti, home, sizeof (home_ti) - 11);
-	home_ti [sizeof(home_ti) - 11] = 0;
-	strcat (home_ti, "/.terminfo");
+	size_t len = strlen (home);
+
+	if (len > sizeof (home_ti) - sizeof ("/.terminfo"))
+	  len = sizeof (home_ti) - sizeof ("/.terminfo");
+	memcpy (home_ti, home, len);
+	memcpy (home_ti + len, "/.terminfo", sizeof ("/.terminfo"));
 	Terminfo_Dirs [0] = home_ti;
      }
 
