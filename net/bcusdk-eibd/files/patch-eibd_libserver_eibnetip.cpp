--- eibd/libserver/eibnetip.cpp.orig	Thu Nov  8 16:31:33 2007
+++ eibd/libserver/eibnetip.cpp	Tue Dec 18 14:36:10 2007
@@ -17,11 +17,9 @@
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
-#include <string.h>
 #include <netdb.h>
 #include <sys/socket.h>
 #include <unistd.h>
-#include <asm/types.h>
 #include "eibnetip.h"
 #include "config.h"
 #ifdef HAVE_LINUX_NETLINK
@@ -34,6 +32,11 @@
 #include <iphlpapi.h>
 #undef Array
 #endif
+#if defined(__FreeBSD__)
+#include <netinet/in.h>
+#include <net/if.h>
+#include <net/route.h>
+#endif
 
 int
 GetHostIP (struct sockaddr_in *sock, const char *Name)
@@ -45,6 +48,7 @@
   h = gethostbyname (Name);
   if (!h)
     return 0;
+  sock->sin_len = sizeof (*sock);
   sock->sin_family = h->h_addrtype;
   sock->sin_addr.s_addr = (*((unsigned long *) h->h_addr_list[0]));
   return 1;
@@ -144,6 +148,54 @@
 }
 #endif
 
+#if defined(__FreeBSD__)
+typedef struct                                                                                            
+{
+  struct rt_msghdr hdr;
+  char data[1000];                                                                                       
+} r_req;
+
+int
+GetSourceAddress (const struct sockaddr_in *dest, struct sockaddr_in *src)                                
+{
+  int s;
+  r_req req; 
+  char *cp = req.data;                                                                                    
+  memset(&req, 0, sizeof(req));                                                                           
+  memset(src, 0, sizeof (*src));                                                                          
+  s = socket(PF_ROUTE, SOCK_RAW, 0);
+  if (s == -1)                                                                                            
+    return 0; 
+  req.hdr.rtm_msglen = sizeof(req) + sizeof(*dest);                                                       
+  req.hdr.rtm_version = RTM_VERSION;                                                                      
+  req.hdr.rtm_flags = RTF_UP;                                                                             
+  req.hdr.rtm_type = RTM_GET;
+  req.hdr.rtm_addrs = RTA_DST | RTA_IFP;                                                                  
+  memcpy(cp, dest, sizeof(*dest));                                                                        
+  if (write (s, (char *)&req, req.hdr.rtm_msglen) < 0)                                                    
+    return 0;
+  if (read(s, (char *)&req, sizeof(req)) < 0)                                                             
+    return 0;
+  close(s);
+  int i;
+  cp = (char *)(&req.hdr + 1);                                                                            
+  for (i = 1; i; i <<= 1)                                                                                 
+    if (i & req.hdr.rtm_addrs)                                                                            
+    { 
+      struct sockaddr *sa = (struct sockaddr *) cp;                                                       
+      if (i == RTA_IFA)                                                                                   
+      {                                                                                                   
+        src->sin_len = sizeof (*src);
+        src->sin_family = AF_INET;                                                                        
+        src->sin_addr.s_addr = ((struct sockaddr_in *)sa)->sin_addr.s_addr;                               
+        return 1;
+      }
+      cp += SA_SIZE(sa);                                                                                  
+    } 
+  return 0;
+}
+#endif
+
 EIBNetIPPacket::EIBNetIPPacket ()
 {
   service = 0;
@@ -208,6 +260,7 @@
     return 1;
   ip = (buf[2] << 24) | (buf[3] << 16) | (buf[4] << 8) | (buf[5]);
   port = (buf[6] << 8) | (buf[7]);
+  a->sin_len = sizeof (*a);
   a->sin_family = AF_INET;
   a->sin_port = htons (port);
   a->sin_addr.s_addr = htonl (ip);
@@ -254,7 +307,7 @@
   if (fd != -1)
     {
       if (multicast)
-	setsockopt (fd, SOL_IP, IP_DROP_MEMBERSHIP, &maddr, sizeof (maddr));
+	setsockopt (fd, IPPROTO_IP, IP_DROP_MEMBERSHIP, &maddr, sizeof (maddr));
       close (fd);
     }
 }
@@ -265,7 +318,7 @@
   if (multicast)
     throw Exception (DEV_OPEN_FAIL);
   maddr = multicastaddr;
-  if (setsockopt (fd, SOL_IP, IP_ADD_MEMBERSHIP, &maddr, sizeof (maddr)) ==
+  if (setsockopt (fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &maddr, sizeof (maddr)) ==
       -1)
     throw Exception (DEV_OPEN_FAIL);
   multicast = 1;
