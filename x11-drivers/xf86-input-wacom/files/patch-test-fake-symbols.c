--- test/fake-symbols.c~
+++ test/fake-symbols.c
@@ -92,7 +92,11 @@ xf86NameCmp(const char *s1, const char *
 }
 
 _X_EXPORT char *
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) > 18
 xf86CheckStrOption(OPTTYPE optlist, const char *name, CONST char *deflt)
+#else
+xf86CheckStrOption(OPTTYPE optlist, const char *name, char *deflt)
+#endif
 {
     return NULL;
 }
@@ -231,7 +235,7 @@ InitValuatorAxisStruct(DeviceIntPtr dev,
 {
     return TRUE;
 }
-#else
+#elif GET_ABI_MAJOR(ABI_XINPUT_VERSION) > 12
 _X_EXPORT void
 InitValuatorAxisStruct(DeviceIntPtr dev, int axnum, Atom label,
                        int minval, int maxval, int resolution,
@@ -239,6 +243,14 @@ InitValuatorAxisStruct(DeviceIntPtr dev,
 {
     return;
 }
+#else
+_X_EXPORT void
+InitValuatorAxisStruct(DeviceIntPtr dev, int axnum, Atom label,
+                       int minval, int maxval, int resolution,
+                       int min_res, int max_res)
+{
+    return;
+}
 #endif
 
 _X_EXPORT void
@@ -279,7 +291,7 @@ InitPtrFeedbackClassDeviceStruct(DeviceI
 _X_EXPORT int
 XIChangeDeviceProperty (DeviceIntPtr dev, Atom property, Atom type,
                         int format, int mode, unsigned long len,
-#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) > 16
+#if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 16
                         const void *
 #elif GET_ABI_MAJOR(ABI_XINPUT_VERSION) > 12
                         const pointer
@@ -506,6 +518,7 @@ xf86UnblockSIGIO (int wasset)
 
 /* This is not the same as the X server one, but it'll do for the tests */
 #if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 14
+#define InputOption InputOption_custom
 typedef struct _InputOption {
     struct _InputOption *next;
     char *key;
@@ -537,6 +550,7 @@ input_option_free_list(InputOption **opt
 		*opts = tmp;
 	}
 }
+#undef InputOption
 #endif
 
 #if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 16
@@ -558,9 +572,9 @@ _X_EXPORT void xf86PostTouchEvent(Device
     uint32_t flags, const ValuatorMask *mask) {
 	return;
 }
+#endif
 
 _X_EXPORT void
 xf86PrintChipsets(const char *drvname, const char *drvmsg, SymTabPtr chips)
 {
 }
-#endif
