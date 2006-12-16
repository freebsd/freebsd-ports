diff -u src/TCPPacket.h.orig src/TCPPacket.h
--- src/TCPPacket.h.orig	Sat Dec 16 00:56:26 2006
+++ src/TCPPacket.h	Sat Dec 16 00:59:55 2006
@@ -29,24 +29,24 @@
 class TCPPacket
 {
 public:
-	TCPPacket::TCPPacket( const u_char *data, unsigned int data_len );
-	TCPPacket::TCPPacket( TCPPacket & orig );
-	seq_t TCPPacket::getSeq() const;
-	seq_t TCPPacket::getAck() const;
+	TCPPacket( const u_char *data, unsigned int data_len );
+	TCPPacket( TCPPacket & orig );
+	seq_t getSeq() const;
+	seq_t getAck() const;
 	bool isFlagSet(unsigned int);
 	unsigned short headerLen() const { return header_len; };

 	portnum_t srcPort() const;
 	portnum_t dstPort() const;

-	bool TCPPacket::fin() const;
-	bool TCPPacket::syn() const;
-	bool TCPPacket::rst() const;
-	bool TCPPacket::psh() const;
-	bool TCPPacket::ack() const;
-	bool TCPPacket::urg() const;
-	bool TCPPacket::ece() const;
-	bool TCPPacket::cwr() const;
+	bool fin() const;
+	bool syn() const;
+	bool rst() const;
+	bool psh() const;
+	bool ack() const;
+	bool urg() const;
+	bool ece() const;
+	bool cwr() const;

 	friend ostream & operator<<( ostream &, const TCPPacket &);
 private:
