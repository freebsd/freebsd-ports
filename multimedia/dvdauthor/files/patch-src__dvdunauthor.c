--- src/dvdunauthor.c.orig	Thu Jun  1 06:03:24 2006
+++ src/dvdunauthor.c	Sat May  5 20:59:53 2007
@@ -818,6 +818,7 @@
     cell_adr_t *cells;
     int numcells,i,j,totalsect,numsect;
     clock_t start,now,clkpsec;
+    struct tms tp;
 
     cptr=titlef?ifo->vts_c_adt:ifo->menu_c_adt;
     if( cptr ) {
@@ -836,7 +837,7 @@
     for( i=0; i<numcells; i++ )
         totalsect += cells[i].last_sector - cells[i].start_sector + 1;
     clkpsec=sysconf(_SC_CLK_TCK);
-    start=times(NULL);
+    start=times(&tp);
     
     for( i=0; i<numcells; i++ ) {
         int h,b,plen;
@@ -874,7 +875,7 @@
         for( b=cells[i].start_sector; b<=cells[i].last_sector; b+=BIGBLOCKSECT ) {
             int rl=cells[i].last_sector+1-b;
             if( rl > BIGBLOCKSECT ) rl = BIGBLOCKSECT;
-            now=times(NULL);
+            now=times(&tp);
             if( now-start>3*clkpsec && numsect>0 ) {
                 int rmn=(totalsect-numsect)*(now-start)/(numsect*clkpsec);
                 fprintf(stderr,"STAT: [%d] VOB %d, Cell %d (%d%%, %d:%02d remain)\r",i,cells[i].vob_id,cells[i].cell_id,(numsect*100+totalsect/2)/totalsect,rmn/60,rmn%60);
