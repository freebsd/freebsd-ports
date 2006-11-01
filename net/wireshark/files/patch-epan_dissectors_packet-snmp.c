--- epan/dissectors/packet-snmp.c.orig	Wed Nov  1 14:44:36 2006
+++ epan/dissectors/packet-snmp.c	Wed Nov  1 14:44:49 2006
@@ -3305,7 +3305,7 @@ void proto_register_snmp(void) {
         "snmp.TimeTicks", HFILL }},
     { &hf_snmp_name,
       { "name", "snmp.name",
-        FT_OID, BASE_NONE, NULL, 0,
+        FT_STRING, BASE_NONE, NULL, 0,
         "snmp.ObjectName", HFILL }},
     { &hf_snmp_valueType,
       { "valueType", "snmp.valueType",
