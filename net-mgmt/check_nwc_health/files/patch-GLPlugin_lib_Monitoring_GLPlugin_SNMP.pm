--- GLPlugin/lib/Monitoring/GLPlugin/SNMP.pm.orig	2022-08-19 23:52:28 UTC
+++ GLPlugin/lib/Monitoring/GLPlugin/SNMP.pm
@@ -1173,8 +1173,11 @@ sub establish_snmp_session {
     # removing this at all may cause strange epn errors. As if only
     # certain oids were returned as undef, others not.
     # next try: 50
-    $params{'-timeout'} = $self->opts->timeout() >= 60 ?
-        50 : $self->opts->timeout() - 2;
+    ##$params{'-timeout'} = $self->opts->timeout() >= 60 ?
+    ##    50 : $self->opts->timeout() - 2;
+    # LBL: we don't use WLC, and if this is WLC specific, we should limit to just WLC
+    $params{'-timeout'} = 5;
+    $params{'-retries'} = 3;
     my $stderrvar = "";
     *SAVEERR = *STDERR;
     open ERR ,'>',\$stderrvar;
