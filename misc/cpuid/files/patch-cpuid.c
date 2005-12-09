--- cpuid.c
+++ cpuid.c
@@ -20,17 +20,34 @@
 void dointel(int),doamd(int),docyrix(int);
 void printregs(int eax,int ebx,int ecx,int edx);
 
-#define MAXBRANDS 9
+#define MAXBRANDS 24
 char *Brands[MAXBRANDS] = {
-  "brand 0",
+  NULL,
   "Celeron processor",
   "Pentium III processor",
   "Intel Pentium III Xeon processor",
-  "brand 4",
-  "brand 5",
-  "brand 6",
-  "brand 7",
+  "Intel Pentium III processor",
+  NULL,
+  "Mobile Intel Pentium III processor-M",
+  "Mobile Intel Celeron processor",
+  /* 8 */
   "Intel Pentium 4 processor",
+  "Intel Pentium 4 processor",
+  "Intel Celeron processor",
+  "Intel Xeon processor",
+  "Intel Xeon processor MP",
+  NULL,
+  "Mobile Intel Pentium 4 processor-M",
+  "Mobile Intel Celeron processor",
+  /* 16 */
+  NULL,
+  "Mobile Genuine Intel processor",
+  "Intel Celeron M processor",
+  "Mobile Intel Celeron processor",
+  "Intel Celeron processor",
+  "Mobile Genuine Intel processor",
+  "Intel Pentium M processor",
+  "Mobile Intel Celeron processor",
 };
 
 #define cpuid(in,a,b,c,d)\
@@ -89,7 +106,7 @@
   exit(0);
 }
 
