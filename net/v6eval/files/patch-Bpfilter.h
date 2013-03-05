--- lib/pkt/Bpfilter.h	2001-10-05 20:41:19.000000000 +0900
+++ lib/pkt/Bpfilter.h	2008-01-01 04:50:29.000000000 +0900
@@ -62,7 +62,7 @@ public:
 	int statistics(uint32_t&,uint32_t&) const;
 	int receive(caddr_t) const;
 	int send(caddr_t,uint32_t) const;
-	uint32_t Bpfilter::getDLT() const;
+	uint32_t getDLT() const;
 };
 inline int Bpfilter::fileDesc() const {return fd_;}
 inline uint32_t Bpfilter::bufferSize() const {return bufsize_;}
