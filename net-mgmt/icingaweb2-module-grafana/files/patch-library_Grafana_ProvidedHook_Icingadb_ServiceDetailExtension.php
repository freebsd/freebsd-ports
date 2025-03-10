--- library/Grafana/ProvidedHook/Icingadb/ServiceDetailExtension.php.orig	2025-02-03 09:18:12 UTC
+++ library/Grafana/ProvidedHook/Icingadb/ServiceDetailExtension.php
@@ -7,6 +7,7 @@ use ipl\Html\ValidHtml;
 use ipl\Html\HtmlString;
 use ipl\Html\ValidHtml;
 
+#[\AllowDynamicProperties]
 class ServiceDetailExtension extends ServiceDetailExtensionHook
 {
     use IcingaDbGrapher;
