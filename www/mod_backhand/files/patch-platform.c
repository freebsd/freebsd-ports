--- platform.c_1.12.c	Tue Nov 28 06:33:52 2006
+++ platform.c	Tue Nov 28 06:25:27 2006
@@ -1,46 +1,46 @@
-	/* ======================================================================
-	 * Copyright (c) 1998-1999 The Johns Hopkins University.
-	 * All rights reserved.
-	 * The following code was written by Theo Schlossnagle for use in the
-	 * Backhand project at The Center for Networking and Distributed Systems
-	 * at The Johns Hopkins University.
-	 * Please refer to the LICENSE file before using this software.
-	 * ======================================================================
-	*/
-	/* This is exported for use in builtins.c */
-	int find_highest_arriba(serverstat *ss) {
-	  int i, highest=0;
-	  for(i=0;i<HARD_SERVER_LIMIT;i++)
-	    highest = MAX(highest,
-			  ss[i].arriba);
-	  return highest;
-	}
-	static int find_max_load(serverstat *ss, int ha) {
-	  int i, highest=0;
-	  float myaa;
-	  for(i=0;i<HARD_SERVER_LIMIT;i++) {
-	    if(ss[i].arriba) myaa = (float)ha/(float)ss[i].arriba;
-	    else myaa = 0;
-	    highest = MAX(highest,
-			  (float)ss[i].load*myaa);
-	  }
-	  return highest;
-	}
-	static int set_high_watermark(void) {
-	  int i=0, aload, ha;
-	  ha = find_highest_arriba(serverstats);
-	  aload = find_max_load(serverstats, ha);
-	  if(aload>0) aload-=1; /* n - delta */
-	  aload /= 1000; /* places hwm @ mag(load)*/
-	  aload <<= 1;
-	  while(aload >>=1) i++; /* log2(1+n-delta) */
-	  aload = 1 << i; /* 2^(n+1) */
-	  for(i=0;i<HARD_SERVER_LIMIT;i++)
-	    aload = MAX(aload, serverstats[i].load_hwm/1000);
-	  return aload;
-	}
+/* ======================================================================
+ * Copyright (c) 1998-1999 The Johns Hopkins University.
+ * All rights reserved.
+ * The following code was written by Theo Schlossnagle for use in the
+ * Backhand project at The Center for Networking and Distributed Systems
+ * at The Johns Hopkins University.
+ * Please refer to the LICENSE file before using this software.
+ * ======================================================================
+*/
+/* This is exported for use in builtins.c */
+int find_highest_arriba(serverstat *ss) {
+  int i, highest=0;
+  for(i=0;i<HARD_SERVER_LIMIT;i++)
+    highest = MAX(highest,
+		  ss[i].arriba);
+  return highest;
+}
+static int find_max_load(serverstat *ss, int ha) {
+  int i, highest=0;
+  float myaa;
+  for(i=0;i<HARD_SERVER_LIMIT;i++) {
+    if(ss[i].arriba) myaa = (float)ha/(float)ss[i].arriba;
+    else myaa = 0;
+    highest = MAX(highest,
+		  (float)ss[i].load*myaa);
+  }
+  return highest;
+}
+static int set_high_watermark(void) {
+  int i=0, aload, ha;
+  ha = find_highest_arriba(serverstats);
+  aload = find_max_load(serverstats, ha);
+  if(aload>0) aload-=1; /* n - delta */
+  aload /= 1000; /* places hwm @ mag(load)*/
+  aload <<= 1;
+  while(aload >>=1) i++; /* log2(1+n-delta) */
+  aload = 1 << i; /* 2^(n+1) */
+  for(i=0;i<HARD_SERVER_LIMIT;i++)
+    aload = MAX(aload, serverstats[i].load_hwm/1000);
+  return aload;
+}
 
-	#ifdef LINUX
+#ifdef LINUX
 #ifndef CPUSTATES
 #define CPUSTATES 4
 #endif
@@ -143,23 +143,42 @@
   ourcpu = (ourcpu==0.0)?0.0:(states[0]/ourcpu); //states[0] == IDLE
   ourcpu *= 1000.0;
   /* Find the memory now */
