--- coda-src/venus/vol_cml.cc.orig	2008-10-06 16:52:54 UTC
+++ coda-src/venus/vol_cml.cc
@@ -3606,7 +3606,8 @@ static int WriteLinks(struct DirEntry *de, void *arg)
 {
     VnodeId vnode;
     Unique_t vunique;
-    char *name = de->name, *comp;
+    char *name = de->name;
+    const char *comp;
     size_t prefixlen;
     char namebuf[CODA_MAXPATHLEN];
     struct WriteLinksHook *hook = (struct WriteLinksHook *)arg;
