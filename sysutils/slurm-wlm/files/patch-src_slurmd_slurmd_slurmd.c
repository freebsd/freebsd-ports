--- src/slurmd/slurmd/slurmd.c.orig	2024-05-21 17:19:51 UTC
+++ src/slurmd/slurmd/slurmd.c
@@ -2191,10 +2191,17 @@ _slurmd_init(void)
 	build_all_frontend_info(true);
 
 	/*
+	 * cgroups is unsupported on FreeBSD and would prevent slurmd from starting
+	 */
+#if defined(__FreeBSD__)
+	info("FreeBSD: Skipping cgroup_conf_init() - cgroups unsupported");
+#else
+	/*
 	 * This needs to happen before _read_config where we will try to read
 	 * cgroup.conf values
 	 */
 	cgroup_conf_init();
+#endif
 
 	xcpuinfo_refresh_hwloc(original);
 
@@ -2214,6 +2221,10 @@ _slurmd_init(void)
 	 * defaults and command line.
 	 */
 	_read_config();
+
+#if defined(__FreeBSD__)
+	info("FreeBSD: Skipping cgroup_g_init() - cgroups unsupported");
+#else
 	/*
 	 * This needs to happen before _resource_spec_init where we will try to
 	 * attach the slurmd pid to system cgroup, and after _read_config to
@@ -2223,6 +2234,7 @@ _slurmd_init(void)
 		error("Unable to initialize cgroup plugin");
 		return SLURM_ERROR;
 	}
+#endif
 
 #ifndef HAVE_FRONT_END
 	if (!find_node_record(conf->node_name))
@@ -2562,6 +2574,10 @@ static int _resource_spec_init(void)
  */
 static int _resource_spec_init(void)
 {
+#if defined(__FreeBSD__)
+	debug("FreeBSD: Skipping system cpuset and memory cgroup setup");
+	return SLURM_SUCCESS;
+#endif
 	fini_system_cgroup();	/* Prevent memory leak */
 	if (_core_spec_init() != SLURM_SUCCESS)
 		error("Resource spec: core specialization disabled");
