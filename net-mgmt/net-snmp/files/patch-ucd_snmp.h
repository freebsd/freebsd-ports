
$FreeBSD$

--- agent/mibgroup/ucd_snmp.h.orig
+++ agent/mibgroup/ucd_snmp.h
@@ -13,5 +13,10 @@
 config_require(ucd-snmp/logmatch)
 config_require(ucd-snmp/memory)
 config_require(ucd-snmp/vmstat)
+config_arch_require(freebsd4, ucd-snmp/vmstat_freebsd2)
+config_arch_require(freebsd5, ucd-snmp/vmstat_freebsd2)
+config_arch_require(freebsd6, ucd-snmp/vmstat_freebsd2)
+config_arch_require(freebsd7, ucd-snmp/vmstat_freebsd2)
+config_arch_require(freebsd8, ucd-snmp/vmstat_freebsd2)
 config_add_mib(UCD-SNMP-MIB)
 config_add_mib(UCD-DEMO-MIB)
