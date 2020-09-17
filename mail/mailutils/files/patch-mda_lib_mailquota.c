--- mda/lib/mailquota.c.orig	2020-08-08 20:32:07 UTC
+++ mda/lib/mailquota.c
@@ -270,16 +270,10 @@ sql_retrieve_quota (char *name, mu_off_t *quota)
 	}
       else if (tmp == NULL || tmp[0] == 0 || mu_c_strcasecmp (tmp, "none") == 0)
 	rc = RETR_UNLIMITED;
-      else
+      else if (get_quota (quota, tmp)) 
 	{
-	  char *p;
-	  
-	  if (get_size (tmp, quota, &p))
-	    {
-	      mu_error (_("bogus mailbox quota for `%s' (near `%s')"),
-			name, p);
-	      *quota = groupquota;
-	    }
+	  *quota = groupquota;
+	  rc = RETR_OK;
 	}
     }
   
