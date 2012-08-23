--- lv.c.orig	2004-01-05 16:30:15.000000000 +0900
+++ lv.c	2012-08-23 16:49:46.728726453 +0900
@@ -2,6 +2,7 @@
  * lv.c
  *
  * All rights reserved. Copyright (C) 1996 by NARITA Tomio.
+ * Copyright (C) Oct 27, 2011 Koichiro IWAO. All rights reserved.
  * $Id: lv.c,v 1.10 2004/01/05 07:30:15 nrt Exp $
  */
 /*
@@ -89,16 +90,35 @@
     grep_mode = FALSE;
 }
 
+private boolean_t isDirectory(byte **file) {
+  struct stat buf;
+  stat((unsigned char *)file, &buf);
+  if (S_ISDIR(buf.st_mode)) {
+    fprintf(stderr, "%s is a directory\n", file);
+    return TRUE;
+  } else {
+    return FALSE;
+  }
+}
+
 private boolean_t LvOpen( conf_t *conf )
 {
+  boolean_t flagIsDirectory = FALSE;
+
   if( NULL != conf->file ){
+    if( TRUE == isDirectory( *conf->file ) ){
+      flagIsDirectory = TRUE;
+    }
     if( NULL == (conf->st = StreamOpen( *conf->file )) ){
       while( NULL != *(++conf->file) ){
-	if( NULL != (conf->st = StreamOpen( *conf->file )) )
-	  return TRUE;
+	if( NULL != (conf->st = StreamOpen( *conf->file )) ){
+          if( TRUE == isDirectory( *conf->file ) ){
+            flagIsDirectory = TRUE;
+	  }
+	}
       }
-      return FALSE;
     }
+    return (TRUE == flagIsDirectory ? FALSE : TRUE);
   } else {
     conf->st = StreamReconnectStdin();
   }
