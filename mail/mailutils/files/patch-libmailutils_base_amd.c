--- libmailutils/base/amd.c.orig	2020-08-11 05:57:13 UTC
+++ libmailutils/base/amd.c
@@ -254,18 +254,22 @@ amd_msg_bsearch (struct _amd_data *amd, mu_off_t first
   mu_off_t mid;
   int rc;
 
-  if (last < first)
-    return 1;
-  
-  mid = (first + last) / 2;
-  rc = amd->msg_cmp (amd->msg_array[mid], msg);
-  if (rc > 0)
-    return amd_msg_bsearch (amd, first, mid-1, msg, pret);
-  *pret = mid;
-  if (rc < 0)
-    return amd_msg_bsearch (amd, mid+1, last, msg, pret);
-  /* else */
-  return 0;
+  while (first <= last)
+    {
+      mid = (first + last) / 2;
+      rc = amd->msg_cmp (amd->msg_array[mid], msg);
+      if (rc > 0)
+	last = mid - 1;
+      else
+	{
+	  *pret = mid;
+	  if (rc < 0)
+	    first = mid + 1;
+	  else
+	    return 0;
+	}
+    }
+  return 1;
 }
 
 /* Search for message MSG in the message array of AMD.
@@ -318,8 +322,7 @@ amd_msg_lookup (struct _amd_data *amd, struct _amd_mes
     }
   
   rc = amd_msg_bsearch (amd, 0, amd->msg_count - 1, msg, &i);
-  if (rc == 0)
-    *pret = i + 1;
+  *pret = i + 1;
   return rc;
 }
 
