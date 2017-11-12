
https://github.com/monero-project/monero/pull/2792

--- src/cryptonote_basic/miner.cpp.orig
+++ src/cryptonote_basic/miner.cpp
@@ -50,12 +50,25 @@
   #include <IOKit/ps/IOPowerSources.h>
   #include <mach/mach_host.h>
   #include <AvailabilityMacros.h>
   #include <TargetConditionals.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <devstat.h>
+#include <errno.h>
+#include <fcntl.h>
+#include <machine/apm_bios.h>
+#include <stdio.h>
+#include <sys/resource.h>
+#include <sys/sysctl.h>
+#include <sys/times.h>
+#include <sys/types.h>
+#include <unistd.h>
+#endif
+
 #undef MONERO_DEFAULT_LOG_CATEGORY
 #define MONERO_DEFAULT_LOG_CATEGORY "miner"
 
 using namespace epee;
 
 #include "miner.h"
@@ -732,14 +745,12 @@ namespace cryptonote
 
         return true;
     	}
 
     #elif defined(__linux__)
 
-      const std::string STR_CPU("cpu");
-      const std::size_t STR_CPU_LEN = STR_CPU.size();
       const std::string STAT_FILE_PATH = "/proc/stat";
 
       if( !epee::file_io_utils::is_file_exist(STAT_FILE_PATH) )
       {
         LOG_ERROR("'" << STAT_FILE_PATH << "' file does not exist");
         return false;
@@ -782,15 +793,42 @@ namespace cryptonote
 
       idle_time = stats.cpu_ticks[CPU_STATE_IDLE];
       total_time = idle_time + stats.cpu_ticks[CPU_STATE_USER] + stats.cpu_ticks[CPU_STATE_SYSTEM];
       
       return true;
 
+    #elif defined(__FreeBSD__)
+
+      struct statinfo s;
+      size_t n = sizeof(s.cp_time);
+      if( sysctlbyname("kern.cp_time", s.cp_time, &n, NULL, 0) == -1 )
+      {
+        LOG_ERROR("sysctlbyname(\"kern.cp_time\"): " << strerror(errno));
+        return false;
+      }
+      if( n != sizeof(s.cp_time) )
+      {
+        LOG_ERROR("sysctlbyname(\"kern.cp_time\") output is unexpectedly "
+          << n << " bytes instead of the expected " << sizeof(s.cp_time)
+          << " bytes.");
+        return false;
+      }
+
+      idle_time = s.cp_time[CP_IDLE];
+      total_time =
+        s.cp_time[CP_USER] +
+        s.cp_time[CP_NICE] +
+        s.cp_time[CP_SYS] +
+        s.cp_time[CP_INTR] +
+        s.cp_time[CP_IDLE];
+
+      return true;
+
     #endif
 
-    return false; // unsupported systemm..
+    return false; // unsupported system
   }
   //-----------------------------------------------------------------------------------------------------
   bool miner::get_process_time(uint64_t& total_time)
   {
     #ifdef _WIN32
 
@@ -804,24 +842,24 @@ namespace cryptonote
           ( (((uint64_t)(kernelTime.dwHighDateTime)) << 32) | ((uint64_t)kernelTime.dwLowDateTime) )
           + ( (((uint64_t)(userTime.dwHighDateTime)) << 32) | ((uint64_t)userTime.dwLowDateTime) );
 
         return true;
       }
 
-    #elif (defined(__linux__) && defined(_SC_CLK_TCK)) || defined(__APPLE__)
+    #elif (defined(__linux__) && defined(_SC_CLK_TCK)) || defined(__APPLE__) || defined(__FreeBSD__)
 
       struct tms tms;
       if ( times(&tms) != (clock_t)-1 )
       {
     		total_time = tms.tms_utime + tms.tms_stime;
         return true;
       }
 
     #endif
 
-    return false; // unsupported system..
+    return false; // unsupported system
   }
   //-----------------------------------------------------------------------------------------------------  
   uint8_t miner::get_percent_of_total(uint64_t other, uint64_t total)
   {
     return (uint8_t)( ceil( (other * 1.f / total * 1.f) * 100) );    
   }
@@ -926,12 +964,76 @@ namespace cryptonote
       if (boost::logic::indeterminate(on_battery))
       {
         LOG_ERROR("couldn't query power status from " << power_supply_class_path);
       }
       return on_battery;
 
+    #elif defined(__FreeBSD__)
+      int ac;
+      size_t n = sizeof(ac);
+      if( sysctlbyname("hw.acpi.acline", &ac, &n, NULL, 0) == -1 )
+      {
+        if( errno != ENOENT )
+        {
+          LOG_ERROR("Cannot query battery status: "
+            << "sysctlbyname(\"hw.acpi.acline\"): " << strerror(errno));
+          return boost::logic::tribool(boost::logic::indeterminate);
+        }
+
+        // If sysctl fails with ENOENT, then try querying /dev/apm.
+
+        static const char* dev_apm = "/dev/apm";
+        const int fd = open(dev_apm, O_RDONLY);
+        if( fd == -1 ) {
+          LOG_ERROR("Cannot query battery status: "
+            << "open(): " << dev_apm << ": " << strerror(errno));
+          return boost::logic::tribool(boost::logic::indeterminate);
+        }
+
+        apm_info info;
+        if( ioctl(fd, APMIO_GETINFO, &info) == -1 ) {
+          close(fd);
+          LOG_ERROR("Cannot query battery status: "
+            << "ioctl(" << dev_apm << ", APMIO_GETINFO): " << strerror(errno));
+          return boost::logic::tribool(boost::logic::indeterminate);
+        }
+
+        close(fd);
+
+        // See apm(8).
+        switch( info.ai_acline )
+        {
+        case 0: // off-line
+        case 2: // backup power
+          return boost::logic::tribool(true);
+        case 1: // on-line
+          return boost::logic::tribool(false);
+        }
+        switch( info.ai_batt_stat )
+        {
+        case 0: // high
+        case 1: // low
+        case 2: // critical
+          return boost::logic::tribool(true);
+        case 3: // charging
+          return boost::logic::tribool(false);
+        }
+
+        LOG_ERROR("Cannot query battery status: "
+          << "sysctl hw.acpi.acline is not available and /dev/apm returns "
+          << "unexpected ac-line status (" << info.ai_acline << ") and "
+          << "battery status (" << info.ai_batt_stat << ").");
+        return boost::logic::tribool(boost::logic::indeterminate);
+      }
+      if( n != sizeof(ac) )
+      {
+        LOG_ERROR("sysctlbyname(\"hw.acpi.acline\") output is unexpectedly "
+          << n << " bytes instead of the expected " << sizeof(ac) << " bytes.");
+        return boost::logic::tribool(boost::logic::indeterminate);
+      }
+      return boost::logic::tribool(ac == 0);
     #endif
     
     LOG_ERROR("couldn't query power status");
     return boost::logic::tribool(boost::logic::indeterminate);
   }
 }
