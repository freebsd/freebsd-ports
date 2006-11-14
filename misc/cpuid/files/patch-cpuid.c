--- cpuid.c.orig	Tue Nov 14 10:17:30 2006
+++ cpuid.c	Tue Nov 14 11:24:57 2006
@@ -10,6 +10,8 @@
  * http://developer.intel.com/design/Pentium4/manuals/24547103.pdf
  * http://developer.intel.com/design/pentiumiii/applnots/24512501.pdf (AP-909)
  * http://www.amd.com/us-en/assets/content_type/white_papers_and_tech_docs/20734.pdf
+ * http://www.amd.com/us-en/assets/content_type/white_papers_and_tech_docs/24594.pdf
+ * http://www.amd.com/us-en/assets/content_type/white_papers_and_tech_docs/25481.pdf
  * 
  */
 
@@ -20,17 +22,34 @@
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
@@ -89,7 +108,7 @@
   exit(0);
 }
 
-char *Intel_feature_flags[] = {
+char *Intel_feature_flags[32] = {
   "FPU    Floating Point Unit",
   "VME    Virtual 8086 Mode Enhancements",
   "DE     Debugging Extensions",
@@ -124,6 +143,49 @@
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
@@ -131,12 +193,15 @@
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
@@ -147,6 +212,7 @@
     apic_id = (ebx >> 24) & 0xff;
     siblings = (ebx >> 16) & 0xff;
     feature_flags = edx;
+    feature_flags2 = ecx;
 
     printf("Type %d - ",type);
     switch(type){
@@ -253,9 +319,25 @@
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
@@ -270,16 +352,22 @@
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
 
@@ -303,12 +391,48 @@
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
@@ -408,6 +532,33 @@
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
@@ -426,6 +577,12 @@
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
@@ -436,13 +593,16 @@
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
@@ -462,6 +622,9 @@
   case 0x72:
     printf("Trace cache: 32K-micro-op, 4-way set assoc\n");
     break;
+  case 0x78:
+    printf("2nd-level cache: 1MB, 4-way set assoc, 64 byte line size\n");
+    break;
   case 0x79:
     printf("2nd-level cache: 128KB, 8-way set assoc, sectored, 64 byte line size\n");
     break;
@@ -474,6 +637,12 @@
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
@@ -486,44 +655,97 @@
   case 0x85:
     printf("2nd-level cache: 2MB, 8-way set assoc, 32 byte line size\n");
     break;
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
+    break;
    default:
     printf("unknown TLB/cache descriptor\n");
     break;
   }
 }
 char *AMD_feature_flags[] = {
-  "Floating Point Unit",
-  "Virtual Mode Extensions",
-  "Debugging Extensions",
-  "Page Size Extensions",
-  "Time Stamp Counter (with RDTSC and CR4 disable bit)",
-  "Model Specific Registers with RDMSR & WRMSR",
-  "PAE - Page Address Extensions",
-  "Machine Check Exception",
-  "COMPXCHG8B Instruction",
-  "APIC",
-  "10 - Reserved",
-  "SYSCALL/SYSRET or SYSENTER/SYSEXIT instructions",
-  "MTRR - Memory Type Range Registers",
-  "Global paging extension",
-  "Machine Check Architecture",
-  "Conditional Move Instruction",
-  "PAT - Page Attribute Table",
-  "PSE-36 - Page Size Extensions",
-  "18 - reserved",
-  "19 - reserved",
-  "20 - reserved",
-  "21 - reserved",
-  "AMD MMX Instruction Extensions",
-  "MMX instructions",
-  "FXSAVE/FXRSTOR",
-  "25 - reserved",
-  "26 - reserved",
-  "27 - reserved",
-  "28 - reserved",
-  "29 - reserved",
-  "3DNow! Instruction Extensions",
-  "3DNow instructions",
+  "FPU    Floating Point Unit",
+  "VME    Virtual 8086 Mode Enhancements",
+  "DE     Debugging Extensions",
+  "PSE    Page Size Extensions",
+  "TSC    Time Stamp Counter",
+  "MSR    Model Specific Registers",
+  "PAE    Physical Address Extension",
+  "MCE    Machine Check Exception",
+  "CX8    COMPXCHG8B Instruction",
+  "APIC   On-chip Advanced Programmable Interrupt Controller present and enabled",
+  "10     Reserved",
+  "SEP    Fast System Call",
+  "MTRR   Memory Type Range Registers",
+  "PGE    PTE Global Flag",
+  "MCA    Machine Check Architecture",
+  "CMOV   Conditional Move and Compare Instructions",
+  "PAT    Page Attribute Table",
+  "PSE36  36-bit Page Size Extension",
+  "18     Reserved",
+  "CLFSH  CLFLUSH instruction",
+  "20     Reserved",
+  "21     Reserved",
+  "22     Reserved",
+  "MMX    MMX instruction set",
+  "FXSR   Fast FP/MMX Streaming SIMD Extensions save/restore",
+  "SSE    SSE extensions",
+  "SSE2   SSE2 extensions",
+  "27     Reserved",
+  "HTT    Hyper-Threading Technology",
+  "29     Reserved",
+  "30     Reserved",
+  "31     Reserved",
+};
+
+char *AMD_feature_flags2[] = {
+  "FPU    Floating Point Unit",
+  "VME    Virtual 8086 Mode Enhancements",
+  "DE     Debugging Extensions",
+  "PSE    Page Size Extensions",
+  "TSC    Time Stamp Counter",
+  "MSR    Model Specific Registers",
+  "PAE    Physical Address Extension",
+  "MCE    Machine Check Exception",
+  "CX8    COMPXCHG8B Instruction",
+  "APIC   On-chip Advanced Programmable Interrupt Controller present and enabled",
+  "10     Reserved",
+  "SEP    Fast System Call",
+  "MTRR   Memory Type Range Registers",
+  "PGE    PTE Global Flag",
+  "MCA    Machine Check Architecture",
+  "CMOV   Conditional Move and Compare Instructions",
+  "PAT    Page Attribute Table",
+  "PSE36  36-bit Page Size Extension",
+  "18     Reserved",
+  "19     Reserved",
+  "NX     No-execute page protection",
+  "21     Reserved",
+  "MmxExt MMX instruction extensions",
+  "MMX    MMX instructions",
+  "FXSR   Fast FP/MMX Streaming SIMD Extensions save/restore",
+  "FFXSR  FXSAVE and FXRSTOR instruction optimizations",
+  "26     Reserved",
+  "RDTSCP RDTSCP instruction",
+  "28     Reserved",
+  "LM     64 bit long mode",
+  "3DNowE 3DNow! instruction extensions",
+  "3DNow  3DNow! instructions",
 };
 
 char *Assoc[] = {
@@ -657,7 +879,7 @@
 	printf("Global Paging Extensions\n");
       } else {
 	if(edx & (1<<i)){
-	  printf("%s\n",AMD_feature_flags[i]);
+	  printf("%s\n",AMD_feature_flags2[i]);
 	}
       }
     }
