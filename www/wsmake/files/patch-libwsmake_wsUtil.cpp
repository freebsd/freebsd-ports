--- libwsmake/wsUtil.cpp.orig	Sat Sep  1 20:09:13 2001
+++ libwsmake/wsUtil.cpp	Thu Sep 15 12:38:48 2005
@@ -709,12 +709,12 @@
   }
 }
 
-void std::__wsmake_print_it(FILE *out, const char *output, const va_list *ap)
+void std::__wsmake_print_it(FILE *out, const char *output, va_list *ap)
 {
   if(__wsmake_quiet) return;
 
   vfprintf(out,output,*ap);
-  va_end((void*&)*ap);
+  va_end(*ap);
 }
 
 #ifdef DEBUG
