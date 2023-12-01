commit 57a1b64ff3ade058a5d8ddd60b3d54f5a2c73c33
Author: Brad Davis <brd@FreeBSD.org>
Date:   Tue Nov 7 03:35:47 2023 -0700

    FreeBSD's PF has a new interface so leverage libpfctl to access it so the right interface is used depending on the version

diff --git src/pf.c src/pf.c
index 9681d366..eef9540d 100644
--- src/pf.c
+++ src/pf.c
@@ -35,6 +35,9 @@
 #endif
 
 #include <net/pfvar.h>
+#ifdef __FreeBSD__
+#include <libpfctl.h>
+#endif
 
 #ifndef FCNT_NAMES
 #if FCNT_MAX != 3
@@ -76,6 +79,56 @@ static void pf_submit(char const *type, char const *type_instance, uint64_t val,
   plugin_dispatch_values(&vl);
 } /* void pf_submit */
 
+#ifdef __FreeBSD__
+static int pf_read(void) {
+  struct pfctl_status *state;
+  int fd;
+
+  fd = open(pf_device, O_RDONLY);
+  if (fd < 0) {
+    ERROR("pf plugin: Unable to open %s: %s", pf_device, STRERRNO);
+    return -1;
+  }
+
+  if ((state = pfctl_get_status(fd)) == NULL) {
+    ERROR("pf plugin: ioctl(DIOCGETSTATUS) failed: %s", STRERRNO);
+    close(fd);
+    return -1;
+  }
+
+  close(fd);
+
+  if (!state->running) {
+    pfctl_free_status(state);
+    WARNING("pf plugin: PF is not running.");
+    return -1;
+  }
+
+  for (int i = 0; i < PFRES_MAX; i++) {
+    pf_submit("pf_counters", pf_reasons[i], pfctl_status_counter(state, i),
+              /* is gauge = */ false);
+  }
+  for (int i = 0; i < LCNT_MAX; i++) {
+    pf_submit("pf_limits", pf_lcounters[i], pfctl_status_lcounter(state, i),
+              /* is gauge = */ false);
+  }
+  for (int i = 0; i < FCNT_MAX; i++) {
+    pf_submit("pf_state", pf_fcounters[i], pfctl_status_fcounter(state, i),
+              /* is gauge = */ false);
+  }
+  for (int i = 0; i < SCNT_MAX; i++) {
+    pf_submit("pf_source", pf_scounters[i], pfctl_status_scounter(state, i),
+              /* is gauge = */ false);
+  }
+
+  pf_submit("pf_states", "current", (uint32_t)state->states,
+            /* is gauge = */ true);
+
+  pfctl_free_status(state);
+
+  return 0;
+} /* int pf_read */
+#else
 static int pf_read(void) {
   struct pf_status state;
   int fd;
@@ -119,5 +172,6 @@ static int pf_read(void) {
 
   return 0;
 } /* int pf_read */
+#endif
 
 void module_register(void) { plugin_register_read("pf", pf_read); }
