--- src/pcf/pcfdriver.c.orig	Fri May 31 15:31:44 2002
+++ src/pcf/pcfdriver.c	Fri May 31 15:16:29 2002
@@ -345,8 +345,8 @@
 #else  /* !FT_CONFIG_OPTION_USE_CMAPS */
 
       /* XXX: charmaps.  For now, report unicode for Unicode and Latin 1 */
-      root->charmaps     = &face->charmap_handle;
-      root->num_charmaps = 1;
+      face->root.charmaps     = &face->charmap_handle;
+      face->root.num_charmaps = 1;
 
       face->charmap.encoding    = ft_encoding_none;
       face->charmap.platform_id = 0;
@@ -359,9 +359,9 @@
         face->charmap.encoding_id = 1;
       }
       
-      face->charmap.face   = root;
+      face->charmap.face   = &face->root;
       face->charmap_handle = &face->charmap;
-      root->charmap        = face->charmap_handle;
+      face->root.charmap        = face->charmap_handle;
 
 #endif /* !FT_CONFIG_OPTION_USE_CMAPS */        
         
