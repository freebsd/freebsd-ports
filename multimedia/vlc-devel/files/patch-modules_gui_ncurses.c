--- modules/gui/ncurses.c.orig	Wed Nov  3 18:12:49 2004
+++ modules/gui/ncurses.c	Wed Nov  3 18:14:27 2004
@@ -875,7 +875,7 @@
 
 static void SearchPlaylist( intf_thread_t *p_intf, char *psz_searchstring )
 {
-    bool b_ok = false;
+    bool b_ok = 0;
     int i_current;
     int i_first = 0 ;
     int i_item = -1;
@@ -900,7 +900,7 @@
                            psz_searchstring ) != NULL )
         {
             i_item = i_current;
-            b_ok = true;
+            b_ok = 1;
             break;
         }
     }
@@ -914,7 +914,7 @@
                                psz_searchstring ) != NULL )
             {
                 i_item = i_current;
-                b_ok = true;
+                b_ok = 1;
                 break;
             }
         }
