--- agent/mibgroup/mibII/icmp.h.orig	2018-07-16 16:33:40.000000000 +0200
+++ agent/mibgroup/mibII/icmp.h	2019-06-15 17:15:20.270320000 +0200
@@ -16,6 +16,7 @@
 config_arch_require(freebsd10, mibII/kernel_sysctl)
 config_arch_require(freebsd11, mibII/kernel_sysctl)
 config_arch_require(freebsd12, mibII/kernel_sysctl)
+config_arch_require(freebsd13, mibII/kernel_sysctl)
 config_arch_require(netbsd,    mibII/kernel_netbsd)
 config_arch_require(netbsdelf, mibII/kernel_netbsd)
 config_arch_require(openbsd4,  mibII/kernel_sysctl)
