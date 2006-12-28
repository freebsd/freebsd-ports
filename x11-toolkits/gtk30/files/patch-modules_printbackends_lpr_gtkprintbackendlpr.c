--- modules/printbackends/lpr/gtkprintbackendlpr.c.orig	Wed Dec 27 21:25:12 2006
+++ modules/printbackends/lpr/gtkprintbackendlpr.c	Wed Dec 27 21:14:47 2006
@@ -372,6 +372,8 @@ gtk_print_backend_lpr_print_stream (GtkP
       goto out;
     }
 
+  g_io_channel_set_close_on_unref (ps->in, TRUE);
+
   g_io_add_watch (data_io, 
                   G_IO_IN | G_IO_PRI | G_IO_ERR | G_IO_HUP,
                   (GIOFunc) lpr_write,
