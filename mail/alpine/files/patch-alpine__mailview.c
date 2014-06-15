--- ./alpine/mailview.c.orig	2013-08-14 23:36:01.000000000 -0500
+++ ./alpine/mailview.c	2014-05-25 19:15:31.000000000 -0500
@@ -178,7 +178,6 @@
 int	    url_local_nntp(char *);
 int	    url_local_news(char *);
 int	    url_local_file(char *);
-int	    url_local_phone_home(char *);
 static int  print_to_printer(SCROLL_S *);
 int	    search_text(int, long, int, char **, Pos *, int *);
 void	    update_scroll_titlebar(long, int);
@@ -1603,7 +1602,6 @@
 	{"x-alpine-gripe:", 15, gripe_gripe_to},
 	{"x-alpine-help:", 14, url_local_helper},
 	{"x-pine-help:", 12, url_local_helper},
-	{"x-alpine-phone-home:", 20, url_local_phone_home},
 	{"x-alpine-config:", 16, url_local_config},
 	{"x-alpine-cert:", 14, url_local_certdetails},
 	{"#", 1, url_local_fragment},
@@ -2158,14 +2156,6 @@
 }
 
 
-int
-url_local_phone_home(char *url)
-{
-    phone_home(url + strlen("x-alpine-phone-home:"));
-    return(2);
-}
-
-
 /*
  * Format editorial comment referencing screen offering
  * List-* header supplied commands
