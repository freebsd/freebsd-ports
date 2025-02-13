--- application/controllers/IcingadbimgController.php.orig	2025-02-03 09:18:12 UTC
+++ application/controllers/IcingadbimgController.php
@@ -16,6 +16,7 @@ use ipl\Web\Url;
 /**
  * IcingadbimgController loads graphs as images from the grafana-image-renderer.
  */
+#[\AllowDynamicProperties]
 class IcingadbimgController extends IcingadbGrafanaController
 {
     protected $timerange;
