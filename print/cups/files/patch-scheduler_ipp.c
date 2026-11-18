--- scheduler/ipp.c.orig	2026-10-05 15:26:07 UTC
+++ scheduler/ipp.c
@@ -5800,7 +5800,7 @@ create_local_printer(
         server_name_len;
 
     /* Get host name of device URI */
-    httpSeparateURI(HTTP_URI_CODING_ALL, ptr,
+    httpSeparateURI(HTTP_URI_CODING_ALL, device_uri_ptr,
 		    scheme, sizeof(scheme), userpass, sizeof(userpass), host,
 		    sizeof(host), &port, resource, sizeof(resource));
 
@@ -5832,7 +5832,7 @@ create_local_printer(
     cupsdSetDeviceURI(printer, uri);
   }
   else
-    cupsdSetDeviceURI(printer, ptr);
+    cupsdSetDeviceURI(printer, device_uri_ptr);
 
   if (printer_geo_location)
     cupsdSetString(&printer->geo_location, ippGetString(printer_geo_location, 0, NULL));
