i915 requires KMS, so FreeBSD uses suffix to distinguish drm1 and drm2 drivers.
drm-kmod kept the same name at the cost of conflict with in-base drm2.

--- src/intel_device.c.orig	2019-02-21 22:26:50 UTC
+++ src/intel_device.c
@@ -204,6 +204,7 @@ static inline struct intel_device *intel_device(ScrnIn
 }
 
 static const char *kernel_module_names[] ={
+	"i915kms",
 	"i915",
 	NULL,
 };
