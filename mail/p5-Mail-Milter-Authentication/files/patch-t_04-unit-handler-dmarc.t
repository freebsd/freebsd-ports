--- t/04-unit-handler-dmarc.t.orig	2024-10-11 04:07:26 UTC
+++ t/04-unit-handler-dmarc.t
@@ -102,7 +102,7 @@ subtest 'config' => sub {
             'report_skip_to' => [ 'my_report_from_address@example.com' ],
             'no_report'      => 0,
             'hide_report_to' => 0,
-            'config_file'    => '/etc/mail-dmarc.ini',
+            'config_file'    => '%%ETCDIR%%/mail-dmarc.ini',
             'no_reject_disposition' => 'quarantine',
             'no_list_reject_disposition' => 'none',
             'reject_on_multifrom' => 30,
