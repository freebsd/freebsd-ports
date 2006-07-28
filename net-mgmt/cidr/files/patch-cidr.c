--- cidr.c.orig	Fri Jul 28 14:36:39 2006
+++ cidr.c	Fri Jul 28 14:39:28 2006
@@ -140,14 +140,14 @@
     }
    }
   
-   strncpy(ip[2],argv[1],18);
+   strlcpy(ip[2],argv[1],19);
 
    holdaddress=strtok(ip[2],sep);
    if(holdaddress==NULL)
     invalid(1);
 
 
-   strncpy(ip[0],holdaddress,strlen(holdaddress));
+   strlcpy(ip[0],holdaddress,strlen(holdaddress)+1);
    if(ip[0]==NULL)
     invalid(1);
 
@@ -156,7 +156,7 @@
     invalid(1);  
 
 
-   strncpy(ip[1],holdprefix,strlen(holdprefix));
+   strlcpy(ip[1],holdprefix,strlen(holdprefix)+1);
    if(ip[1]==NULL)
     invalid(1); 
 
