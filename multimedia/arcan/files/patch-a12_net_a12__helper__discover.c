src/a12/net/a12_helper_discover.c:211:23: error: variable has incomplete type 'struct sockaddr_in'
                        struct sockaddr_in caddr;
                                           ^
src/a12/net/a12_helper_discover.c:219:15: error: use of undeclared identifier 'INET6_ADDRSTRLEN'
                                char name[INET6_ADDRSTRLEN];
                                          ^
src/a12/net/a12_helper_discover.c:304:41: error: use of undeclared identifier 'IPPROTO_UDP'
        int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
                                               ^
src/a12/net/a12_helper_discover.c:312:14: warning: implicit declaration of function 'htons' is invalid in C99 [-Wimplicit-function-declaration]
                        .s_addr = htons(INADDR_ANY),
                                  ^
src/a12/net/a12_helper_discover.c:312:20: error: use of undeclared identifier 'INADDR_ANY'
                        .s_addr = htons(INADDR_ANY),
                                        ^

--- a12/net/a12_helper_discover.c.orig	2023-12-19 00:13:54 UTC
+++ a12/net/a12_helper_discover.c
@@ -13,6 +13,7 @@
 #include <inttypes.h>
 #include <sys/wait.h>
 #include <sys/types.h>
+#include <netinet/in.h>
 #include <sys/socket.h>
 #include <pthread.h>
 #include <semaphore.h>
