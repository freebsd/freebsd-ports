--- mouseclock.c.orig	1996-05-05 16:47:18 UTC
+++ mouseclock.c
@@ -31,6 +31,7 @@ int Scr;
 Window Root;
 int shadow_size = 2;
 int shadow_mode = 1;
+int ampm = 0;
 
 /* ---------------------------------------------------------------- */
 void
@@ -56,6 +57,7 @@ usage (const char *nom)
   printf ("-display <dpy>   display name\n");
   printf ("-fg <color>      foreground color\n");
   printf ("-fn <font_name>  font to use\n");
+  printf ("-12hr            use 12-hour format\n");
 
   exit (1);
 }
@@ -266,6 +268,11 @@ main (int argc, char **argv)
 	  shadow_mode = 0;
 	  continue;
 	}
+      if (!strcmp ("-12hr", argv[i]))
+	{
+	  ampm = 1;
+	  continue;
+	}
       usage (argv[0]);
     }
 
@@ -295,7 +302,7 @@ main (int argc, char **argv)
 	  struct tm *now_tm = localtime (&now);
 	  Cursor cur;
 
-	  h = now_tm->tm_hour;
+	  h = ampm && (now_tm->tm_hour - 12 > 0) ? now_tm->tm_hour - 12 : now_tm->tm_hour;
 	  m = now_tm->tm_min;
 
 	  if (h != last_h || m != last_m)
