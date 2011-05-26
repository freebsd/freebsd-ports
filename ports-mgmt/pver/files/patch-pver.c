--- ./pver.c.orig	2009-04-05 18:35:40.000000000 +0200
+++ ./pver.c	2011-05-26 12:00:10.000000000 +0200
@@ -78,12 +78,14 @@
 	  char *data_sp;
 	  char *show_p;
 	  char *p1, *p2;
+	  int w;
 	  /**
 	   * show_p: dp->d_name 's c-string version
 	   * data_p: data.data 's c-string version
 	   */
 	  asprintf(&show_p, "%.*s", dp->d_namlen, dp->d_name);
-	  asprintf(&data_p, "%.*s", data.DU_LEN, (const char *)data.DU_DATA);
+	  w = data.DU_LEN > INT_MAX ? INT_MAX : data.DU_LEN;
+	  asprintf(&data_p, "%.*s", w, (const char *)data.DU_DATA);
 
 	  /**
 	   * If string data_p contains |, data_p is terminated at |
