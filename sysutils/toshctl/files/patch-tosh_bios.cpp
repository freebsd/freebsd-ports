--- tosh_bios.cpp.orig Fri Aug 22 16:03:37 2003
+++ tosh_bios.cpp      Fri Aug 22 16:03:50 2003
@@ -130,7 +130,7 @@
     bios_time.tm_mday = str2int(&mem[0xFFFF8],2);
     time_t t = mktime(&bios_time);

-    snprintf(buf,32,"%ld",t);
+    snprintf(buf,32,"%d",t);
     s = "20";s += mem[0xFFFFB];s += mem[0xFFFFC];s += '-';
     s += mem[0xFFFF5]; s+= mem[0xFFFF6];s+= '-';
     s += mem[0xFFFF8]; s+= mem[0xFFFF9];
