qemu:handle_cpu_signal received signal outside vCPU context

https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=240037

--- lib/freebl/blinit.c.orig	2019-08-30 15:46:32 UTC
+++ lib/freebl/blinit.c
@@ -154,12 +154,14 @@ CheckARMSupport()
         arm_sha2_support_ = hwcaps & HWCAP_SHA2;
     }
 #elif defined(__FreeBSD__)
-    uint64_t id_aa64isar0;
-    id_aa64isar0 = READ_SPECIALREG(ID_AA64ISAR0_EL1);
-    arm_aes_support_ = ID_AA64ISAR0_AES(id_aa64isar0) >= ID_AA64ISAR0_AES_BASE && disable_hw_aes == NULL;
-    arm_pmull_support_ = ID_AA64ISAR0_AES(id_aa64isar0) == ID_AA64ISAR0_AES_PMULL && disable_pmull == NULL;
-    arm_sha1_support_ = ID_AA64ISAR0_SHA1(id_aa64isar0) == ID_AA64ISAR0_SHA1_BASE;
-    arm_sha2_support_ = ID_AA64ISAR0_SHA2(id_aa64isar0) >= ID_AA64ISAR0_SHA2_BASE;
+    if (!PR_GetEnvSecure("QEMU_EMULATING")) {
+        uint64_t id_aa64isar0;
+        id_aa64isar0 = READ_SPECIALREG(ID_AA64ISAR0_EL1);
+        arm_aes_support_ = ID_AA64ISAR0_AES(id_aa64isar0) >= ID_AA64ISAR0_AES_BASE && disable_hw_aes == NULL;
+        arm_pmull_support_ = ID_AA64ISAR0_AES(id_aa64isar0) == ID_AA64ISAR0_AES_PMULL && disable_pmull == NULL;
+        arm_sha1_support_ = ID_AA64ISAR0_SHA1(id_aa64isar0) == ID_AA64ISAR0_SHA1_BASE;
+        arm_sha2_support_ = ID_AA64ISAR0_SHA2(id_aa64isar0) >= ID_AA64ISAR0_SHA2_BASE;
+    }
 #endif /* defined(__linux__) */
     /* aarch64 must support NEON. */
     arm_neon_support_ = disable_arm_neon == NULL;
