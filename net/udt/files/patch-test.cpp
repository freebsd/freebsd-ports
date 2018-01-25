--- app/test.cpp	2013-02-23 03:32:36
+++ app/test.cpp	2018-01-21 02:11:47
@@ -88,5 +88,5 @@
 
    ssock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
-   if (bind(ssock, res->ai_addr, res->ai_addrlen) != 0)
+   if (::bind(ssock, res->ai_addr, res->ai_addrlen) != 0)
    {
       return -1;
