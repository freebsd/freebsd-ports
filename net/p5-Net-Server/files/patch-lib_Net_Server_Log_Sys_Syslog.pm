--- lib/Net/Server/Log/Sys/Syslog.pm.orig	2014-05-05 18:43:15 UTC
+++ lib/Net/Server/Log/Sys/Syslog.pm
@@ -39,12 +39,12 @@ sub initialize {
         # do nothing - assume they have what they want
     } else {
         if (! defined $prop->{'syslog_logsock'}) {
-            $prop->{'syslog_logsock'} = ($Sys::Syslog::VERSION < 0.15) ? 'unix' : '';
+            $prop->{'syslog_logsock'} = ($Sys::Syslog::VERSION lt '0.15') ? 'unix' : '';
         }
         if ($prop->{'syslog_logsock'} =~ /^(|native|tcp|udp|unix|inet|stream|console)$/) {
             $prop->{'syslog_logsock'} = $1;
         } else {
-            $prop->{'syslog_logsock'} = ($Sys::Syslog::VERSION < 0.15) ? 'unix' : '';
+            $prop->{'syslog_logsock'} = ($Sys::Syslog::VERSION lt '0.15') ? 'unix' : '';
         }
     }
 
