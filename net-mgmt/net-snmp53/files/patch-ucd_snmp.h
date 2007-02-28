--- agent/mibgroup/ucd_snmp.h.orig	Tue Feb 27 20:44:04 2007
+++ agent/mibgroup/ucd_snmp.h	Tue Feb 27 20:44:20 2007
@@ -41,6 +41,8 @@
 config_arch_require(freebsd5, ucd-snmp/memory_freebsd2)
 config_arch_require(freebsd6, ucd-snmp/vmstat_freebsd2)
 config_arch_require(freebsd6, ucd-snmp/memory_freebsd2)
+config_arch_require(freebsd7, ucd-snmp/vmstat_freebsd2)
+config_arch_require(freebsd7, ucd-snmp/memory_freebsd2)
 config_arch_require(netbsd1, ucd-snmp/vmstat_netbsd1)
 config_arch_require(netbsd1, ucd-snmp/memory_netbsd1)
 config_arch_require(netbsd, ucd-snmp/vmstat_netbsd1)
