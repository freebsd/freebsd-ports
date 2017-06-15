--- libenv/sysinfo.c.orig	2016-07-28 21:25:33 UTC
+++ libenv/sysinfo.c
@@ -168,15 +168,16 @@ static int MiscOS(EvalContext *ctx);
 static void OpenVZ_Detect(EvalContext *ctx);
 
 
-#ifdef XEN_CPUID_SUPPORT
-static void Xen_Cpuid(uint32_t idx, uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx);
-static int Xen_Hv_Check(void);
-#endif
 
 static bool ReadLine(const char *filename, char *buf, int bufsize);
 static FILE *ReadFirstLine(const char *filename, char *buf, int bufsize);
 #endif
 
+#ifdef XEN_CPUID_SUPPORT
+static void Xen_Cpuid(uint32_t idx, uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx);
+static bool Xen_Hv_Check(void);
+#endif
+
 static void GetCPUInfo(EvalContext *ctx);
 
 static const char *const CLASSATTRIBUTES[][3] =
@@ -1146,14 +1147,6 @@ static void OSClasses(EvalContext *ctx)
         OpenVZ_Detect(ctx);
     }
 
-#ifdef XEN_CPUID_SUPPORT
-    else if (Xen_Hv_Check())
-    {
-        Log(LOG_LEVEL_VERBOSE, "This appears to be a xen hv system.");
-        EvalContextClassPutHard(ctx, "xen", "inventory,attribute_name=Virtual host,source=agent");
-        EvalContextClassPutHard(ctx, "xen_domu_hv", "source=agent");
-    }
-#endif
 
 #else
 
@@ -1195,6 +1188,15 @@ static void OSClasses(EvalContext *ctx)
 
 #endif
 
+#ifdef XEN_CPUID_SUPPORT
+    if (Xen_Hv_Check())
+    {
+        Log(LOG_LEVEL_VERBOSE, "This appears to be a xen hv system.");
+        EvalContextClassPutHard(ctx, "xen", "inventory,attribute_name=Virtual host,source=agent");
+        EvalContextClassPutHard(ctx, "xen_domu_hv", "source=agent");
+    }
+#endif
+
     GetCPUInfo(ctx);
 
 #ifdef __CYGWIN__
@@ -2518,49 +2520,6 @@ static void OpenVZ_Detect(EvalContext *c
 
 /******************************************************************/
 
-#ifdef XEN_CPUID_SUPPORT
-
-/* borrowed from Xen source/tools/libxc/xc_cpuid_x86.c */
-
-static void Xen_Cpuid(uint32_t idx, uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx)
-{
-    asm(
-           /* %ebx register need to be saved before usage and restored thereafter
-            * for PIC-compliant code on i386 */
-# ifdef __i386__
-           "push %%ebx; cpuid; mov %%ebx,%1; pop %%ebx"
-# else
-           "push %%rbx; cpuid; mov %%ebx,%1; pop %%rbx"
-# endif
-  : "=a"(*eax), "=r"(*ebx), "=c"(*ecx), "=d"(*edx):"0"(idx), "2"(0));
-}
-
-/******************************************************************/
-
-static int Xen_Hv_Check(void)
-{
-    uint32_t eax;
-    union
-    {
-        uint32_t u[3];
-        char s[13];
-    } sig = {{0}};
-
-    Xen_Cpuid(0x40000000, &eax, &sig.u[0], &sig.u[1], &sig.u[2]);
-
-    if (strcmp("XenVMMXenVMM", sig.s) || (eax < 0x40000002))
-    {
-        return 0;
-    }
-
-    Xen_Cpuid(0x40000001, &eax, &sig.u[0], &sig.u[1], &sig.u[2]);
-    return 1;
-}
-
-#endif
-
-/******************************************************************/
-
 static bool ReadLine(const char *filename, char *buf, int bufsize)
 {
     FILE *fp = ReadFirstLine(filename, buf, bufsize);
@@ -2597,6 +2556,48 @@ static FILE *ReadFirstLine(const char *f
 }
 #endif /* __linux__ */
 
+/******************************************************************/
+
+#ifdef XEN_CPUID_SUPPORT
+
+/* borrowed from Xen source/tools/libxc/xc_cpuid_x86.c */
+
+static void Xen_Cpuid(uint32_t idx, uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx)
+{
+    asm(
+           /* %ebx register need to be saved before usage and restored thereafter
+            * for PIC-compliant code on i386 */
+# ifdef __i386__
+           "push %%ebx; cpuid; mov %%ebx,%1; pop %%ebx"
+# else
+           "push %%rbx; cpuid; mov %%ebx,%1; pop %%rbx"
+# endif
+  : "=a"(*eax), "=r"(*ebx), "=c"(*ecx), "=d"(*edx):"0"(idx), "2"(0));
+}
+
+/******************************************************************/
+
+static bool Xen_Hv_Check(void)
+{
+    uint32_t eax, base;
+    union
+    {
+        uint32_t u[3];
+        char s[13];
+    } sig = {{0}};
+
+    for (base = 0x40000000; base < 0x40010000; base += 0x100)
+    {
+        Xen_Cpuid(base, &eax, &sig.u[0], &sig.u[1], &sig.u[2]);
+        if (strcmp("XenVMMXenVMM", sig.s) == 0 && eax >= (base + 2))
+            return true;
+    }
+
+    return false;
+}
+#endif /* XEN_CPUID_SUPPORT */
+
+
 static void GetCPUInfo(EvalContext *ctx)
 {
 #if defined(MINGW) || defined(NT)
