--- common/client_msgs.c.orig	Tue Oct 28 02:24:02 2003
+++ common/client_msgs.c	Tue Oct 28 02:25:00 2003
@@ -145,22 +145,16 @@
   printf ("%%ok\n");
 }
 
-void print_response(va_alist)
-    va_dcl
+void print_response(int resp_no, char *format, ...)
 {
   va_list list;
   int i;
-  int resp_no;
-  char *format;
   FILE *fp;
 
-  va_start(list);
+  va_start(list, format);
 
   fp = get_out_fp();
 
-  resp_no = va_arg(list, int);
-  format = va_arg(list, char *);
-
   for (i = 0; i < N_RESP; i++)
   {
     if (resp[i].resp_no == resp_no)
@@ -179,6 +173,7 @@
   }
 
   vfprintf(fp, format, list);
+  va_end(list);
 
   fprintf(fp, "\n");
 }