-char *Intel_feature_flags[] = {
+char *Intel_feature_flags[32] = {
   "FPU    Floating Point Unit",
   "VME    Virtual 8086 Mode Enhancements",
   "DE     Debugging Extensions",
@@ -124,6 +141,49 @@
   "31     reserved",
 };
 
+char *Intel_feature_flags2[32] = {
+  "SSE3    SSE3 extensions",
+  NULL,
+  NULL,
+  "MONITOR MONITOR/MWAIT instructions",
+  "DS-CPL  CPL Qualified Debug Store",
+  NULL,
+  NULL,
+  "EST     Enhanced Intel SpeedStep Technology",
+  "TM2     Thermal Monitor 2",
+  NULL,
+  "CID     Context ID",
+  NULL,
+  NULL,
+  "CX16    CMPXCHG16B",
+  "xTPR    Send Task Priority messages",
+  NULL,
+  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
+  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
+};
+
+char *Intel_ext_feature_flags[32] = {
+  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
+  NULL, NULL, NULL,
+  "SYSCALL   SYSCALL/SYSRET instructions",
+  NULL, NULL, NULL, NULL,
+  NULL, NULL, NULL, NULL,
+  "XD-bit    Execution Disable bit",
+  NULL, NULL, NULL,
+  NULL, NULL, NULL, NULL, NULL,
+  "EM64T     Intel Extended Memory 64 Technology",
+  NULL, NULL
+};
+
+char *Intel_ext_feature_flags2[32] = {
+  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
+  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
+  NULL, NULL, NULL, NULL, 
+  "LAHF      LAHF/SAHF available in IA-32e mode",
+  NULL, NULL, NULL,
+  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
+};
+
 /* Intel-specific information */
 void dointel(int maxi){
   printf("Intel-specific functions:\n");
@@ -131,12 +191,15 @@
   if(maxi >= 1){
     /* Family/model/type etc */
     int clf,apic_id,feature_flags;
+    int feature_flags2 = 0;
+    int ext_feature_flags = 0;
+    int ext_feature_flags2 = 0;
     int extended_model = -1,extended_family = -1;
-    unsigned long eax,ebx,edx,unused;
+    unsigned long eax,ebx,ecx,edx;
     int stepping,model,family,type,reserved,brand,siblings;
     int i;
 
-    cpuid(1,eax,ebx,unused,edx);
+    cpuid(1,eax,ebx,ecx,edx);
     printf("Version %08lx:\n",eax);
     stepping = eax & 0xf;
     model = (eax >> 4) & 0xf;
@@ -147,6 +210,7 @@
     apic_id = (ebx >> 24) & 0xff;
     siblings = (ebx >> 16) & 0xff;
     feature_flags = edx;
+    feature_flags2 = ecx;
 
     printf("Type %d - ",type);
     switch(type){
@@ -253,9 +317,25 @@
       case 8:
 	printf("Pentium III/Pentium III Xeon - internal L2 cache");
 	break;
+      case 9:
+	printf("Intel Pentium M processor model 9");
+	break;
+      case 10:
+	printf("Pentium III Xeon processor model A");
+	break;
+      case 11:
+	printf("Intel Pentium III processor model B");
+	break;
+      case 13:
+	printf("Intel Pentium M processor model D");
+	break;
       }
       break;
     case 15:
+      extended_model = (eax >> 16) & 0xf;
+      if (extended_model == 0) {
+	printf("Intel Pentium 4 processor (generic) or newer");
+      }
       break;
     }
     printf("\n");
@@ -270,16 +350,22 @@
     brand = ebx & 0xff;
     if(brand > 0){
       printf("Brand index: %d [",brand);
-      if(brand  < MAXBRANDS){
+      if(brand  < MAXBRANDS && Brands[brand] != NULL){
 	printf("%s]\n",Brands[brand]);
       } else {
 	printf("not in table]\n");
       }
     }
-    cpuid(0x80000000,eax,ebx,unused,edx);
+    cpuid(0x80000000,eax,ebx,ecx,edx);
     if(eax & 0x80000000){
       /* Extended feature/signature bits supported */
       int maxe = eax;
+      if (maxe >= 0x80000001) {
+	unsigned long eax,ebx,ecx,edx;
+	cpuid(0x80000001,eax,ebx,ecx,edx);	
+	ext_feature_flags = edx;
+	ext_feature_flags2 = ecx;
+      }
       if(maxe >= 0x80000004){
 	int i;
 
@@ -303,12 +389,48 @@
       printf("Hyper threading siblings: %d\n",siblings);
     }
 
-    printf("\nFeature flags %08x:\n",feature_flags);
+    printf("\nFeature flags: %08x:\n",feature_flags);
     for(i=0;i<32;i++){
       if(feature_flags & (1<<i)){
 	printf("%s\n",Intel_feature_flags[i]);
       }
     }
+    if(feature_flags2) {
+      printf("\nFeature flags set 2: %08x:\n",feature_flags2);
+      for (i = 0; i < 32; ++i) {
+        if (feature_flags2 & (1 << i)) {
+          const char* fn = Intel_feature_flags2[i];
+          if (fn != NULL)
+            printf("%s\n", fn);
+          else
+            printf("%d - unknown feature\n", i);
+        }
+      }
+    }
+    if(ext_feature_flags) {
+      printf("\nExtended feature flags: %08x:\n",ext_feature_flags);
+      for (i = 0; i < 32; ++i) {
+        if (ext_feature_flags & (1 << i)) {
+          const char* fn = Intel_ext_feature_flags[i];
+          if (fn != NULL)
+            printf("%s\n", fn);
+          else
+            printf("%d - unknown feature\n", i);
+        }
+      }
+    }
+    if(ext_feature_flags2) {
+      printf("\nExtended feature flags set 2: %08x:\n",ext_feature_flags2);
+      for (i = 0; i < 32; ++i) {
+        if (ext_feature_flags2 & (1 << i)) {
+          const char* fn = Intel_ext_feature_flags2[i];
+          if (fn != NULL)
+            printf("%s\n", fn);
+          else
+            printf("%d - unknown feature\n", i);
+        }
+      }
+    }
     printf("\n");
   }
   if(maxi >= 2){
@@ -408,6 +530,33 @@
   case 0xc:
     printf("1st-level data cache: 16KB, 4-way set assoc, 32 byte line size\n");
     break;
+  case 0x22:
+    printf("3rd-level cache: 512 KB, 4-way set associative, sectored cache, 64-byte line size\n");
+    break;
+  case 0x23:
+    printf("3rd-level cache: 1-MB, 8-way set associative, sectored cache, 64-byte line size\n");
+    break;
+  case 0x25:
+    printf("3rd-level cache: 2-MB, 8-way set associative, sectored cache, 64-byte line size\n");
+    break;
+  case 0x29:
+    printf("3rd-level cache: 4-MB, 8-way set associative, sectored cache, 64-byte line size\n");
+    break;
+  case 0x2c:
+    printf("1st-level data cache: 32-KB, 8-way set associative, 64-byte line size\n");
+    break;
+  case 0x30:
+    printf("1st-level instruction cache: 32-KB, 8-way set associative, 64-byte line size\n");
+    break;
+  case 0x39:
+    printf("2nd-level cache: 128-KB, 4-way set associative, sectored cache, 64-byte line size\n");
+    break;
+  case 0x3b:
+    printf("2nd-level cache: 128-KB, 2-way set associative, sectored cache, 64-byte line size\n");
+    break;
+  case 0x3c:
+    printf("2nd-level cache: 256-KB, 4-way set associative, sectored cache, 64-byte line size\n");
+    break;
   case 0x40:
     printf("No 2nd-level cache, or if 2nd-level cache exists, no 3rd-level cache\n");
     break;
@@ -426,6 +575,12 @@
   case 0x45:
     printf("2nd-level cache: 2MB, 4-way set assoc, 32 byte line size\n");
     break;
+  case 0x46:
+    printf("3rd-level cache: 4MB, 4-way set associative, 64-byte line size\n");
+    break;
+  case 0x47:
+    printf("3rd-level cache: 8MB, 8-way set associative, 64-byte line size\n");
+    break;
   case 0x50:
     printf("Instruction TLB: 4KB and 2MB or 4MB pages, 64 entries\n");
     break;
@@ -436,13 +591,16 @@
     printf("Instruction TLB: 4KB and 2MB or 4MB pages, 256 entries\n");
     break;
   case 0x5b:
-    printf("Data TLB: 4KB and 4MB pages, 64 entries\n");
+    printf("Data TLB: 4KB and 4MB pages, fully assoc., 64 entries\n");
     break;
   case 0x5c:
-    printf("Data TLB: 4KB and 4MB pages, 128 entries\n");
+    printf("Data TLB: 4KB and 4MB pages, fully assoc., 128 entries\n");
     break;
   case 0x5d:
-    printf("Data TLB: 4KB and 4MB pages, 256 entries\n");
+    printf("Data TLB: 4KB and 4MB pages, fully assoc., 256 entries\n");
+    break;
+  case 0x60:
+    printf("1st-level data cache: 16-KB, 8-way set associative, sectored cache, 64-byte line size\n");
     break;
   case 0x66:
     printf("1st-level data cache: 8KB, 4-way set assoc, 64 byte line size\n");
@@ -462,6 +620,9 @@
   case 0x72:
     printf("Trace cache: 32K-micro-op, 4-way set assoc\n");
     break;
+  case 0x78:
+    printf("2nd-level cache: 1MB, 4-way set assoc, 64 byte line size\n");
+    break;
   case 0x79:
     printf("2nd-level cache: 128KB, 8-way set assoc, sectored, 64 byte line size\n");
     break;
@@ -474,6 +635,12 @@
   case 0x7c:
     printf("2nd-level cache: 1MB, 8-way set assoc, sectored, 64 byte line size\n");    
     break;
+  case 0x7d:
+    printf("2nd-level cache: 2-MB, 8-way set associative, 64-byte line size\n");    
+    break;
+  case 0x7f:
+    printf("2nd-level cache: 512KB, 2-way set assoc, 64 byte line size\n");    
+    break;
   case 0x82:
     printf("2nd-level cache: 256KB, 8-way set assoc, 32 byte line size\n");
     break;
@@ -485,6 +652,24 @@
     break;
   case 0x85:
     printf("2nd-level cache: 2MB, 8-way set assoc, 32 byte line size\n");
+    break;
+  case 0x86:
+    printf("2nd-level cache: 512KB, 4-way set assoc, 64 byte line size\n");
+    break;
+  case 0x87:
+    printf("2nd-level cache: 1MB, 8-way set assoc, 64 byte line size\n");
+    break;
+  case 0xB0:
+    printf("Instruction TLB: 4-KB Pages, 4-way set associative, 128 entries\n");
+    break;
+  case 0xB3:
+    printf("Data TLB: 4-KB Pages, 4-way set associative, 128 entries\n");
+    break;
+  case 0xF0:
+    printf("64-byte prefetching\n");
+    break;
+  case 0xF1:
+    printf("128-byte prefetching\n");
     break;
    default:
     printf("unknown TLB/cache descriptor\n");
