--- gtk/xdgmime/xdgmimecache.h.orig	Mon May 29 20:04:24 2006
+++ gtk/xdgmime/xdgmimecache.h	Mon May 29 20:11:42 2006
@@ -32,9 +32,19 @@
 typedef struct _XdgMimeCache XdgMimeCache;
 
 #ifdef XDG_PREFIX
-#define _xdg_mime_cache_new_from_file        XDG_ENTRY(cache_new_from_file)
-#define _xdg_mime_cache_ref                  XDG_ENTRY(cache_ref)
-#define _xdg_mime_cache_unref                XDG_ENTRY(cache_unref)
+#define _xdg_mime_cache_new_from_file                XDG_ENTRY(cache_new_from_file)
+#define _xdg_mime_cache_ref                          XDG_ENTRY(cache_ref)
+#define _xdg_mime_cache_unref                        XDG_ENTRY(cache_unref)
+#define _xdg_mime_cache_get_mime_type_for_data       XDG_ENTRY(cache_get_mime_type_for_data)
+#define _xdg_mime_cache_get_mime_type_for_file       XDG_ENTRY(cache_get_mime_type_for_file)
+#define _xdg_mime_cache_get_mime_type_from_file_name XDG_ENTRY(cache_get_mime_type_from_file_name)
+#define _xdg_mime_cache_is_valid_mime_type           XDG_ENTRY(cache_is_valid_mime_type)
+#define _xdg_mime_cache_mime_type_equal              XDG_ENTRY(cache_mime_type_equal)
+#define _xdg_mime_cache_media_type_equal             XDG_ENTRY(cache_media_type_equal)
+#define _xdg_mime_cache_mime_type_subclass           XDG_ENTRY(cache_mime_type_subclass)
+#define _xdg_mime_cache_list_mime_parents            XDG_ENTRY(cache_list_mime_parents)
+#define _xdg_mime_cache_unalias_mime_type            XDG_ENTRY(cache_unalias_mime_type)
+#define _xdg_mime_cache_get_max_buffer_extents       XDG_ENTRY(cache_get_max_buffer_extents)
 #endif
 
 extern XdgMimeCache **_caches;
