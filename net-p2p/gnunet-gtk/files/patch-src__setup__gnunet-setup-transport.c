--- src/setup/gnunet-setup-transport.c.orig	2014-01-07 10:40:01 UTC
+++ src/setup/gnunet-setup-transport.c
@@ -349,8 +349,7 @@ nipo (void *cls, const char *name, int i
   if ( (sizeof (struct sockaddr_in6) == addrlen) &&
        (0 != memcmp (&in6addr_loopback,
                      &((struct sockaddr_in6 *)addr)->sin6_addr,
-		     sizeof (struct in6_addr))) &&
-       (! IN6_IS_ADDR_LINKLOCAL ((const struct sockaddr_in6*) addr)) )
+		     sizeof (struct in6_addr))))
   {
     *have_v6 = GNUNET_YES;
     GNUNET_log (GNUNET_ERROR_TYPE_INFO,
