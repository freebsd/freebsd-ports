--- src/genarch.c.orig	2003-01-17 00:49:02 UTC
+++ src/genarch.c
@@ -40,6 +40,7 @@ section(FILE * f, const char *str)
     fprintf(f, "\n\t /* ---------------- %s ---------------- */\n\n", str);
 }
 
+#ifndef __FreeBSD__
 private clock_t
 time_clear(char *buf, int bsize, int nreps)
 {
@@ -50,6 +51,7 @@ time_clear(char *buf, int bsize, int nre
 	memset(buf, 0, bsize);
     return clock() - t;
 }
+#endif /* __FreeBSD__ */
 
 private void
 define(FILE *f, const char *str)
@@ -180,6 +182,7 @@ main(int argc, char *argv[])
     fprintf(f, "((unsigned long)~0L + (unsigned long)0)\n");
 #undef PRINT_MAX
 
+#ifndef __FreeBSD__
     section(f, "Cache sizes");
 
     /*
@@ -240,6 +243,7 @@ main(int argc, char *argv[])
 	}
 	define_int(f, "ARCH_CACHE2_SIZE", bsize >> 1);
     }
+#endif /* __FreeBSD__ */
 
     section(f, "Miscellaneous");
 
