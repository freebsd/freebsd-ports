--- data_link.c.orig	Sat Apr  6 22:45:23 2002
+++ data_link.c	Sat Apr  6 22:48:01 2002
@@ -93,6 +93,7 @@
 	{
         	soc_addr.sin_family    	= AF_INET;
         	soc_addr.sin_port	= htons(port);
+		bzero(&soc_addr.sin_zero, sizeof(soc_addr.sin_zero));
                 if (interface_address == 0)
                         soc_addr.sin_addr.s_addr= INADDR_ANY;
                 else 