-  tmem = -1;
-  amem = -1;
+  tmem = 0;
+  amem = 0;
+
   if((proc_stat=fopen(MEMFILE,"r")) == NULL) {
     perror(MEMFILE);
   } else {
+    long long int tm, um, fm, sm, bm, cm;
+    tm=-1; um=-1; fm=-1; sm=-1; bm=-1; cm=-1;
+
     while(fgets(dummy, 100, proc_stat)) {
       if(strncmp(dummy, "Mem:", 4)==0) {
-	int tm, um, fm, sm, bm, cm;
-	sscanf(dummy+5, "%d %d %d %d %d %d", &tm, &um, &fm, &sm, &bm, &cm);
-	tmem=tm/(1024*1024);
-	fm /= (1024*1024);
-	bm /= (1024*1024);
-	cm /= (1024*1024);
-	amem=MAX(fm+bm+cm-5, 0); // Free + Cached + Buffered ???
-	break;
+        sscanf(dummy+5, "%Ld %Ld %Ld %Ld %Ld %Ld", &tm, &um, &fm, &sm, &bm, &cm);
+        tmem=tm/(1024*1024);
+        fm /= (1024*1024);
+        bm /= (1024*1024);
+        cm /= (1024*1024);
+        break;
+      }
+      if(strncmp(dummy, "MemTotal:", 9)==0) {
+        sscanf(dummy+9, "%Ld kB", &tm);
+        tmem = tm/(1024);
+      }
+      if(strncmp(dummy, "Cached:", 7)==0) {
+        sscanf(dummy+7, "%Ld kB", &cm);
+        cm /= (1024);
+      }
+      if(strncmp(dummy, "Buffers:", 8)==0) {
+        sscanf(dummy+8, "%Ld kB", &bm);
+        bm /= (1024);
+      }
+      if(strncmp(dummy, "MemFree:", 8)==0) {
+        sscanf(dummy+8, "%Ld kB", &fm);
+        fm /= (1024);
       }
     }
+    amem=MAX(fm+bm+cm-5, 0); // Free + Cached + Buffered ???
     fclose(proc_stat);
   }
   /* Find the load now */
@@ -267,10 +286,10 @@
       kstat_named_t *kn;
       syspages = k;
       if(kstat_read(kctl, syspages, 0)!=-1 &&
-	 (kn = (kstat_named_t *)kstat_data_lookup(syspages, "physmem"))!=NULL)
+	 (kn = (kstat_named_t *)kstat_data_lookup(syspages, "physmem"))!=NULL) {
 	kn->value.ul /= 1024; /* pgsize in kb, we want mb */
 	physmem = pgsize*kn->value.ul;
-      else
+    } else
         physmem = 0;
     } else if(!strncmp(k->ks_name, "system_misc", 11)) {
       sysmisc = k;
@@ -383,10 +402,10 @@
   ss->tmem = physmem;
   if(syspages &&
      kstat_read(kctl, syspages, 0)!=-1 &&
-     ((kn = (kstat_named_t *)kstat_data_lookup(syspages, "freemem"))!=NULL))
+     ((kn = (kstat_named_t *)kstat_data_lookup(syspages, "freemem"))!=NULL)) {
     kn->value.ul /= 1024; /* pgsize in kb, we want mb */
     ss->amem = pgsize*kn->value.ul;
-  else
+  } else
     ss->amem = 0;
   if(!ss->contact.sin_port)
     if(webport) {
@@ -538,10 +557,12 @@
 void initstat(void) {
   int mib[2];
   size_t len;
+  long long int memsize;
   mib[0] = CTL_HW;
   mib[1] = HW_USERMEM;
-  len = sizeof(int);
-  sysctl(mib, 2, &usermem, &len, NULL, 0);
+  len = sizeof(long long int);
+  sysctl(mib, 2, &memsize, &len, NULL, 0);
+  usermem = (len==4)?(unsigned int) memsize/(1024*1024):(int) (memsize/(1024*1024));
   mib[1] = HW_NCPU;
   sysctl(mib, 2, &ncpu, &len, NULL, 0);
   mib[1] = HW_PAGESIZE;
@@ -577,7 +598,7 @@
   sysctl(mib, 2, &ourload, &len, NULL, 0);
   ss->load = (int)1000.0*((float)ourload.ldavg[0]/(float)ourload.fscale);
   ss->load_hwm=set_high_watermark()*1000;
-  ss->tmem=(int)usermem/(1024*1024); /* in mb */
+  ss->tmem=usermem;
 #ifdef VM_TOTAL
   mib[1] = VM_TOTAL;
 #else
@@ -589,8 +610,7 @@
 #endif
   len = sizeof(struct vmtotal);
   sysctl(mib, 2, &ourmem, &len, NULL, 0);
-  ourmem.t_free /= 1024*1024; /* calculate in mb */
-  ss->amem=(int)usermem-(ourpagesize*ourmem.t_free);
+  ss->amem=(int)(ourpagesize*((unsigned long long int)ourmem.t_free)/(1024*1024));
   ss->cpu =(int)ourcpu;
   ss->ncpu=(int)ncpu;
   /* Fill out hostname */
