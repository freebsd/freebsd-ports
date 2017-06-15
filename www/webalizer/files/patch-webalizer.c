--- webalizer.c.orig	2013-08-26 04:52:15 UTC
+++ webalizer.c
@@ -942,7 +942,11 @@ int main(int argc, char *argv[])
                {
                   /* Save query portion in log.rec.srchstr */
                   strncpy(log_rec.srchstr,(char *)cp1,MAXSRCH);
+#ifdef USE_FULL_CGI_REFS
+                  *cp1++;
+#else
                   *cp1++='\0';
+#endif
                   break;
                }
                else cp1++;
@@ -1089,6 +1093,13 @@ int main(int argc, char *argv[])
             {
                freeaddrinfo(ares);
                resolve_dns(&log_rec);
+
+#ifdef USE_IP_AS_HOSTNAME
+               /* restore the host's IP-address if the host's name has not been resolved */
+               if (!strcmp(log_rec.hostname,"\020\002"))
+                       strncpy(log_rec.hostname, host_buf, sizeof(host_buf));
+#endif
+
             }
          }
 #endif
