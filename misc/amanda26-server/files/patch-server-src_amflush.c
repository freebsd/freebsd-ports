--- server-src/amflush.c.orig	2011-06-25 22:52:32.000000000 +0200
+++ server-src/amflush.c	2011-06-25 22:54:16.000000000 +0200
@@ -241,7 +241,7 @@
 		    stralloc((char *)datestamp->data),
 		    g_compare_strings);
 	}
-	g_slist_free_full(all_datestamps);
+	_slist_free_full(all_datestamps, g_free);
     }
     else {
 	/* otherwise, in batch mode, use all datestamps */
@@ -390,9 +390,9 @@
 	}
     }
 
-    g_slist_free_full(datestamp_list);
+    _slist_free_full(datestamp_list, g_free);
     datestamp_list = NULL;
-    g_slist_free_full(holding_list);
+    _slist_free_full(holding_list, g_free);
     holding_list = NULL;
 
     if(redirect) { /* rename errfile */
@@ -583,7 +583,7 @@
 		}
 		chupper = (char)toupper(ch);
 		if (chupper < 'A' || chupper > max_char) {
-		    g_slist_free_full(r_datestamp_list);
+		    _slist_free_full(r_datestamp_list, g_free);
 		    r_datestamp_list = NULL;
 		    break;
 		}
@@ -591,7 +591,7 @@
 					   stralloc(datestamps[chupper - 'A']));
 	    } while ((ch = *a++) != '\0');
 	    if (r_datestamp_list && ch == '\0') {
-		g_slist_free_full(datestamp_list);
+		_slist_free_full(datestamp_list, g_free);
 		datestamp_list = r_datestamp_list;
 		break;
 	    }
