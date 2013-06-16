--- lib/Cm/CmSocket.h.orig	2003-10-23 13:37:30.000000000 +0900
+++ lib/Cm/CmSocket.h	2013-06-16 10:52:19.000000000 +0900
@@ -147,9 +147,9 @@
 inline int CmSockAddr::length() const {return length_;}
 inline sock* CmSockAddr::sockAddr() const {return addr_;}
 
-struct SocketSet;
+class SocketSet;
 //======================================================================
-struct CmSocket:public CmSockAddr {
+class CmSocket:public CmSockAddr {
 private:
 	int fileDesc_;
 	int syserrno_;
@@ -250,7 +250,7 @@
 
 //======================================================================
 // Stream Specific Functions
-struct CmStream:public CmSocket {
+class CmStream:public CmSocket {
 private:
 	CmSockAddr* self_;
 	CmSockAddr* peer_;
@@ -284,7 +284,8 @@
 // Datagram Socket can be used with connect and send/receive,
 // and can be specified the receiver when sending or can be given
 // the sender when receiving.
-struct CmDgram:public CmSocket {
+class CmDgram:public CmSocket {
+public:
 	CmDgram(int l,const sock* s=0,int fd=-1);
 	CmDgram(const inSock&,int fd=-1);
 	CmDgram(const in6Sock&,int fd=-1);
@@ -300,7 +301,8 @@
 
 //======================================================================
 // Raw Specific Functions
-struct CmRaw:public CmDgram {
+class CmRaw:public CmDgram {
+public:
 	CmRaw(int l,const sock* s=0,int fd=-1);
 virtual	int socket();
 virtual	CmSocket* create(int,const sock*,int=-1);
@@ -310,7 +312,8 @@
 //======================================================================
 // for Unix Domain Socket
 //	It can be stream/datagram and any address or pathname.
-struct UnixSocket {
+class UnixSocket {
+public:
 static CmSocket* stream();
 static CmSocket* stream(CSTR aName);
 static CmDgram* datagram();
@@ -323,7 +326,7 @@
 // for Inet Domain Socket
 //	It can be stream/datagram and any address or service
 //	with/without hostname/ipaddress.
-struct InetSocket {
+class InetSocket {
 static int getService(CSTR serv);
 //----------------------------------------------------------------------
 // defaultService is used for debugging.
