Index: lib/dlopen.c
diff -u lib/dlopen.c.orig lib/dlopen.c
--- lib/dlopen.c.orig	Fri Apr 19 01:58:42 2002
+++ lib/dlopen.c	Wed Aug 14 18:45:43 2002
@@ -254,7 +254,11 @@
 		return SASL_FAIL;
 	    }
 	}
+#if defined(__FreeBSD__)
+	if(out != in) snprintf(out, PATH_MAX, "%s/%s", prefix, in);
+#else
 	if(out != in) strncpy(out, in, PATH_MAX);
+#endif
 	return SASL_OK;
     }
 
