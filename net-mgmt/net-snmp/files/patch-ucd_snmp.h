--- agent/mibgroup/ucd_snmp.h.orig	Mon Oct 25 21:36:55 2004
+++ agent/mibgroup/ucd_snmp.h	Mon Oct 25 21:37:20 2004
@@ -39,6 +39,8 @@
 config_arch_require(freebsd4, ucd-snmp/memory_freebsd2)
 config_arch_require(freebsd5, ucd-snmp/vmstat_freebsd2)
 config_arch_require(freebsd5, ucd-snmp/memory_freebsd2)
+config_arch_require(freebsd6, ucd-snmp/vmstat_freebsd2)
+config_arch_require(freebsd6, ucd-snmp/memory_freebsd2)
 config_arch_require(netbsd1, ucd-snmp/vmstat_netbsd1)
 config_arch_require(netbsd1, ucd-snmp/memory_netbsd1)
 config_arch_require(openbsd2, ucd-snmp/vmstat_netbsd1)
