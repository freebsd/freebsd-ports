--- tests/regression/ust/ust-dl/prog.c.orig	2017-01-12 17:19:54 UTC
+++ tests/regression/ust/ust-dl/prog.c
@@ -21,7 +21,11 @@ int main(int argc, char **argv)
 	if (!h0) {
 		goto get_error;
 	}
+#if defined(__FreeBSD__)
+	h1 = dlopen("libfoo.so", RTLD_LAZY);
+#else
 	h1 = dlmopen(LM_ID_BASE, "libfoo.so", RTLD_LAZY);
+#endif
 	if (!h1) {
 		goto get_error;
 	}
