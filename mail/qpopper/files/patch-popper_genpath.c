--- popper/genpath.c.orig	Thu Mar  9 14:32:37 2006
+++ popper/genpath.c		Sat May 13 17:40:25 2006
@@ -133,7 +133,10 @@
             break;
 
         case GNPH_POP:    /* .pop file  */
-            len1 = strlcpy ( pszDrop, p->pCfg_temp_dir, iDropLen );
+	    if (p->bHome_dir_misc == TRUE)
+		len1 = strlcpy (pszDrop, pw->pw_dir,    iDropLen );
+	    else
+		len1 = strlcpy (pszDrop, p->pCfg_temp_dir, iDropLen );
             len2 = strlcat ( pszDrop, "/",              iDropLen );
             break;
 
@@ -143,7 +146,10 @@
             break;
 
         case GNPH_CACHE:   /* .cache file  */
-            len1 = strlcpy ( pszDrop, p->pCfg_cache_dir, iDropLen );
+	    if (p->bHome_dir_misc == TRUE)
+		len1 = strlcpy (pszDrop, pw->pw_dir,    iDropLen );
+	    else
+		len1 = strlcpy (pszDrop, p->pCfg_cache_dir, iDropLen );
             len2 = strlcat ( pszDrop, "/",               iDropLen );
             break;
 
