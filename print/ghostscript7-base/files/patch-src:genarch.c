--- src/genarch.c.orig	Tue Jun  5 15:38:57 2001
+++ src/genarch.c	Wed Jun 20 04:17:42 2001
@@ -41,6 +41,7 @@
     fprintf(f, "\n\t /* ---------------- %s ---------------- */\n\n", str);
 }
 
+#ifndef __FreeBSD__
 private clock_t
 time_clear(char *buf, int bsize, int nreps)
 {
@@ -51,6 +52,7 @@
 	memset(buf, 0, bsize);
     return clock() - t;
 }
+#endif /* __FreeBSD__ */
 
 private void
 define(FILE *f, const char *str)
@@ -181,6 +183,7 @@
     fprintf(f, "((unsigned long)~0L + (unsigned long)0)\n");
 #undef PRINT_MAX
 
+#ifndef __FreeBSD__
     section(f, "Cache sizes");
 
     /*
@@ -241,6 +244,7 @@
 	}
 	define_int(f, "ARCH_CACHE2_SIZE", bsize >> 1);
     }
+#endif /* __FreeBSD__ */
 
     section(f, "Miscellaneous");
 
