--- src/transports/appendfile.c.orig	Tue Mar 11 13:20:23 2003
+++ src/transports/appendfile.c	Tue Apr 15 14:46:18 2003
@@ -702,7 +702,9 @@
     if (pcre_exec(regex, NULL, CS name, Ustrlen(name), 0, 0, ovector,6) >= 2)
       {
       int size;
-      Ustrncpy(buffer, name + ovector[2], ovector[3] - ovector[2]);
+      int n = ovector[3] - ovector[2];
+      Ustrncpy(buffer, name + ovector[2], n);
+      buffer[n] = 0;
       size = Uatoi(buffer);
       sum += size;
       DEBUG(D_transport)
