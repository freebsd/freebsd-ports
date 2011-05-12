--- configuration.c.orig	2011-05-12 02:55:52.000000000 +0200
+++ configuration.c	2011-05-12 02:56:03.000000000 +0200
@@ -43,7 +43,7 @@
   char    my_local_host_name[255];
   static const size_t  my_local_host_name_len=255;
   struct  hostent         *hent;
-  int	  i, full;
+  int	  full;
   Num_prefer = 0;
 
   if (File_name && File_name[0] && (NULL != (fp = fopen(File_name,"r"))) )
