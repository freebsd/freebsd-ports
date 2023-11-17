--- protocol/hp_ipp.c.orig	2023-09-13 04:07:44 UTC
+++ protocol/hp_ipp.c
@@ -108,9 +108,6 @@ int addCupsPrinter(char *name, char *device_uri, char 
         goto abort;
     }
 
-     if ( info == NULL )
-        snprintf( info,sizeof(info), name );
-
     sprintf(printer_uri, "ipp://localhost/printers/%s", name);
 
     cupsSetUser("root");
@@ -514,27 +511,27 @@ int __parsePrinterAttributes(ipp_t *response, printer_
 
              if ( strcmp(attr_name, "printer-name") == 0 &&
                                         val_tag == IPP_TAG_NAME ) {
-                  snprintf(t_printer->name, sizeof(t_printer->name),ippGetString(attr, 0, NULL) );
+                  snprintf(t_printer->name, sizeof(t_printer->name), "%s", ippGetString(attr, 0, NULL) );
              }
              else if ( strcmp(attr_name, "device-uri") == 0 &&
                                          val_tag == IPP_TAG_URI ) {
-                  snprintf(t_printer->device_uri,sizeof(t_printer->device_uri), ippGetString(attr, 0, NULL) );
+                  snprintf(t_printer->device_uri,sizeof(t_printer->device_uri), "%s", ippGetString(attr, 0, NULL) );
              }
              else if ( strcmp(attr_name, "printer-uri-supported") == 0 &&
                                                  val_tag == IPP_TAG_URI ) {
-                  snprintf(t_printer->printer_uri,sizeof(t_printer->printer_uri), ippGetString(attr, 0, NULL) );
+                  snprintf(t_printer->printer_uri,sizeof(t_printer->printer_uri), "%s", ippGetString(attr, 0, NULL) );
              }
              else if ( strcmp(attr_name, "printer-info") == 0 &&
                                         val_tag == IPP_TAG_TEXT ) {
-                  snprintf(t_printer->info,sizeof(t_printer->info), ippGetString(attr, 0, NULL) );
+                  snprintf(t_printer->info,sizeof(t_printer->info), "%s", ippGetString(attr, 0, NULL) );
              }
              else if ( strcmp(attr_name, "printer-location") == 0 &&
                                            val_tag == IPP_TAG_TEXT ) {
-                  snprintf(t_printer->location,sizeof(t_printer->location),ippGetString(attr, 0, NULL) );
+                  snprintf(t_printer->location,sizeof(t_printer->location), "%s", ippGetString(attr, 0, NULL) );
              }
              else if ( strcmp(attr_name, "printer-make-and-model") == 0 &&
                                                   val_tag == IPP_TAG_TEXT ) {
-                  snprintf(t_printer->make_model,sizeof(t_printer->make_model),ippGetString(attr, 0, NULL) );
+                  snprintf(t_printer->make_model,sizeof(t_printer->make_model), "%s", ippGetString(attr, 0, NULL) );
              } 
              else if ( strcmp(attr_name, "printer-state") == 0 &&
                                              val_tag == IPP_TAG_ENUM ) {
