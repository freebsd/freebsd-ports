--- cpuid.c.orig	2002-01-02 06:14:51.000000000 +0000
+++ cpuid.c
@@ -3,38 +3,62 @@
  * Updated 24 Apr 2001 to latest Intel CPUID spec
  * Updated 22 Dec 2001 to decode Intel flag 28, hyper threading
  * Updated 1 Jan 2002 to cover AMD Duron, Athlon
+ * Updated 24 Aug 2009 to decode additional Intel flags
+ * Updated 23 May 2010 to decode additional Intel flags
  * May be used under the terms of the GNU Public License (GPL)
 
  * Reference documents:
- * ftp://download.intel.com/design/pro/applnots/24161809.pdf  (AP-485)
+ * http://www.intel.com/Assets/PDF/appnote/241618.pdf (AN-485 August 2009)
  * http://developer.intel.com/design/Pentium4/manuals/24547103.pdf
  * http://developer.intel.com/design/pentiumiii/applnots/24512501.pdf (AP-909)
  * http://www.amd.com/us-en/assets/content_type/white_papers_and_tech_docs/20734.pdf
- * 
+ * http://www.amd.com/us-en/assets/content_type/white_papers_and_tech_docs/24594.pdf
+ * http://www.amd.com/us-en/assets/content_type/white_papers_and_tech_docs/25481.pdf
+ *
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 
 void decode_intel_tlb(int);
 void decode_cyrix_tlb(int);
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
   asm("cpuid": "=a" (a), "=b" (b), "=c" (c), "=d" (d) : "a" (in));
