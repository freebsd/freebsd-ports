--- tcpview.c.orig	1993-04-22 20:40:33 UTC
+++ tcpview.c
@@ -33,7 +33,7 @@
 
 #include <stdio.h>
 #include <sys/types.h>
-#include <sys/limits.h>
+#include <limits.h>
 #include  <X11/Xlib.h>
 #include  <X11/Intrinsic.h>
 #include  <X11/StringDefs.h>
@@ -155,13 +155,13 @@ static XtResource resources[] = {
 
 static XtResource resources[] = {
   { "hostnames", "Hostnames", XtRString, sizeof(String), 
-      XtOffset(params_ptr, hostnames), XtRString, "/usr/local/tcpview/hosts" },
+      XtOffset(params_ptr, hostnames), XtRString, "/usr/local/lib/tcpview/hosts" },
   { "manuf", "Manuf", XtRString, sizeof(String), 
-      XtOffset(params_ptr, manuf), XtRString, "/usr/local/tcpview/manuf" },
+      XtOffset(params_ptr, manuf), XtRString, "/usr/local/lib/tcpview/manuf" },
   { "services", "Services", XtRString, sizeof(String), 
       XtOffset(params_ptr, services), XtRString, "/etc/services" },
   { "filters", "Filters", XtRString, sizeof(String), 
-      XtOffset(params_ptr, filters), XtRString, "/usr/local/tcpview/filters" },
+      XtOffset(params_ptr, filters), XtRString, "/usr/local/lib/tcpview/filters" },
   { "viewer", "Viewer", XtRString, sizeof(String), 
       XtOffset(params_ptr, viewer), XtRString, "*" },
   { "printcommand", "Printcommand", XtRString, sizeof(String), 
