--- src/genarch.c.orig	Wed Sep 20 04:00:23 2000
+++ src/genarch.c	Wed Jun 20 04:05:36 2001
@@ -40,6 +40,7 @@
     fprintf(f, "\n\t /* ---------------- %s ---------------- */\n\n", str);
 }
 
+#ifndef __FreeBSD__
 private clock_t
 time_clear(char *buf, int bsize, int nreps)
 {
@@ -50,6 +51,7 @@
 	memset(buf, 0, bsize);
     return clock() - t;
 }
+#endif /* __FreeBSD__ */
 
 private void
 define(FILE *f, const char *str)
@@ -180,6 +182,7 @@
     fprintf(f, "((unsigned long)~0L + (unsigned long)0)\n");
 #undef PRINT_MAX
 
+#ifndef __FreeBSD__
     section(f, "Cache sizes");
 
     /*
@@ -240,6 +243,7 @@
 	}
 	define_int(f, "ARCH_CACHE2_SIZE", bsize >> 1);
     }
+#endif /* __FreeBSD__ */
 
     section(f, "Miscellaneous");
 
