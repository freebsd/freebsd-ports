--- port.c	Sat Jan 29 15:02:08 2005
+++ port.c	Sun Jan 30 11:36:03 2005
@@ -10,6 +10,9 @@
 #include <syslog.h>
 #include <sys/socket.h>
 #include <sys/un.h>
+#ifdef __FreeBSD__
+#include <string.h>
+#endif
 #include "switch.h"
 #include "hash.h"
 #include "port.h"
@@ -316,10 +319,19 @@
 		    port=p->data;
 		    //if(match_sock(p->control, fd, p->data, p->data_len, &data)) break;
 		    if(p->data_len == sizeof(struct sock_data) &&
-				    !(memcmp(&(port->sock), &mine->sock, sizeof(mine->sock)))) break;
+#ifdef __FreeBSD__
+				    port->sock.sun_family == mine->sock.sun_family &&
+				    !(strcmp(port->sock.sun_path, mine->sock.sun_path)))
+#else
+				    !(memcmp(&(port->sock), &mine->sock, sizeof(mine->sock))))
+#endif
+			    break;
 	    }
   }
-  handle_direct_data(p,hub,&packet,len);
+  if (i < g_nfds)
+	handle_direct_data(p,hub,&packet,len);
+  else
+	printlog(LOG_WARNING, "No port associated with descriptor %d", fd);
   return 0;
 }
 
