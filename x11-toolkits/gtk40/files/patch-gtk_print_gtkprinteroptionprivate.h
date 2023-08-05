$ gtk4-demo
/usr/local/lib/gtk-4.0/4.0.0/printbackends/libprintbackend-file.so: Undefined symbol "gtk_printer_option_new"
Failed to load module: /usr/local/lib/gtk-4.0/4.0.0/printbackends/libprintbackend-file.so
/usr/local/lib/gtk-4.0/4.0.0/printbackends/libprintbackend-cups.so: Undefined symbol "gtk_printer_option_new"
Failed to load module: /usr/local/lib/gtk-4.0/4.0.0/printbackends/libprintbackend-cups.so
[...]

--- gtk/print/gtkprinteroptionprivate.h.orig	2023-08-05 04:01:26 UTC
+++ gtk/print/gtkprinteroptionprivate.h
@@ -27,6 +27,7 @@
 #endif
 
 #include <glib-object.h>
+#include <gdk/gdk.h>
 
 G_BEGIN_DECLS
 
@@ -89,26 +90,36 @@ GType   gtk_printer_option_get_type       (void) G_GNU
 
 GType   gtk_printer_option_get_type       (void) G_GNUC_CONST;
 
+GDK_AVAILABLE_IN_ALL
 GtkPrinterOption *gtk_printer_option_new                    (const char           *name,
 							     const char           *display_text,
 							     GtkPrinterOptionType  type);
+GDK_AVAILABLE_IN_ALL
 void              gtk_printer_option_set                    (GtkPrinterOption     *option,
 							     const char           *value);
+GDK_AVAILABLE_IN_ALL
 void              gtk_printer_option_set_has_conflict       (GtkPrinterOption     *option,
 							     gboolean              has_conflict);
+GDK_AVAILABLE_IN_ALL
 void              gtk_printer_option_clear_has_conflict     (GtkPrinterOption     *option);
+GDK_AVAILABLE_IN_ALL
 void              gtk_printer_option_set_boolean            (GtkPrinterOption     *option,
 							     gboolean              value);
+GDK_AVAILABLE_IN_ALL
 void              gtk_printer_option_allocate_choices       (GtkPrinterOption     *option,
 							     int                   num);
+GDK_AVAILABLE_IN_ALL
 void              gtk_printer_option_choices_from_array     (GtkPrinterOption     *option,
                                                              int                   num_choices,
                                                              const char           **choices,
                                                              const char           **choices_display);
+GDK_AVAILABLE_IN_ALL
 gboolean          gtk_printer_option_has_choice             (GtkPrinterOption     *option,
 							    const char           *choice);
+GDK_AVAILABLE_IN_ALL
 void              gtk_printer_option_set_activates_default (GtkPrinterOption     *option,
 							    gboolean              activates);
+GDK_AVAILABLE_IN_ALL
 gboolean          gtk_printer_option_get_activates_default (GtkPrinterOption     *option);
 
 
