
$FreeBSD$

--- agent/mibgroup/hardware/cpu.h
+++ agent/mibgroup/hardware/cpu.h
@@ -12,10 +12,10 @@
 #elif defined(irix6)
 config_require(hardware/cpu/cpu_sysinfo)
 
-#elif (defined(netbsd) || defined(netbsd1) || defined(netbsdelf) || defined(netbsdelf2)|| defined(netbsdelf3) || defined(openbsd2)|| defined(openbsd3) || defined(openbsd4))
+#elif (defined(netbsd) || defined(netbsd1) || defined(netbsdelf) || defined(netbsdelf2)|| defined(netbsdelf3) || defined(openbsd2)|| defined(openbsd3) || defined(openbsd4) || defined(freebsd4)  || defined(freebsd5)|| defined(freebsd6))
 config_require(hardware/cpu/cpu_sysctl)
 
-#elif (defined(freebsd2) || defined(freebsd3) || defined(freebsd4)  || defined(freebsd5)|| defined(freebsd6))
+#elif (defined(freebsd2) || defined(freebsd3))
 config_require(hardware/cpu/cpu_nlist)
 
 #elif (defined(aix4) || defined(aix5))
