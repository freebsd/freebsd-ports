*** pcap.pyx	Mon Oct 17 08:00:11 2005
--- /Users/gnn/src/pypcap-1.1.new/pcap.pyx	Fri Jun 23 18:22:03 2006
***************
*** 61,66 ****
--- 64,70 ----
      int     pcap_stats(pcap_t *p, pcap_stat *ps)
      char   *pcap_geterr(pcap_t *p)
      void    pcap_close(pcap_t *p)
+     int     pcap_inject(pcap_t *p, char *buf, int size)
      int     bpf_filter(bpf_insn *insns, char *buf, int len, int caplen)
  
  cdef extern from "pcap_ex.h":
***************
*** 313,318 ****
--- 318,338 ----
              elif n == -2:
                  break
      
+     def inject(self, packet, len):
+         """Inject a packet onto an interface.
+         May or may not work depending on platform.
+ 
+         Arguments:
+ 
+         packet -- a pointer to the packet in memory
+         """
+         cdef int n
+         n = pcap_inject(self.__pcap, packet, len)
+         if (n < 0):
+             raise OSError, pcap_geterr(self.__pcap)
+ 
+         return n
+     
      def geterr(self):
          """Return the last error message associated with this handle."""
          return pcap_geterr(self.__pcap)
