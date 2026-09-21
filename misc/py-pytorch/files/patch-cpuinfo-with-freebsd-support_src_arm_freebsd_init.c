-- New minimal FreeBSD/aarch64 backend for cpuinfo.
-- cpuinfo upstream only ships a FreeBSD backend for x86 (src/x86/freebsd);
-- aarch64 (this system's architecture) has no FreeBSD implementation, which
-- leaves cpuinfo_initialize() unimplemented and cpuinfo_isa undefined,
-- causing libtorch_cpu.so to fail to load with "Undefined symbol
-- \"cpuinfo_isa\"" on FreeBSD/aarch64. Detects topology via the existing
-- FreeBSD-only cpuinfo_freebsd_detect_topology() helper and ISA features via
-- elf_aux_info(AT_HWCAP/AT_HWCAP2), whose bit layout FreeBSD keeps identical
-- to Linux by design.

-- Upstreamed: https://github.com/pytorch/cpuinfo/pull/436

--- cpuinfo-with-freebsd-support/src/arm/freebsd/init.c.orig	2026-09-21 07:19:45 UTC
+++ cpuinfo-with-freebsd-support/src/arm/freebsd/init.c
@@ -0,0 +1,171 @@
+/*
+ * Minimal AArch64/FreeBSD backend for cpuinfo.
+ *
+ * FreeBSD does not offer /proc/cpuinfo or the sysfs hwcap files that the
+ * Linux backend (src/arm/linux) relies on, so ISA feature bits are queried
+ * through elf_aux_info(AT_HWCAP/AT_HWCAP2), whose bit layout FreeBSD keeps
+ * identical to Linux by design (see sys/arm64/include/elf.h). Per-core
+ * microarchitecture identification (MIDR, vendor/uarch heuristics) and cache
+ * topology detection are not implemented; this only provides enough
+ * information (logical processor/core/package topology and ISA extensions)
+ * for callers such as ATen's cpuinfo-based capability queries.
+ */
+#include <stdbool.h>
+#include <stdint.h>
+#include <stdlib.h>
+#include <string.h>
+
+#include <sys/auxv.h>
+
+#include <cpuinfo.h>
+#include <cpuinfo/internal-api.h>
+#include <cpuinfo/log.h>
+#include <freebsd/api.h>
+
+#ifndef HWCAP_ASIMDHP
+#define HWCAP_ASIMDHP (1 << 10)
+#endif
+#ifndef HWCAP2_I8MM
+#define HWCAP2_I8MM (1 << 13)
+#endif
+#ifndef HWCAP2_BF16
+#define HWCAP2_BF16 (1 << 14)
+#endif
+#ifndef HWCAP2_SME
+#define HWCAP2_SME (1 << 23)
+#endif
+#ifndef HWCAP2_SVE2
+#define HWCAP2_SVE2 (1 << 1)
+#endif
+
+static uint64_t get_hwcap(int type) {
+	unsigned long value = 0;
+	if (elf_aux_info(type, &value, sizeof(value)) != 0) {
+		return 0;
+	}
+	return value;
+}
+
+struct cpuinfo_arm_isa cpuinfo_isa = {0};
+
+void cpuinfo_arm_freebsd_init(void) {
+	struct cpuinfo_processor* processors = NULL;
+	struct cpuinfo_core* cores = NULL;
+	struct cpuinfo_cluster* clusters = NULL;
+	struct cpuinfo_package* packages = NULL;
+	struct cpuinfo_uarch_info* uarchs = NULL;
+
+	struct cpuinfo_freebsd_topology freebsd_topology = cpuinfo_freebsd_detect_topology();
+	if (freebsd_topology.packages == 0) {
+		cpuinfo_log_error("failed to detect topology");
+		return;
+	}
+
+	processors = calloc(freebsd_topology.threads, sizeof(struct cpuinfo_processor));
+	cores = calloc(freebsd_topology.cores, sizeof(struct cpuinfo_core));
+	clusters = calloc(freebsd_topology.packages, sizeof(struct cpuinfo_cluster));
+	packages = calloc(freebsd_topology.packages, sizeof(struct cpuinfo_package));
+	uarchs = calloc(1, sizeof(struct cpuinfo_uarch_info));
+	if (processors == NULL || cores == NULL || clusters == NULL || packages == NULL || uarchs == NULL) {
+		cpuinfo_log_error("failed to allocate topology descriptors");
+		goto cleanup;
+	}
+
+	const uint32_t threads_per_package = freebsd_topology.threads / freebsd_topology.packages;
+	const uint32_t cores_per_package = freebsd_topology.cores / freebsd_topology.packages;
+	const uint32_t threads_per_core = freebsd_topology.threads_per_core;
+
+	uarchs[0] = (struct cpuinfo_uarch_info){
+		.uarch = cpuinfo_uarch_unknown,
+		.processor_count = freebsd_topology.threads,
+		.core_count = freebsd_topology.cores,
+	};
+
+	for (uint32_t i = 0; i < freebsd_topology.packages; i++) {
+		clusters[i] = (struct cpuinfo_cluster){
+			.processor_start = i * threads_per_package,
+			.processor_count = threads_per_package,
+			.core_start = i * cores_per_package,
+			.core_count = cores_per_package,
+			.cluster_id = 0,
+			.package = packages + i,
+		};
+		packages[i].processor_start = i * threads_per_package;
+		packages[i].processor_count = threads_per_package;
+		packages[i].core_start = i * cores_per_package;
+		packages[i].core_count = cores_per_package;
+		packages[i].cluster_start = i;
+		packages[i].cluster_count = 1;
+		strncpy(packages[i].name, "unknown", CPUINFO_PACKAGE_NAME_MAX - 1);
+	}
+	for (uint32_t i = 0; i < freebsd_topology.cores; i++) {
+		cores[i] = (struct cpuinfo_core){
+			.processor_start = i * threads_per_core,
+			.processor_count = threads_per_core,
+			.core_id = i % cores_per_package,
+			.cluster = clusters + i / cores_per_package,
+			.package = packages + i / cores_per_package,
+		};
+	}
+	for (uint32_t i = 0; i < freebsd_topology.threads; i++) {
+		processors[i].smt_id = i % threads_per_core;
+		processors[i].core = cores + i / threads_per_core;
+		processors[i].cluster = clusters + i / threads_per_package;
+		processors[i].package = packages + i / threads_per_package;
+	}
+
+	const uint64_t hwcap = get_hwcap(AT_HWCAP);
+	const uint64_t hwcap2 = get_hwcap(AT_HWCAP2);
+
+	struct cpuinfo_arm_isa isa;
+	memset(&isa, 0, sizeof(isa));
+	isa.aes = !!(hwcap & HWCAP_AES);
+	isa.pmull = !!(hwcap & HWCAP_PMULL);
+	isa.sha1 = !!(hwcap & HWCAP_SHA1);
+	isa.sha2 = !!(hwcap & HWCAP_SHA2);
+	isa.crc32 = !!(hwcap & HWCAP_CRC32);
+	isa.atomics = !!(hwcap & HWCAP_ATOMICS);
+	isa.rdm = !!(hwcap & HWCAP_ASIMDRDM);
+	isa.jscvt = !!(hwcap & HWCAP_JSCVT);
+	isa.fcma = !!(hwcap & HWCAP_FCMA);
+	isa.dot = !!(hwcap & HWCAP_ASIMDDP);
+	isa.fhm = !!(hwcap & HWCAP_ASIMDFHM);
+	isa.sve = !!(hwcap & HWCAP_SVE);
+	isa.fp16arith = !!(hwcap & HWCAP_FPHP) && !!(hwcap & HWCAP_ASIMDHP);
+	isa.i8mm = !!(hwcap2 & HWCAP2_I8MM);
+	isa.bf16 = !!(hwcap2 & HWCAP2_BF16);
+	isa.sve2 = !!(hwcap2 & HWCAP2_SVE2);
+	isa.sme = !!(hwcap2 & HWCAP2_SME);
+
+	/* Commit changes */
+	cpuinfo_isa = isa;
+	cpuinfo_processors = processors;
+	cpuinfo_cores = cores;
+	cpuinfo_clusters = clusters;
+	cpuinfo_packages = packages;
+
+	cpuinfo_processors_count = freebsd_topology.threads;
+	cpuinfo_cores_count = freebsd_topology.cores;
+	cpuinfo_clusters_count = freebsd_topology.packages;
+	cpuinfo_packages_count = freebsd_topology.packages;
+
+	cpuinfo_uarchs = uarchs;
+	cpuinfo_uarchs_count = 1;
+
+	__sync_synchronize();
+
+	cpuinfo_is_initialized = true;
+
+	processors = NULL;
+	cores = NULL;
+	clusters = NULL;
+	packages = NULL;
+	uarchs = NULL;
+
+cleanup:
+	free(processors);
+	free(cores);
+	free(clusters);
+	free(packages);
+	free(uarchs);
+}
