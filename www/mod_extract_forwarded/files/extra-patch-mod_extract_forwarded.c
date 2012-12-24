--- mod_extract_forwarded.c.orig	2010-05-24 13:43:06.446992453 +0900
+++ mod_extract_forwarded.c	2010-06-12 17:46:16.673689346 +0900
@@ -423,7 +423,7 @@
     {
         result = &(conn->remote_addr->sa.sin.sin_addr.s_addr);
     }
-#if defined(AF_INET6) && defined(IN6_IS_ADDR_V4MAPPED)
+#if defined(AF_INET6) && defined(IN6_IS_ADDR_V4MAPPED) && APR_HAVE_IPV6 == 1
     if (conn->remote_addr->family == AF_INET6 &&
         IN6_IS_ADDR_V4MAPPED(&conn->remote_addr->sa.sin6.sin6_addr)) 
     {
