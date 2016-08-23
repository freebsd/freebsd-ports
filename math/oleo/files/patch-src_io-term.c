--- src/io-term.c.orig	2001-02-13 23:38:06 UTC
+++ src/io-term.c
@@ -1,7 +1,7 @@
 /*
  * $Id: io-term.c,v 1.51 2001/02/13 23:38:06 danny Exp $
  *
- * Copyright © 1990, 1992, 1993, 1999, 2000, 2001 Free Software Foundation, Inc.
+ * Copyright 1990, 1992, 1993, 1999, 2000, 2001 Free Software Foundation, Inc.
  * 
  * This file is part of Oleo, the GNU Spreadsheet.
  * 
@@ -220,6 +220,7 @@ do_set_option (char *ptr)
 {
   int	set_opt = 1;
   int	i, l;
+  int *tmp;
   char	*p;
 
   while (*ptr == ' ')
@@ -234,9 +235,11 @@ do_set_option (char *ptr)
 
 		if (Preferences[i].copynext) {
 			ptr += strlen(Preferences[i].name) + 1;
-			((char *)Preferences[i].var) = strdup(ptr);
-		} else if (Preferences[i].var)
-			*((int *)Preferences[i].var) = Preferences[i].value;
+			Preferences[i].var = strdup(ptr);
+		} else if (Preferences[i].var) {
+         tmp = Preferences[i].var;
+			*tmp = Preferences[i].value;
+      }
 
 		if (Preferences[i].cont == 0)
 			return 1;
@@ -1023,7 +1026,7 @@ main (int argc, char **argv)
 	  case 'v':
 	  case 'V':
 	    printf(_("%s %s\n"), GNU_PACKAGE, VERSION);
-            printf(_("Copyright © 1992-2000 Free Software Foundation, Inc.\n"));
+            printf(_("Copyright 1992-2000 Free Software Foundation, Inc.\n"));
             printf(_("%s comes with ABSOLUTELY NO WARRANTY.\n"), GNU_PACKAGE);
             printf(_("You may redistribute copies of %s\n"), PACKAGE);
             printf(_("under the terms of the GNU General Public License.\n"));
