--- ../../src/webrtc/src/third_party/opus/src/celt/arm/armcpu.c.orig	2023-10-25 18:00:46 UTC
+++ ../../src/webrtc/src/third_party/opus/src/celt/arm/armcpu.c
@@ -148,6 +148,37 @@
   }
   return flags;
 }
+#elif defined(__FreeBSD__)
+#include <sys/auxv.h>
+
+opus_uint32 opus_cpu_capabilities(void)
+{
+	long hwcap = 0;
+	opus_uint32 flags = 0;
+
+	elf_aux_info(AT_HWCAP, &hwcap, sizeof hwcap);
+
+# if defined(OPUS_ARM_MAY_HAVE_EDSP) || defined(OPUS_ARM_MAY_HAVE_MEDIA) \
+ || defined(OPUS_ARM_MAY_HAVE_NEON) || defined(OPUS_ARM_MAY_HAVE_NEON_INTR)
+	if (hwcap & HWCAP_EDSP)
+		flags |= OPUS_CPU_ARM_EDSP_FLAG;
+
+#  if defined(OPUS_ARM_MAY_HAVE_NEON) || defined(OPUS_ARM_MAY_HAVE_NEON_INTR)
+	if (hwcap & HWCAP_NEON)
+		flags |= OPUS_CPU_ARM_NEON_FLAG;
+#  endif
+# endif
+
+# if defined(OPUS_ARM_MAY_HAVE_MEDIA) \
+ || defined(OPUS_ARM_MAY_HAVE_NEON) || defined(OPUS_ARM_MAY_HAVE_NEON_INTR)
+
+#  if __ARM_ARCH >= 6
+	flags |= OPUS_CPU_ARM_MEDIA_FLAG;
+#  endif
+# endif
+
+	return (flags);
+}
 #else
 /* The feature registers which can tell us what the processor supports are
  * accessible in priveleged modes only, so we can't have a general user-space
