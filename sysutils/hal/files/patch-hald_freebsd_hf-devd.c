--- hald/freebsd/hf-devd.c.orig	2009-08-24 08:42:29.000000000 -0400
+++ hald/freebsd/hf-devd.c	2011-02-26 13:03:00.000000000 -0500
@@ -122,7 +122,7 @@ hf_devd_parse_add_remove (const char *ev
   g_return_val_if_fail(parent != NULL, FALSE);
 
   if ((params_ptr = strchr(event, ' '))
-      && (at_ptr = strstr(params_ptr + 1, " at "))
+      && (at_ptr = strstr(params_ptr, "at "))
       && (parent_ptr = strstr(at_ptr + 4, " on ")))
     {
       char *params_str;
@@ -130,7 +130,7 @@ hf_devd_parse_add_remove (const char *ev
 
       *name = g_strndup(event, params_ptr - event);
       params_str = g_strndup(params_ptr + 1, at_ptr - params_ptr - 1);
-      at_str = g_strndup(at_ptr + 4, parent_ptr - at_ptr - 4);
+      at_str = g_strndup(at_ptr + 3, parent_ptr - at_ptr - 3);
       *parent = g_strdup(parent_ptr + 4);
 
       if (! strcmp(*parent, ".")) /* sys/kern/subr_bus.c */
@@ -398,7 +398,7 @@ hf_devd_event_cb (GIOChannel *source, GI
       hf_devd_process_event(event);
       g_free(event);
     }
-  else if (status == G_IO_STATUS_AGAIN)
+  else if (status == G_IO_STATUS_AGAIN || status == G_IO_STATUS_EOF)
     {
       hf_devd_init();
       if (hf_devd_inited)
