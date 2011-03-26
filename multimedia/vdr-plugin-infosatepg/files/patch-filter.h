--- a/filter.h
+++ b/filter.h
@@ -33,8 +33,8 @@ private:
   cGlobalInfosatepg *global;
   u_long do_sum(u_long sum, u_char *buf, int nBytes);
   u_short foldsum(u_long sum);
-  u_short IPChecksum(iphdr *ipHeader);
-  u_short UDPChecksum(iphdr *ipHeader, udphdr *udpHeader);
+  u_short IPChecksum(ip *ipHeader);
+  u_short UDPChecksum(ip *ipHeader, udphdr *udpHeader);
 protected:
   virtual void Process(u_short Pid, u_char Tid, const u_char *Data, int Length);
 public:
