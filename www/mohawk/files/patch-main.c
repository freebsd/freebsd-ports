main.c:387:2: error: misleading indentation; statement is not part of the previous 'if' [-Werror,-Wmisleading-indentation]
        if (network->not)
        ^

--- main.c.orig	2020-03-22 05:37:24 UTC
+++ main.c
@@ -384,9 +384,7 @@ access_granted_inet(struct addrinfo *ai, struct mohawk
     if ((sa->sin_addr.s_addr & network->mask) != network->prefix) 
         return -1;
 
-	if (network->not)
-		return 0; 
-    return 1;
+    return !network->not;
 } 
  
 static inline int 
@@ -400,9 +398,8 @@ access_granted_inet6(struct addrinfo *ai, struct mohaw
         if ((sa6->sin6_addr.s6_addr[i] & network->mask[i]) != network->prefix[i])
             return -1;
     }
-	if (network->not)
-		return 0; 
-    return 1; 
+
+    return !network->not;
 }
 
 
