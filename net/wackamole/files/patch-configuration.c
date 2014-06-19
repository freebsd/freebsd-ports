--- configuration.c.orig	2014-05-06 16:35:08.783140770 -0700
+++ configuration.c	2014-05-06 16:35:58.734348535 -0700
@@ -43,7 +43,7 @@
   char    my_local_host_name[255];
   static const size_t  my_local_host_name_len=255;
   struct  hostent         *hent;
-  int	  i, full;
+  int	  full;
   Num_prefer = 0;
 
   if (File_name && File_name[0] && (NULL != (fp = fopen(File_name,"r"))) )
