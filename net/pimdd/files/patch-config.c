--- config.c.orig	1999-11-30 17:58:53 UTC
+++ config.c
@@ -343,7 +343,7 @@ parse_phyint(s)
 		    v->uv_local_pref = n;
 		}
 	    
-	    else if(EQUAL(w, "metric")) 
+	    else if(EQUAL(w, "metric")) {
                 if(EQUAL((w = next_word(&s)), "")) 
                     log(LOG_WARNING, 0,
                         "Missing metric for phyint %s in %s",
@@ -361,7 +361,7 @@ parse_phyint(s)
 			    inet_fmt(local, s1), n);
 		    v->uv_local_metric = n;
 		}
-	    
+	    }
 	}		/* if not empty */
 	break;
     }
