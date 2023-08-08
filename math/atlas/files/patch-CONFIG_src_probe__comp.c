--- CONFIG/src/probe_comp.c.orig	2016-07-28 19:43:01 UTC
+++ CONFIG/src/probe_comp.c
@@ -1367,7 +1367,7 @@ char *FindGoodGcc(enum OSTYPE OS, enum MACHTYPE arch, 
  */
    {
       char *stdpaths =
-         "/usr/local /bin /sbin /usr/bin /usr/sbin /opt/bin /opt/sbin";
+         "%%WRKBIN%% /usr/local /bin /sbin /usr/bin /usr/sbin /opt/bin /opt/sbin";
 
       i = 64 + strlen(stdpaths);
       ln = CheckStrLen(ln, &lnlen, i);
