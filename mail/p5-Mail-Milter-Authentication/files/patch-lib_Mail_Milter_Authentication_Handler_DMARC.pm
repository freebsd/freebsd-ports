--- lib/Mail/Milter/Authentication/Handler/DMARC.pm.orig	2024-10-11 04:07:26 UTC
+++ lib/Mail/Milter/Authentication/Handler/DMARC.pm
@@ -27,7 +27,7 @@ sub default_config {
         'report_suppression_email_list' => 'rbl.example.com',
         'no_report'      => 0,
         'hide_report_to' => 0,
-        'config_file'    => '/etc/mail-dmarc.ini',
+        'config_file'    => '%%ETCDIR%%/mail-dmarc.ini',
         'no_reject_disposition' => 'quarantine',
         'no_list_reject_disposition' => 'none',
         'reject_on_multifrom' => 30,
