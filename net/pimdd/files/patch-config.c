--- config.c.orig	Fri Sep 29 11:55:19 2006
+++ config.c	Fri Sep 29 11:55:43 2006
@@ -343,7 +343,7 @@
 		    v->uv_local_pref = n;
 		}
 	    
-	    else if(EQUAL(w, "metric")) 
+	    else if(EQUAL(w, "metric")) {
                 if(EQUAL((w = next_word(&s)), "")) 
                     log(LOG_WARNING, 0,
                         "Missing metric for phyint %s in %s",
@@ -361,7 +361,7 @@
 			    inet_fmt(local, s1), n);
 		    v->uv_local_metric = n;
 		}
-	    
+	    }
 	}		/* if not empty */
 	break;
     }
