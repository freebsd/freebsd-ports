--- pcap.pyx.orig	2005-10-17 00:08:17 UTC
+++ pcap.pyx
@@ -17,9 +17,11 @@ __url__ = 'http://monkey.org/~dugsong/py
 __version__ = '1.1'
 
 import sys
+import struct
 
 cdef extern from "Python.h":
     object PyBuffer_FromMemory(char *s, int len)
+    int    PyObject_AsCharBuffer(object obj, char **buffer, int *buffer_len)
     int    PyGILState_Ensure()
     void   PyGILState_Release(int gil)
     void   Py_BEGIN_ALLOW_THREADS()
@@ -42,6 +44,10 @@ cdef extern from "pcap.h":
         unsigned int caplen
     ctypedef struct pcap_t:
         int __xxx
+    ctypedef struct pcap_if_t # hack for win32
+    ctypedef struct pcap_if_t:
+        pcap_if_t *next
+        char *name
 
 ctypedef void (*pcap_handler)(void *arg, pcap_pkthdr *hdr, char *pkt)
 
@@ -62,6 +68,13 @@ cdef extern from "pcap.h":
     char   *pcap_geterr(pcap_t *p)
     void    pcap_close(pcap_t *p)
     int     bpf_filter(bpf_insn *insns, char *buf, int len, int caplen)
+    int     pcap_findalldevs(pcap_if_t **alldevsp, char *errbuf)
+    void    pcap_freealldevs(pcap_if_t *alldevs)
+    int     pcap_lookupnet(char *device,
+                           unsigned int *netp,
+                           unsigned int *maskp,
+                           char *errbuf)
+    int     pcap_sendpacket(pcap_t *p, char *buf, int size)
 
 cdef extern from "pcap_ex.h":
     # XXX - hrr, sync with libdnet and libevent
@@ -134,16 +147,18 @@ cdef class bpf:
             raise IOError, 'bad filter'
     def filter(self, buf):
         """Return boolean match for buf against our filter."""
+        cdef char *p
         cdef int n
-        n = len(buf)
-        if bpf_filter(self.fcode.bf_insns, buf, n, n) == 0:
+        if PyObject_AsCharBuffer(buf, &p, &n) < 0:
+            raise TypeError
+        if bpf_filter(self.fcode.bf_insns, p, n, n) == 0:
             return False
         return True
     def __dealloc__(self):
         pcap_freecode(&self.fcode)
             
 cdef class pcap:
-    """pcap(name=None, snaplen=65535, promisc=True, immediate=False) -> packet capture object
+    """pcap(name=None, snaplen=65535, promisc=True, timeout_ms=None, immediate=False)  -> packet capture object
     
     Open a handle to a packet capture descriptor.
     
@@ -152,6 +167,9 @@ cdef class pcap:
                  or None to open the first available up interface
     snaplen   -- maximum number of bytes to capture for each packet
     promisc   -- boolean to specify promiscuous mode sniffing
