--- ./src/nntpthreadsocket.h.orig	2007-06-25 23:05:29.000000000 -0500
+++ ./src/nntpthreadsocket.h	2007-06-25 23:06:23.000000000 -0500
@@ -234,7 +234,7 @@
 		bool getHead(QString group, int artnum); //Unimplemented
 		int m_getError() {return error;}
     	const char *m_getErrorDesc() {return (const char *) errorString;}
-		char * NntpThreadSocket::m_findEndLine( char * start, char * end );
+		char * m_findEndLine( char * start, char * end );
 		void setHost(NntpHost *nh);
 		bool m_sendCmd( QString& cmd, int response );
 		QTime prevTime, currentTime;
