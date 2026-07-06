--- core/src/plugins/stored/scsitapealert/scsitapealert-sd.cc.orig	2026-06-24 10:21:35 UTC
+++ core/src/plugins/stored/scsitapealert/scsitapealert-sd.cc
@@ -54,10 +54,10 @@ void dispatch_messages(JobControlRecord* jcr,
         "Possible cause: %s\n";
 
   constexpr const char* print_msg
-      = "TapeAlert on device \"%s\" with volume \"%s\" from jobid %lu: "
+      = "TapeAlert on device \"%s\" with volume \"%s\" from jobid %llu: "
         "[%d] %s\n";
   constexpr const char* print_msg_novol
-      = "TapeAlert on device \"%s\" from jobid %lu: [%d] %s\n";
+      = "TapeAlert on device \"%s\" from jobid %llu: [%d] %s\n";
 
   const uint64_t jobid{jcr ? jcr->JobId : 0};
 
@@ -66,11 +66,11 @@ void dispatch_messages(JobControlRecord* jcr,
       if (volume && volume[0] != '\0') {
         Jmsg(jcr, flag.type, 0, job_msg, device, volume, flag.no, flag.name,
              flag.message, flag.cause);
-        Pmsg0(-1, print_msg, device, volume, jobid, flag.no, flag.name);
+        Pmsg0(-1, print_msg, device, volume, (unsigned long long)jobid, flag.no, flag.name);
       } else {
         Jmsg(jcr, flag.type, 0, job_msg_novol, device, flag.no, flag.name,
              flag.message, flag.cause);
-        Pmsg0(-1, print_msg_novol, device, jobid, flag.no, flag.name);
+        Pmsg0(-1, print_msg_novol, device, (unsigned long long)jobid, flag.no, flag.name);
       }
     }
   }
@@ -251,7 +251,7 @@ static bRC handle_tapealert_readout(void* value)
   Dmsg1(debuglevel,
         "scsitapealert-sd: checking for tapealerts on device %s DONE\n",
         dev->archive_device_string);
-  Dmsg1(debuglevel, "scsitapealert-sd: flags: %ld \n", flags);
+  Dmsg1(debuglevel, "scsitapealert-sd: flags: %llu \n", (unsigned long long)flags);
 
   if (flags) {
     Dmsg1(
