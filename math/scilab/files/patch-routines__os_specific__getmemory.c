--- routines/os_specific/getmemory.c	Wed Feb  1 21:50:55 2006
+++ routines/os_specific/getmemory.c	Sat May 27 19:59:53 2006
@@ -69,6 +69,11 @@
    }
 #endif
 
+#if defined(__FreeBSD__)
+#define MEMOK 1
+  return 0;
+#endif
+
 #ifndef  MEMOK
 /* Linux ,Solaris and others assumed*/
       return (sysconf(_SC_AVPHYS_PAGES)*sysconf(_SC_PAGESIZE))/kooctet;
@@ -132,6 +137,11 @@
 	  return 0;
        }
    }
+#endif
+
+#if defined(__FreeBSD__)
+#define MEMOK 1
+  return 0;
 #endif
 
 #ifndef  MEMOK
