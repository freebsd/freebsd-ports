--- panel-plugin/libacpi.c.orig	2018-12-31 22:14:28 UTC
+++ panel-plugin/libacpi.c
@@ -100,7 +100,7 @@ oidfmt(int *oid, int len, char *fmt, u_int *kind)
     j = sizeof(buf);
     i = sysctl(qoid, len + 2, buf, &j, 0, 0);
     if (i)
-        err(1, "sysctl fmt %d %d %d", i, j, errno);
+        err(1, "sysctl fmt %d %zu %d", i, j, errno);
 
     if (kind)
         *kind = *(u_int *)buf;
@@ -129,7 +129,7 @@ get_var(int *oid, int nlen)
     j = sizeof(name);
     i = sysctl(qoid, nlen + 2, name, &j, 0, 0);
     if (i || !j)
-        err(1, "sysctl name %d %d %d", i, j, errno);
+        err(1, "sysctl name %d %zu %d", i, j, errno);
 
     sep = "=";
 
@@ -145,7 +145,7 @@ get_var(int *oid, int nlen)
         return (1);
 
     val[len] = '\0';
-    fmt = buf;
+    fmt = (char *)buf;
     oidfmt(oid, nlen, fmt, &kind);
     p = val;
     switch (*fmt) {
@@ -170,7 +170,7 @@ get_var(int *oid, int nlen)
         return (retval);
     default:
         printf("%s%s", name, sep);
-        printf("Format:%s Length:%d Dump:0x", fmt, len);
+        printf("Format:%s Length:%zu Dump:0x", fmt, len);
         while (len-- && (p < val + 16))
             printf("%02x", *p++);
         if (len > 16)
