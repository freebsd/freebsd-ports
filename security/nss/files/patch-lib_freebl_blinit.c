qemu:handle_cpu_signal received signal outside vCPU context

https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=240037

--- lib/freebl/blinit.c.orig	2020-01-03 20:27:43 UTC
+++ lib/freebl/blinit.c
@@ -174,12 +174,14 @@ CheckARMSupport()
 #ifndef ID_AA64ISAR0_SHA2_VAL
 #define ID_AA64ISAR0_SHA2_VAL ID_AA64ISAR0_SHA2
 #endif
-    uint64_t id_aa64isar0;
-    id_aa64isar0 = READ_SPECIALREG(id_aa64isar0_el1);
-    arm_aes_support_ = ID_AA64ISAR0_AES_VAL(id_aa64isar0) >= ID_AA64ISAR0_AES_BASE && disable_hw_aes == NULL;
-    arm_pmull_support_ = ID_AA64ISAR0_AES_VAL(id_aa64isar0) == ID_AA64ISAR0_AES_PMULL && disable_pmull == NULL;
-    arm_sha1_support_ = ID_AA64ISAR0_SHA1_VAL(id_aa64isar0) == ID_AA64ISAR0_SHA1_BASE;
-    arm_sha2_support_ = ID_AA64ISAR0_SHA2_VAL(id_aa64isar0) >= ID_AA64ISAR0_SHA2_BASE;
+    if (!PR_GetEnvSecure("QEMU_EMULATING")) {
+        uint64_t id_aa64isar0;
+        id_aa64isar0 = READ_SPECIALREG(id_aa64isar0_el1);
+        arm_aes_support_ = ID_AA64ISAR0_AES_VAL(id_aa64isar0) >= ID_AA64ISAR0_AES_BASE && disable_hw_aes == NULL;
+        arm_pmull_support_ = ID_AA64ISAR0_AES_VAL(id_aa64isar0) == ID_AA64ISAR0_AES_PMULL && disable_pmull == NULL;
+        arm_sha1_support_ = ID_AA64ISAR0_SHA1_VAL(id_aa64isar0) == ID_AA64ISAR0_SHA1_BASE;
+        arm_sha2_support_ = ID_AA64ISAR0_SHA2_VAL(id_aa64isar0) >= ID_AA64ISAR0_SHA2_BASE;
+    }
 #endif
     /* aarch64 must support NEON. */
     arm_neon_support_ = disable_arm_neon == NULL;
