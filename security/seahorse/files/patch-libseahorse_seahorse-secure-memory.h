--- libseahorse/seahorse-secure-memory.h.orig	2008-04-11 09:33:34.000000000 -0400
+++ libseahorse/seahorse-secure-memory.h	2008-04-11 09:34:12.000000000 -0400
@@ -34,6 +34,7 @@
     } while (0)
 
 /* This must be called before any glib/gtk/gnome functions */
-void    seahorse_secure_memory_init         (void);
+void     seahorse_secure_memory_init         (void);
+gboolean seahorse_try_gk_secure_memory      (void);
 
 #endif /* _SEAHORSE_SECURE_MEMORY_H_ */
