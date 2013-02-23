diff -Nur src/prelink.c src/prelink.c
--- src/prelink.c	2013-02-19 23:54:34.000000000 +0200
+++ src/prelink.c	2013-02-19 23:50:31.000000000 +0200
@@ -17,7 +17,13 @@
 
 #include <config.h>
 #include <assert.h>
+
+#if HAVE_ENDIAN_H
 #include <endian.h>
+#elif HAVE_SYS_ENDIAN_H
+#include <sys/endian.h>
+#endif
+
 #include <errno.h>
 #include <error.h>
 #include <fcntl.h>
@@ -439,6 +445,7 @@
 	       adjusting the rest of the library.  */
 	    break;
 	  case SHT_DYNAMIC:
+#ifdef SHT_MIPS_REGINFO
 	  case SHT_MIPS_REGINFO:
 	    /* The same applies to these sections on MIPS.  The convention
 	       is to put .dynamic and .reginfo near the beginning of the
@@ -446,6 +453,7 @@
 	       may refer to them.  */
 	    if (dso->ehdr.e_machine == EM_MIPS)
 	      break;
+#endif
 	    /* FALLTHROUGH */
 	  default:
 	    /* The rest of sections are not safe.  */