+    timeout_ms -- requests for the next packet will return None if the timeout
+                  (in milliseconds) is reached and no packets were received
+                  (Default: no timeout)  
     immediate -- disable buffering, if possible
     """
     cdef pcap_t *__pcap
@@ -161,7 +179,7 @@ cdef class pcap:
     cdef int __dloff
     
     def __init__(self, name=None, snaplen=65535, promisc=True,
-                 timeout_ms=500, immediate=False):
+                 timeout_ms=0, immediate=False):
         global dltoff
         cdef char *p
         
@@ -171,7 +189,7 @@ cdef class pcap:
                 raise OSError, self.__ebuf
         else:
             p = name
-        
+
         self.__pcap = pcap_open_offline(p, self.__ebuf)
         if not self.__pcap:
             self.__pcap = pcap_open_live(pcap_ex_name(p), snaplen, promisc,
@@ -184,7 +202,7 @@ cdef class pcap:
         try: self.__dloff = dltoff[pcap_datalink(self.__pcap)]
         except KeyError: pass
         if immediate and pcap_ex_immediate(self.__pcap) < 0:
-            raise OSError, "couldn't set BPF immediate mode"
+            raise OSError, "couldn't enable immediate mode"
     
     property name:
         """Network interface or dumpfile name."""
@@ -243,16 +261,6 @@ cdef class pcap:
         """Return datalink type (DLT_* values)."""
         return pcap_datalink(self.__pcap)
     
-    def next(self):
-        """Return the next (timestamp, packet) tuple, or None on error."""
-        cdef pcap_pkthdr hdr
-        cdef char *pkt
-        pkt = <char *>pcap_next(self.__pcap, &hdr)
-        if not pkt:
-            return None
-        return (hdr.ts.tv_sec + (hdr.ts.tv_usec / 1000000.0),
-                PyBuffer_FromMemory(pkt, hdr.caplen))
-
     def __add_pkts(self, ts, pkt, pkts):
         pkts.append((ts, pkt))
     
@@ -288,18 +296,24 @@ cdef class pcap:
             raise exc[0], exc[1], exc[2]
         return n
 
-    def loop(self, callback, *args):
-        """Loop forever, processing packets with a user callback.
-        The loop can be exited with an exception, including KeyboardInterrupt.
+    def loop(self, cnt, callback, *args):
+        """Processing packets with a user callback during a loop.
+        The loop can be exited when cnt value is reached
+        or with an exception, including KeyboardInterrupt.
         
         Arguments:
 
+        cnt      -- number of packets to process;
+                    0 or -1 to process all packets until an error occurs,
+                    EOF is reached;
         callback -- function with (timestamp, pkt, *args) prototype
         *args    -- optional arguments passed to callback on execution
         """
         cdef pcap_pkthdr *hdr
         cdef char *pkt
         cdef int n
+        cdef int i
+        i = 1
         pcap_ex_setup(self.__pcap)
         while 1:
             Py_BEGIN_ALLOW_THREADS
@@ -308,10 +322,22 @@ cdef class pcap:
             if n == 1:
                 callback(hdr.ts.tv_sec + (hdr.ts.tv_usec / 1000000.0),
                          PyBuffer_FromMemory(pkt, hdr.caplen), *args)
+            elif n == 0:
+                break
             elif n == -1:
                 raise KeyboardInterrupt
             elif n == -2:
                 break
+            if i == cnt:
+                break
+            i = i + 1
+
+    def sendpacket(self, buf):
+        """Send a raw network packet on the interface."""
+        ret = pcap_sendpacket(self.__pcap, buf, len(buf))
+        if ret == -1:
+            raise OSError, pcap_geterr(self.__pcap)
+        return len(buf)
     
     def geterr(self):
         """Return the last error message associated with this handle."""
@@ -340,6 +366,8 @@ cdef class pcap:
             if n == 1:
                 return (hdr.ts.tv_sec + (hdr.ts.tv_usec / 1000000.0),
                         PyBuffer_FromMemory(pkt, hdr.caplen))
+            elif n == 0:
+                return None
             elif n == -1:
                 raise KeyboardInterrupt
             elif n == -2:
@@ -364,3 +392,36 @@ def lookupdev():
         raise OSError, ebuf
     return p
 
+def findalldevs():
+    """Return a list of capture devices."""
+    cdef pcap_if_t *devs, *curr
+    cdef char ebuf[256]
+
+    status = pcap_findalldevs(&devs, ebuf)
+    if status:
+        raise OSError(ebuf)
+    retval = []
+    if not devs:
+        return retval
+    curr = devs
+    while 1:
+        retval.append(curr.name)
+        if not curr.next:
+            break
+        curr = curr.next
+    pcap_freealldevs(devs)
+    return retval
+
+def lookupnet(char *dev):
+    """
+    Return the address and the netmask of a given device
+    as network-byteorder integers.
+    """
+    cdef unsigned int netp
+    cdef unsigned int maskp
+    cdef char ebuf[256]
+
+    status = pcap_lookupnet(dev, &netp, &maskp, ebuf)
+    if status:
+        raise OSError(ebuf)
+    return struct.pack('I', netp), struct.pack('I', maskp)
