--- src/udpsvd.c.orig	2008-06-15 20:31:14 UTC
+++ src/udpsvd.c
@@ -268,7 +268,7 @@ int main(int argc, const char **argv, const char *cons
     if (user) {
       bufnum[fmt_ulong(bufnum, ugid.uid)] =0;
       out(", uid "); out(bufnum);
-      bufnum[fmt_ulong(bufnum, ugid.gid)] =0;
+      bufnum[fmt_ulong(bufnum, ugid.gid[0])] =0;
       out(", gid "); out(bufnum);
     }
     flush(", starting.\n");
