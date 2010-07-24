--- src/dvdunauthor.c.orig	2010-07-24 18:22:12.113194336 +0200
+++ src/dvdunauthor.c	2010-07-24 18:19:15.409638405 +0200
@@ -1033,6 +1033,7 @@
     const cell_adr_t *cells;
     int numcells,i,j,totalsect,numsect;
     clock_t start,now,clkpsec;
+    struct tms tp;
 
     cptr = titlef ? ifo->vts_c_adt : ifo->menu_c_adt;
     if (cptr)
@@ -1054,7 +1055,7 @@
     for (i = 0; i < numcells; i++)
         totalsect += cells[i].last_sector - cells[i].start_sector + 1;
     clkpsec = sysconf(_SC_CLK_TCK);
-    start = times(NULL);
+    start = times(&tp);
     
     for (i = 0; i < numcells; i++)
       {
@@ -1106,7 +1107,7 @@
             int rl = cells[i].last_sector + 1 - b;
             if (rl > BIGBLOCKSECT)
                 rl = BIGBLOCKSECT;
-            now = times(NULL);
+            now = times(&tp);
             if (now-start > 3 * clkpsec && numsect > 0)
               {
                 const int rmn = (totalsect - numsect) * (now - start) / (numsect * clkpsec);
