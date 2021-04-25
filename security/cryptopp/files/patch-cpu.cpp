--- cpu.cpp.orig	2021-03-08 03:42:24 UTC
+++ cpu.cpp
@@ -1172,6 +1172,11 @@ inline bool CPU_QueryAltivec()
 	unsigned int unused, arch;
 	GetAppleMachineInfo(unused, unused, arch);
 	return arch == AppleMachineInfo::PowerMac;
+#elif defined(__FreeBSD__) && defined(PPC_FEATURE_HAS_ALTIVEC)
+	unsigned long cpufeatures;
+	if (elf_aux_info(AT_HWCAP, &cpufeatures, sizeof(cpufeatures))
+		return false;
+	else return cpufeatures & PPC_FEATURE_HAS_ALTIVEC;
 #endif
 	return false;
 }
@@ -1185,6 +1190,12 @@ inline bool CPU_QueryPower7()
 #elif defined(_AIX)
 	if (__power_7_andup() != 0)
 		return true;
+
+#elif defined(__FreeBSD__) && defined(PPC_FEATURE_ARCH_2_06)
+	unsigned long cpufeatures;
+	if (elf_aux_info(AT_HWCAP, &cpufeatures, sizeof(cpufeatures))
+		return false;
+	else return cpufeatures & PPC_FEATURE_ARCH_2_06;
 #endif
 	return false;
 }
@@ -1198,6 +1209,11 @@ inline bool CPU_QueryPower8()
 #elif defined(_AIX)
 	if (__power_8_andup() != 0)
 		return true;
+#elif defined(__FreeBSD__) && defined(PPC_FEATURE2_ARCH_2_07)
+	unsigned long cpufeatures;
+	if (elf_aux_info(AT_HWCAP, &cpufeatures, sizeof(cpufeatures))
+		return false;
+	else return cpufeatures & PPC_FEATURE2_ARCH_2_07;
 #endif
 	return false;
 }
@@ -1211,6 +1227,11 @@ inline bool CPU_QueryPower9()
 #elif defined(_AIX)
 	if (__power_9_andup() != 0)
 		return true;
+#elif defined(__FreeBSD__) && defined(PPC_FEATURE2_ARCH_3_00)
+	unsigned long cpufeatures;
+	if (elf_aux_info(AT_HWCAP2, &cpufeatures, sizeof(cpufeatures))
+		return false;
+	else return cpufeatures & PPC_FEATURE_ARCH2_3_00;
 #endif
 	return false;
 }
@@ -1225,6 +1246,11 @@ inline bool CPU_QueryAES()
 #elif defined(_AIX)
 	if (__power_8_andup() != 0)
 		return true;
+#elif defined(__FreeBSD__) && defined(PPC_FEATURE2_HAS_VEC_CRYPTO)
+	unsigned long cpufeatures;
+	if (elf_aux_info(AT_HWCAP2, &cpufeatures, sizeof(cpufeatures))
+		return false;
+	else return cpufeatures & PPC_FEATURE2_HAS_VEC_CRYPTO;
 #endif
 	return false;
 }
@@ -1239,6 +1265,11 @@ inline bool CPU_QueryPMULL()
 #elif defined(_AIX)
 	if (__power_8_andup() != 0)
 		return true;
+#elif defined(__FreeBSD__) && defined(PPC_FEATURE2_HAS_VEC_CRYPTO)
+	unsigned long cpufeatures;
+	if (elf_aux_info(AT_HWCAP2, &cpufeatures, sizeof(cpufeatures))
+		return false;
+	else return cpufeatures & PPC_FEATURE2_HAS_VEC_CRYPTO;
 #endif
 	return false;
 }
@@ -1253,6 +1284,11 @@ inline bool CPU_QuerySHA256()
 #elif defined(_AIX)
 	if (__power_8_andup() != 0)
 		return true;
+#elif defined(__FreeBSD__) && defined(PPC_FEATURE2_HAS_VEC_CRYPTO)
+	unsigned long cpufeatures;
+	if (elf_aux_info(AT_HWCAP2, &cpufeatures, sizeof(cpufeatures))
+		return false;
+	else return cpufeatures & PPC_FEATURE2_HAS_VEC_CRYPTO;
 #endif
 	return false;
 }
@@ -1266,6 +1302,11 @@ inline bool CPU_QuerySHA512()
 #elif defined(_AIX)
 	if (__power_8_andup() != 0)
 		return true;
+#elif defined(__FreeBSD__) && defined(PPC_FEATURE2_HAS_VEC_CRYPTO)
+	unsigned long cpufeatures;
+	if (elf_aux_info(AT_HWCAP2, &cpufeatures, sizeof(cpufeatures))
+		return false;
+	else return cpufeatures & PPC_FEATURE2_HAS_VEC_CRYPTO;
 #endif
 	return false;
 }
@@ -1280,6 +1321,11 @@ inline bool CPU_QueryDARN()
 #elif defined(_AIX)
 	if (__power_9_andup() != 0)
 		return true;
+#elif defined(__FreeBSD__) && defined(PPC_FEATURE2_ARCH_3_00)
+	unsigned long cpufeatures;
+	if (elf_aux_info(AT_HWCAP2, &cpufeatures, sizeof(cpufeatures))
+		return false;
+	else return cpufeatures & PPC_FEATURE2_ARCH_3_00;
 #endif
 	return false;
 }