+#define cpuidx(in,in2,a,b,c,d)\
+  asm("cpuid": "=a" (a), "=b" (b), "=c" (c), "=d" (d) : "a" (in), "c" (in2));
 
 int main(){
   int i;
@@ -48,8 +72,9 @@ int main(){
   printf(" eax in    eax      ebx      ecx      edx\n");
   for(i=0;i<=maxi;i++){
     unsigned long eax,ebx,ecx,edx;
+    ecx = 0; /* basic query for leaves that dependent on it */
 
-    cpuid(i,eax,ebx,ecx,edx);
+    cpuidx(i,ecx,eax,ebx,ecx,edx);
     printf("%08x %08lx %08lx %08lx %08lx\n",i,eax,ebx,ecx,edx);
   }
   cpuid(0x80000000,maxei,unused,unused,unused);
@@ -89,7 +114,7 @@ int main(){
   exit(0);
 }
 
-char *Intel_feature_flags[] = {
+char *Intel_feature_flags1[32] = {
   "FPU    Floating Point Unit",
   "VME    Virtual 8086 Mode Enhancements",
   "DE     Debugging Extensions",
@@ -108,7 +133,7 @@ char *Intel_feature_flags[] = {
   "CMOV   Conditional Move and Compare Instructions",
   "FGPAT  Page Attribute Table",
   "PSE-36 36-bit Page Size Extension",
-  "PN     Processor Serial Number present and enabled",
+  "PSN    Processor Serial Number present and enabled",
   "CLFSH  CFLUSH instruction",
   "20     reserved",
   "DS     Debug store",
@@ -121,7 +146,76 @@ char *Intel_feature_flags[] = {
   "HT     Hyper Threading",
   "TM     Thermal monitor",
   "30     reserved",
-  "31     reserved",
+  "31     Pending Break Enable"
+};
+
+char *Intel_feature_flags2[32] = {
+  "SSE3     SSE3 extensions",
+  "PCLMULDQ PCLMULDQ instruction",
+  "DTES64   64-bit debug store",
+  "MONITOR  MONITOR/MWAIT instructions",
+  "DS-CPL   CPL Qualified Debug Store",
+  "VMX      Virtual Machine Extensions",
+  "SMX      Safer Mode Extension",
+  "EST      Enhanced Intel SpeedStep Technology",
+  "TM2      Thermal Monitor 2",
+  "SSSE3    Supplemental Streaming SIMD Extension 3",
+  "CNXT-ID  L1 Context ID",
+  NULL,
+  "FMA      Fused Multiply-Add",
+  "CX16     CMPXCHG16B",
+  "xTPR     Send Task Priority messages",
+  "PDCM     Perfmon and debug capability",
+  NULL,
+  "PCID     Process-Context Identifiers",
+  "DCA      Direct Cache Access",
+  "SSE4.1   Streaming SIMD Extension 4.1",
+  "SSE4.2   Streaming SIMD Extension 4.2",
+  "x2APIC   Extended xAPIC support",
+  "MOVBE    MOVBE instruction",
+  "POPCNT   POPCNT instruction",
+  "TSC-Deadline",
+  "AESNI    AES Instruction set",
+  "XSAVE    XSAVE/XSTOR states",
+  "OSXSAVE  OS-enabled extended state managerment",
+  "AVX      AVX extensions",
+  "F16C     Half-precision conversions",
+  "RDRAND   RDRAND Instruction",
+  NULL
+};
+
+char *Intel_ext_feature_flags1[32] = {
+  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
+  NULL, NULL, NULL,
+  "SYSCALL   SYSCALL/SYSRET instructions",
+  NULL, NULL, NULL, NULL,
+  NULL, NULL, NULL, NULL,
+  "XD-bit    Execution Disable bit",
+  NULL, NULL, NULL,
+  NULL, NULL,
+  "1GBP      1 GByte pages are available",
+  "RDTSCP    RDTSCP and IA32_TSC_AUX are available",
+  NULL,
+  "EM64T     Intel Extended Memory 64 Technology",
+  NULL, NULL
+};
+
+char *Intel_ext_feature_flags2[32] = {
+  "LAHF      LAHF/SAHF available in IA-32e mode",
+  NULL, NULL, NULL, NULL, NULL, NULL, NULL,
+  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
+  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
+  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
+};
+
+char *Intel_struct_ext_feature_flags_7_0_b[32] = {
+  "FSGSBASE", "IA32_TSC_ADJUST MSR",
+  NULL, "BMI1", "HLE", "AVX2", NULL, "SMEP",
+  "BMI2", "Enhanced REP MOVSB/STOSB",
+  "INVPCID", "RTM", "Quality of Service Monitoring capability",
+  "Deprecates FPU CS and FPU DS", NULL, NULL,
+  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
+  NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
 };
 
 /* Intel-specific information */
@@ -131,22 +225,31 @@ void dointel(int maxi){
   if(maxi >= 1){
     /* Family/model/type etc */
     int clf,apic_id,feature_flags;
-    int extended_model = -1,extended_family = -1;
-    unsigned long eax,ebx,edx,unused;
-    int stepping,model,family,type,reserved,brand,siblings;
+    int feature_flags2 = 0;
+    int ext_feature_flags = 0;
+    int ext_feature_flags2 = 0;
+    int basic_family, extended_family, basic_model, extended_model;
+    int family, model;
+    unsigned long eax,ebx,ecx,edx;
+    int stepping,type,reserved,brand,siblings;
     int i;
 
-    cpuid(1,eax,ebx,unused,edx);
+    cpuid(1,eax,ebx,ecx,edx);
     printf("Version %08lx:\n",eax);
     stepping = eax & 0xf;
-    model = (eax >> 4) & 0xf;
-    family = (eax >> 8) & 0xf;
+    basic_family = (eax >> 8) & 0xf;
+    extended_family = (eax >> 20) & 0xff;
+    family = basic_family + extended_family;
+    basic_model = (eax >> 4) & 0xf;
+    extended_model = (eax >> 16) & 0xf;
+    model = (extended_model << 4) | basic_model;
     type = (eax >> 12) & 0x3;
-    reserved = eax >> 14;
+    reserved = eax & 0xf000c000l;
     clf = (ebx >> 8) & 0xff;
     apic_id = (ebx >> 24) & 0xff;
     siblings = (ebx >> 16) & 0xff;
     feature_flags = edx;
+    feature_flags2 = ecx;
 
     printf("Type %d - ",type);
     switch(type){
@@ -183,10 +286,6 @@ void dointel(int maxi){
       printf("Pentium 4");
     }
     printf("\n");
-    if(family == 15){
-      extended_family = (eax >> 20) & 0xff;
-      printf("Extended family %d\n",extended_family);
-    }
     printf("Model %d - ",model);
     switch(family){
     case 3:
@@ -253,33 +352,72 @@ void dointel(int maxi){
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
+      case 14:
+	printf("Intel Core family processor, 65nm");
+	break;
+      case 15:
+	printf("Intel Core2 family processor, 65nm");
+	break;
+      case 21:
+	printf("Intel EP80579 integrated processor");
+	break;
+      case 22:
+	printf("Intel Celeron processor model 16h, 65nm");
+	break;
+      case 23:
+	printf("Intel Core2 Extreme or Xeon processor, 45nm");
+	break;
+      case 28:
+	printf("Intel Atom processor, 45nm");
+	break;
+      case 30:
+	printf("Intel Corei7 or Xeon processor, 45nm");
+	break;
+      case 31:
+	printf("Intel Xeon processor MP, 45nm");
+	break;
       }
       break;
     case 15:
+      printf("Intel Pentium 4 processor (generic) or newer");
       break;
     }
     printf("\n");
-    if(model == 15){
-      extended_model = (eax >> 16) & 0xf;
-      printf("Extended model %d\n",extended_model);
-    }
     printf("Stepping %d\n",stepping);
 
-    printf("Reserved %d\n\n",reserved);
+    printf("Reserved %x\n\n",reserved);
 
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
 
@@ -303,10 +441,50 @@ void dointel(int maxi){
       printf("Hyper threading siblings: %d\n",siblings);
     }
 
-    printf("\nFeature flags %08x:\n",feature_flags);
+    printf("\nFeature flags set 1 (CPUID.01H:EDX): %08x:\n",
+      feature_flags);
     for(i=0;i<32;i++){
       if(feature_flags & (1<<i)){
-	printf("%s\n",Intel_feature_flags[i]);
+	printf("%s\n",Intel_feature_flags1[i]);
+      }
+    }
+    if(feature_flags2) {
+      printf("\nFeature flags set 2 (CPUID.01H:ECX): %08x:\n",
+	feature_flags2);
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
+      printf("\nExtended feature flags set 1 (CPUID.80000001H:EDX): %08x\n",
+	ext_feature_flags);
+      for (i = 0; i < 32; ++i) {
+        if (ext_feature_flags & (1 << i)) {
+          const char* fn = Intel_ext_feature_flags1[i];
+          if (fn != NULL)
+            printf("%s\n", fn);
+          else
+            printf("%d - unknown feature\n", i);
+        }
+      }
+    }
+    if(ext_feature_flags2) {
+      printf("\nExtended feature flags set 2 (CPUID.80000001H:ECX): %08x\n",
+	ext_feature_flags2);
+      for (i = 0; i < 32; ++i) {
+        if (ext_feature_flags2 & (1 << i)) {
+          const char* fn = Intel_ext_feature_flags2[i];
+          if (fn != NULL)
+            printf("%s\n", fn);
+          else
+            printf("%d - unknown feature\n", i);
+        }
       }
     }
     printf("\n");
@@ -316,7 +494,7 @@ void dointel(int maxi){
     int ntlb,i;
 
     ntlb = 255;
-    printf("TLB and cache info:\n");
+    printf("Old-styled TLB and cache info:\n");
     for(i=0;i<ntlb;i++){
       unsigned long eax,ebx,ecx,edx;
 
@@ -352,7 +530,7 @@ void dointel(int maxi){
 
     cpuid(1,signature,unused,unused,unused);
     cpuid(3,unused,unused,ecx,edx);
-    printf("Processor serial: ");
+    printf("\nProcessor serial: ");
     printf("%04lX",signature >> 16);
     printf("-%04lX",signature & 0xffff);
     printf("-%04lX",edx >> 16);
@@ -360,6 +538,72 @@ void dointel(int maxi){
     printf("-%04lX",ecx >> 16);
     printf("-%04lX\n",ecx & 0xffff);
   }
+  if (maxi >= 4) {
+    unsigned long index, eax, ebx, ecx, edx, ctype;
+    unsigned long linesize, partitions, ways, sets, t;
+    for (index = 0; ; ++index) {
+      cpuidx(4,index,eax,ebx,ecx,edx);
+      ctype = eax&31;
+      if (ctype == 0)
+	break;
+      if (index==0)
+	printf("\nDeterministic Cache Parameters:\n");
+      printf("index=%lu: eax=%08lx ebx=%08lx ecx=%08lx edx=%08lx\n> ",
+	index, eax, ebx, ecx, edx);
+      switch (ctype) {
+	case 1:
+	  printf("Data cache");
+	  break;
+	case 2:
+	  printf("Instruction cache");
+	  break;
+	case 3:
+	  printf("Unified cache");
+	  break;
+	default:
+	  printf("Unknown cache type (%lu)", ctype);
+      }
+      printf(", level %lu", (eax>>5)&7);
+      if (eax&0x100u)
+	printf(", self initializing");
+      if (eax&0x200u)
+	printf(", fully associative");
+      printf("\n");
+      sets = ecx+1;
+      ways = ((ebx>>22)&0x3ffu)+1;
+      partitions = ((ebx>>12)&0x3ffu)+1;
+      linesize = (ebx&0xfffu)+1;
+      printf("> %lu sets", sets);
+      printf(", %lu ways", ways);
+      printf(", %lu partitions", partitions);
+      printf(", line size %lu", linesize);
+      printf("\n> full size %lu bytes\n", sets*ways*partitions*linesize);
+      t = (eax>>14)&0xfffu;
+      if (t>0)
+	printf("> shared between up to %lu threads\n", t+1);
+      t = (eax>>26)&0x3fu;
+      if (index==0 && t>0)
+	printf("> NB this package has up to %lx threads\n", t+1);
+    }
+  }
+  if (maxi >= 7) {
+    unsigned i;
+    unsigned long eax, ebx, ecx, edx;
+    cpuidx(7, 0, eax, ebx, ecx, edx);
+    if (ebx != 0) {
+      printf("\nStructured feature flags CPUID.07H.00H:EBX: %08lx:\n",
+	ebx);
+      for(i=0;i<32;i++){
+	if(ebx & (1<<i)){
+	  const char* fn = Intel_struct_ext_feature_flags_7_0_b[i];
+	  if (fn != NULL)
+	    printf("%s\n", fn);
+	  else
+	    printf("%d - unknown feature\n", i);
+	}
+      }
+    }
+  }
 }
 void printregs(int eax,int ebx,int ecx,int edx){
   int j;
@@ -396,18 +640,66 @@ void decode_intel_tlb(int x){
   case 0x4:
     printf("Data TLB: 4MB pages, 4-way set assoc, 8 entries\n");
     break;
+  case 0x5:
+    printf("Data TLB: 4MB pages, 4-way set assoc, 32 entries\n");
+    break;
   case 0x6:
     printf("1st-level instruction cache: 8KB, 4-way set assoc, 32 byte line size\n");
     break;
   case 0x8:
     printf("1st-level instruction cache: 16KB, 4-way set assoc, 32 byte line size\n");
     break;
+  case 0x9:
+    printf("1st-level instruction cache: 32KB, 4-way set assoc, 64 byte line size\n");
+    break;
   case 0xa:
     printf("1st-level data cache: 8KB, 2-way set assoc, 32 byte line size\n");
     break;
   case 0xc:
     printf("1st-level data cache: 16KB, 4-way set assoc, 32 byte line size\n");
     break;
+  case 0xd:
+    printf("1st-level data cache: 16KB, 4-way set assoc, 64 byte line size, ECC\n");
+    break;
+  case 0x21:
+    printf("256-KB L2 (MLC), 8-way set associative, 64 byte line size\n");
+    break;
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
+  case 0x3a:
+    printf("2nd-level cache: 192-KB, 6-way set associative, sectored cache, 64-byte line size\n");
+    break;
+  case 0x3b:
+    printf("2nd-level cache: 128-KB, 2-way set associative, sectored cache, 64-byte line size\n");
+    break;
+  case 0x3c:
+    printf("2nd-level cache: 256-KB, 4-way set associative, sectored cache, 64-byte line size\n");
+    break;
+  case 0x3d:
+    printf("2nd-level cache: 384-KB, 6-way set associative, sectored cache, 64-byte line size\n");
+    break;
+  case 0x3e:
+    printf("2nd-level cache: 512-KB, 4-way set associative, sectored cache, 64-byte line size\n");
+    break;
   case 0x40:
     printf("No 2nd-level cache, or if 2nd-level cache exists, no 3rd-level cache\n");
     break;
@@ -426,23 +718,67 @@ void decode_intel_tlb(int x){
   case 0x45:
     printf("2nd-level cache: 2MB, 4-way set assoc, 32 byte line size\n");
     break;
+  case 0x46:
+    printf("3rd-level cache: 4MB, 4-way set associative, 64-byte line size\n");
+    break;
+  case 0x47:
+    printf("3rd-level cache: 8MB, 8-way set associative, 64-byte line size\n");
+    break;
+  case 0x48:
+    printf("2nd-level cache: 3MB, 12-way set associative, 64-byte line size, unified on die\n");
+    break;
+  case 0x49:
+    /* TODO The code needs to be slightly restructured so we can check family and model here */
+    printf("3rd-level cache: 4MB, 16-way set associative, 64-byte line size (Intel Xeon MP, Family 0Fh, Model 06h\n");
+    printf("OR 2nd-level cache: 4MB, 16-way set associative, 64-byte line size\n");
+    break;
+  case 0x4a:
+    printf("3rd-level cache: 6MB, 12-way set associative, 64-byte line size\n");
+    break;
+  case 0x4b:
+    printf("3rd-level cache: 8MB, 16-way set associative, 64-byte line size\n");
+    break;
+  case 0x4c:
+    printf("3rd-level cache: 12MB, 12-way set associative, 64-byte line size\n");
+    break;
+  case 0x4d:
+    printf("3rd-level cache: 16MB, 16-way set associative, 64-byte line size\n");
+    break;
+  case 0x4e:
+    printf("3rd-level cache: 6MB, 24-way set associative, 64-byte line size\n");
+    break;
   case 0x50:
-    printf("Instruction TLB: 4KB and 2MB or 4MB pages, 64 entries\n");
+    printf("Instruction TLB: 4KB, 2MB or 4MB pages, fully assoc., 64 entries\n");
     break;
   case 0x51:
-    printf("Instruction TLB: 4KB and 2MB or 4MB pages, 128 entries\n");
+    printf("Instruction TLB: 4KB, 2MB or 4MB pages, fully assoc., 128 entries\n");
     break;
   case 0x52:
-    printf("Instruction TLB: 4KB and 2MB or 4MB pages, 256 entries\n");
+    printf("Instruction TLB: 4KB, 2MB or 4MB pages, fully assoc., 256 entries\n");
+    break;
+  case 0x55:
+    printf("Instruction TLB: 2MB or 4MB pages, fully assoc., 7 entries\n");
+    break;
+  case 0x56:
+    printf("Data TLB: 4MB pages, 4-way set associative, 16 entries\n");
+    break;
+  case 0x57:
+    printf("Data TLB: 4KB pages, 4-way set associative, 16 entries\n");
+    break;
+  case 0x5a:
+    printf("Data TLB: 2MB or 4MB pages, 4-way set associative, 32 entries\n");
     break;
   case 0x5b:
-    printf("Data TLB: 4KB and 4MB pages, 64 entries\n");
+    printf("Data TLB: 4KB or 4MB pages, fully assoc., 64 entries\n");
     break;
   case 0x5c:
-    printf("Data TLB: 4KB and 4MB pages, 128 entries\n");
+    printf("Data TLB: 4KB or 4MB pages, fully assoc., 128 entries\n");
     break;
   case 0x5d:
-    printf("Data TLB: 4KB and 4MB pages, 256 entries\n");
+    printf("Data TLB: 4KB or 4MB pages, fully assoc., 256 entries\n");
+    break;
+  case 0x60:
+    printf("1st-level data cache: 16-KB, 8-way set associative, sectored cache, 64-byte line size\n");
     break;
   case 0x66:
     printf("1st-level data cache: 8KB, 4-way set assoc, 64 byte line size\n");
@@ -454,25 +790,40 @@ void decode_intel_tlb(int x){
     printf("1st-level data cache: 32KB, 4-way set assoc, 64 byte line size\n");
     break;
   case 0x70:
-    printf("Trace cache: 12K-micro-op, 4-way set assoc\n");
+    printf("Trace cache: 12K-micro-op, 8-way set assoc\n");
     break;
   case 0x71:
-    printf("Trace cache: 16K-micro-op, 4-way set assoc\n");
+    printf("Trace cache: 16K-micro-op, 8-way set assoc\n");
     break;
   case 0x72:
-    printf("Trace cache: 32K-micro-op, 4-way set assoc\n");
+    printf("Trace cache: 32K-micro-op, 8-way set assoc\n");
+    break;
+  case 0x73:
+    printf("Trace cache: 64K-micro-op, 8-way set assoc\n");
+    break;
+  case 0x76:
+    printf("Instruction TLB: 2M/4M pages, fully associative, 8 entries\n");
+    break;
+  case 0x78:
+    printf("2nd-level cache: 1MB, 4-way set assoc, 64 byte line size\n");
     break;
   case 0x79:
     printf("2nd-level cache: 128KB, 8-way set assoc, sectored, 64 byte line size\n");
     break;
   case 0x7a:
-    printf("2nd-level cache: 256KB, 8-way set assoc, sectored, 64 byte line size\n");    
+    printf("2nd-level cache: 256KB, 8-way set assoc, sectored, 64 byte line size\n");
     break;
   case 0x7b:
     printf("2nd-level cache: 512KB, 8-way set assoc, sectored, 64 byte line size\n");
     break;
   case 0x7c:
-    printf("2nd-level cache: 1MB, 8-way set assoc, sectored, 64 byte line size\n");    
+    printf("2nd-level cache: 1MB, 8-way set assoc, sectored, 64 byte line size\n");
+    break;
+  case 0x7d:
+    printf("2nd-level cache: 2-MB, 8-way set associative, 64-byte line size\n");
+    break;
+  case 0x7f:
+    printf("2nd-level cache: 512KB, 2-way set assoc, 64 byte line size\n");
     break;
   case 0x82:
     printf("2nd-level cache: 256KB, 8-way set assoc, 32 byte line size\n");
@@ -486,44 +837,192 @@ void decode_intel_tlb(int x){
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
+  case 0xB1:
+    printf("Instruction TLB: 2MB Pages (8 entries) or 4MB pages (4 entries), 4-way set associative\n");
+    break;
+  case 0xB2:
+    printf("Instruction TLB: 4-KB Pages, 4-way set associative, 64 entries\n");
+    break;
+  case 0xB3:
+    printf("Data TLB: 4-KB Pages, 4-way set associative, 128 entries\n");
+    break;
+  case 0xB4:
+    printf("Data TLB: 4-KB Pages, 4-way set associative, 256 entries\n");
+    break;
+  case 0xCA:
+    printf("Shared 2nd-level TLB: 4-KB Pages, 4-way set associative, 512 entries\n");
+    break;
+  case 0xD0:
+    printf("3rd-level cache: 512KB, 4-way set associative, 64-byte line size\n");
+    break;
+  case 0xD1:
+    printf("3rd-level cache: 1MB, 4-way set associative, 64-byte line size\n");
+    break;
+  case 0xD2:
+    printf("3rd-level cache: 2MB, 4-way set associative, 64-byte line size\n");
+    break;
+  case 0xD6:
+    printf("3rd-level cache: 1MB, 8-way set associative, 64-byte line size\n");
+    break;
+  case 0xD7:
+    printf("3rd-level cache: 2MB, 8-way set associative, 64-byte line size\n");
+    break;
+  case 0xD8:
+    printf("3rd-level cache: 4MB, 8-way set associative, 64-byte line size\n");
+    break;
+  case 0xDC:
+    printf("3rd-level cache: 1.5MB, 12-way set associative, 64-byte line size\n");
+    break;
+  case 0xDD:
+    printf("3rd-level cache: 3MB, 12-way set associative, 64-byte line size\n");
+    break;
+  case 0xDE:
+    printf("3rd-level cache: 6MB, 12-way set associative, 64-byte line size\n");
+    break;
+  case 0xE2:
+    printf("3rd-level cache: 2MB, 16-way set associative, 64-byte line size\n");
+    break;
+  case 0xE3:
+    printf("3rd-level cache: 4MB, 16-way set associative, 64-byte line size\n");
+    break;
+  case 0xE4:
+    printf("3rd-level cache: 8MB, 16-way set associative, 64-byte line size\n");
+    break;
+  case 0xEA:
+    printf("3rd-level cache: 12MB, 24-way set associative, 64-byte line size\n");
+    break;
+  case 0xEB:
+    printf("3rd-level cache: 18MB, 24-way set associative, 64-byte line size\n");
+    break;
+  case 0xEC:
+    printf("3rd-level cache: 24MB, 24-way set associative, 64-byte line size\n");
+    break;
+  case 0xF0:
+    printf("64-byte prefetching\n");
+    break;
+  case 0xF1:
+    printf("128-byte prefetching\n");
+    break;
+  case 0xFF:
+    printf("CPUID leaf 2 does not report full information, query leaf 4\n");
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
+  "Pge1GB 1GB Page Support",
+  "RDTSCP RDTSCP instruction",
+  "28     Reserved",
+  "LM     64 bit long mode",
+  "3DNowE 3DNow! instruction extensions",
+  "3DNow  3DNow! instructions",
+};
+
+char *AMD_feature_flags3[] = {
+  "LhfSaf LAHF and SAHF instructions in 65-bit mode",
+  "CmpLeg Core Multi-Processing mode",
+  "SVM    Secure Virtual Machine",
+  "XAPSPC Extended APIC Register Space",
+  "AltMC8 LOCK MOV CR0 means MOV CR8",
+  "ABM    Advanced Bit Manipulation",
+  "SSE4A  EXTRQ, INSERTQ, MOVNTSS, and MOVNTSD support",
+  "MASSE  Misaligned SSE mode",
+  "3DNPFC PREFETCH and PREFETCHW support",
+  "OSVW   OS Visible Workaround support",
+  "10     Reserved",
+  "11     Reserved",
+  "SKINIT SKINIT, STGI, and DEV support",
+  "WDT    Watchdog Timer support"
+  "14     Reserved",
+  "15     Reserved",
+  "16     Reserved",
+  "17     Reserved",
+  "18     Reserved",
+  "19     Reserved",
+  "20     Reserved",
+  "21     Reserved",
+  "22     Reserved",
+  "23     Reserved",
+  "24     Reserved",
+  "25     Reserved",
+  "26     Reserved",
+  "27     Reserved",
+  "28     Reserved",
+  "29     Reserved",
+  "30     Reserved",
+  "31     Reserved",
 };
 
 char *Assoc[] = {
@@ -657,10 +1156,16 @@ void doamd(int maxi){
 	printf("Global Paging Extensions\n");
       } else {
 	if(edx & (1<<i)){
-	  printf("%s\n",AMD_feature_flags[i]);
+	  printf("%s\n",AMD_feature_flags2[i]);
 	}
       }
     }
+    printf("\nExtended Miscellaneous feature flags %08lx:\n", ecx);
+    for(i=0;i<32;i++){
+      if(ecx & (1<<i)){
+        printf("%s\n",AMD_feature_flags3[i]);
+      }
+    }
   }
   printf("\n");
   if(maxei >= 0x80000002){
