--- lenses/tests/test_syslog.aug.orig	2018-08-10 20:17:35 UTC
+++ lenses/tests/test_syslog.aug
@@ -351,3 +351,6 @@ daemon.info                             
     (* allow space before comments *)
     test Syslog.lns get "  \t# space comment\n" =
       { "#comment" = "space comment" }
+
+    test Syslog.lns get "include /etc/syslog.d\n" =
+      { "include" = "/etc/syslog.d" }
