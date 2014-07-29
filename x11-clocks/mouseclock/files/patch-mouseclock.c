--- mouseclock.c.orig	Sun May  5 09:47:18 1996
+++ mouseclock.c	Mon Oct  6 23:09:43 1997
@@ -31,6 +31,7 @@
 Window Root;
 int shadow_size = 2;
 int shadow_mode = 1;
+int ampm = 0;
 
 /* ---------------------------------------------------------------- */
 void
@@ -56,6 +57,7 @@
   printf ("-display <dpy>   display name\n");
   printf ("-fg <color>      foreground color\n");
   printf ("-fn <font_name>  font to use\n");
+  printf ("-12hr            use 12-hour format\n");
 
   exit (1);
 }
@@ -266,6 +268,11 @@
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
 
@@ -295,7 +302,7 @@
 	  struct tm *now_tm = localtime (&now);
 	  Cursor cur;
 
-	  h = now_tm->tm_hour;
+	  h = ampm && (now_tm->tm_hour - 12 > 0) ? now_tm->tm_hour - 12 : now_tm->tm_hour;
 	  m = now_tm->tm_min;
 
 	  if (h != last_h || m != last_m)
