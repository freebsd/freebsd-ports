
$FreeBSD$

--- agent/mibgroup/ucd_snmp.h.orig
+++ agent/mibgroup/ucd_snmp.h
@@ -39,6 +39,10 @@
 config_arch_require(freebsd4, ucd-snmp/memory_freebsd2)
 config_arch_require(freebsd5, ucd-snmp/vmstat_freebsd2)
 config_arch_require(freebsd5, ucd-snmp/memory_freebsd2)
+config_arch_require(freebsd6, ucd-snmp/vmstat_freebsd2)
+config_arch_require(freebsd6, ucd-snmp/memory_freebsd2)
+config_arch_require(freebsd7, ucd-snmp/vmstat_freebsd2)
+config_arch_require(freebsd7, ucd-snmp/memory_freebsd2)
 config_arch_require(netbsd1, ucd-snmp/vmstat_netbsd1)
 config_arch_require(netbsd1, ucd-snmp/memory_netbsd1)
 config_arch_require(netbsd, ucd-snmp/vmstat_netbsd1)
