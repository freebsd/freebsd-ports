--- gdb-5.3/include/obstack.h.ORIG	2007-10-17 11:39:24.000000000 -0400
+++ gdb-5.3/include/obstack.h	2007-10-17 11:30:02.000000000 -0400
@@ -349,7 +349,7 @@
 
 #define obstack_memory_used(h) _obstack_memory_used (h)
 
-#if defined __GNUC__ && defined __STDC__ && __STDC__
+#if defined USE_OBSTACK_MACROS && defined __GNUC__ && defined __STDC__ && __STDC__
 /* NextStep 2.0 cc is really gcc 1.93 but it defines __GNUC__ = 2 and
    does not implement __extension__.  But that compiler doesn't define
    __GNUC_MINOR__.  */
