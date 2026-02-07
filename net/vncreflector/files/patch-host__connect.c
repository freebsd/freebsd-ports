--- host_connect.c.orig	2025-10-10 10:32:37 UTC
+++ host_connect.c
@@ -232,7 +232,7 @@ static void rf_host_ver(void)
   char *buf = (char *)cur_slot->readbuf;
   int major = 3, minor = 3;
   int remote_major, remote_minor;
-  char ver_msg[12];
+  char ver_msg[13];
 
   if ( strncmp(buf, "RFB ", 4) != 0 || !isdigit(buf[4]) ||
        !isdigit(buf[4]) || !isdigit(buf[5]) || !isdigit(buf[6]) ||
@@ -256,7 +256,8 @@ static void rf_host_ver(void)
     log_write(LL_WARN, "Protocol sub-version does not match (ignoring)");
   }
 
-  sprintf(ver_msg, "RFB %03d.%03d\n", abs(major) % 999, abs(minor) % 999);
+  snprintf(ver_msg, sizeof(ver_msg),
+    "RFB %03d.%03d\n", abs(major) % 999, abs(minor) % 999);
   aio_write(NULL, ver_msg, 12);
   aio_setread(rf_host_auth, NULL, 4);
 }
