--- pjlsession.cpp.orig	Sat Jul  6 18:36:21 2002
+++ pjlsession.cpp	Mon Aug  9 11:39:10 2004
@@ -3,7 +3,7 @@
  *
  * $Id: pjlsession.cpp,v 1.7 2002/07/05 16:41:26 fx Exp $
  */
-#include <iostream.h>
+#include <iostream>
 #include <stdio.h>
 #include <stdlib.h>
 
@@ -21,13 +21,14 @@
 #include <sys/types.h>			// open(), close(), write()
 #include <sys/stat.h>
 #include <fcntl.h>
-#endif UNIX
+#endif // UNIX
 
 
 #include "pjlsession.h"
 #include "pjllists.h"
 #include "commands.h"
 
+using namespace std;
 
 PJLsession::PJLsession() {
 	// nothing so far
@@ -69,7 +70,7 @@
 	if (ts.stoken("@PJL INFO VARIABLES",0)==NULL) {
 #ifdef _DEBUG
 		cerr << "PJLsession::read_env(): did not receive command echo" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExPJLerror();
 	}
 
@@ -167,7 +168,7 @@
 	if (ts.stoken("@PJL INFO ID",0)==NULL) {
 #ifdef _DEBUG
 		cerr << "PJLsession::read_devive_id(): did not receive command echo" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExPJLerror();
 	}
 	
@@ -186,7 +187,7 @@
 	_snprintf(numb,49,"%u",pass);
 #else
 	snprintf(numb,49,"%u",pass);
-#endif UNIX
+#endif // UNIX
 	
 	connection.clear();
 	connection.sendbuf.set(PJL_START);
@@ -206,7 +207,7 @@
 	if (ts.findstr("@PJL DINQUIRE PASSWORD")==NULL) {
 #ifdef _DEBUG
 		cerr << "PJLsession::disable_pjl_password(): did not receive command echo" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExPJLerror();
 	}
 	
@@ -219,7 +220,7 @@
 
 #ifdef _DEBUG
 	cerr << "PJLsession::disable_pjl_password(): DINQUIRE didn't return result" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 	throw ExPJLerror();
 
 }
@@ -234,7 +235,7 @@
 	_snprintf(numb,49,"%u",pass);
 #else
 	snprintf(numb,49,"%u",pass);
-#endif UNIX
+#endif // UNIX
 
 	connection.clear();
 	connection.sendbuf.set(PJL_START);
@@ -277,7 +278,7 @@
 	if (ts.findstr("@PJL DINQUIRE PASSWORD")==NULL) {
 #ifdef _DEBUG
 		cerr << "PJLsession::chk_pjl_password(): did not receive command echo" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExPJLerror();
 	}
 	
@@ -290,7 +291,7 @@
 
 #ifdef _DEBUG
 	cerr << "PJLsession::chk_pjl_password(): DINQUIRE didn't return result" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 	throw ExPJLerror();
 
 }
@@ -353,7 +354,7 @@
 	if (ts.stoken("@PJL INFO FILESYS",0)==NULL) {
 #ifdef _DEBUG
 		cerr << "PJLsession::read_volumes(): did not receive command echo" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExPJLerror();
 	}
 
@@ -404,14 +405,14 @@
 	if (ts.stoken("@PJL FSDIRLIST",0)==NULL) {
 #ifdef _DEBUG
 		cerr << "PJLsession::read_dir(): did not receive command echo" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExPJLerror();
 	}
 
 	if (ts.stoken("\r\n",1)==NULL) {
 #ifdef _DEBUG
 		cerr << "PJLsession::read_dir(): strange! got echo but no more lines" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExPJLerror();
 	} else {
 		String err=ts.stoken("\r\n",1);
@@ -419,7 +420,7 @@
 		if (err.findstr("FILEERROR")!=NULL) {
 #ifdef _DEBUG
 			cerr << "PJLsession::read_dir(): Filesystem error " << err.token('=',1) << endl;
-#endif _DEBUG
+#endif // _DEBUG
 			throw ExPJLerror();
 		}
 	}
@@ -495,7 +496,7 @@
 	if (ts.findstr("@PJL FSQUERY")==NULL) {
 #ifdef _DEBUG
 		cerr << "PJLsession::stat(): did not receive command echo" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExPJLerror();
 	}
 
@@ -514,7 +515,7 @@
 #ifdef _DEBUG
 			cerr << "PJLsession::stat(): strange answer: '"
 				<< ts.get() << "'" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 			throw ExPJLerror();
 		}
 	// failure ...
@@ -524,13 +525,13 @@
 		if (err.findstr("FILEERROR")!=NULL) {
 #ifdef _DEBUG
 			cerr << "PJLsession::stat(): Filesystem error " << err.token('=',1) << endl;
-#endif _DEBUG
+#endif // _DEBUG
 			return (-1);
 		} else {
 			#ifdef _DEBUG
 			cerr << "PJLsession::does_exist(): strange answer: '"
 				<< ts.get() << "'" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 			throw ExPJLerror();
 		}
 	}
@@ -578,7 +579,7 @@
 	_snprintf(numb,49,"%u",expsize);
 #else
 	snprintf(numb,49,"%u",expsize);
-#endif UNIX
+#endif // UNIX
 
 	filebuffer.clear();
 	connection.clear();
@@ -602,7 +603,7 @@
 	if (ts.findstr("@PJL FSUPLOAD")==NULL) {
 #ifdef _DEBUG
 		cerr << "PJLsession::recv_file(): did not receive command echo" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExPJLerror();
 	}
 	if (ts.findstr("SIZE=")==NULL) {
@@ -614,13 +615,13 @@
 		if (ts.findstr("FILEERROR")!=NULL) {
 #ifdef _DEBUG
 			cerr << "PJLsession::recv_file(): Filesystem error " << ts.token('=',1) << endl;
-#endif _DEBUG
+#endif // _DEBUG
 			throw ExPJLerror();
 		} else {
 #ifdef _DEBUG
 			cerr << "PJLsession::recv_file(): strange answer: '"
 				<< ts.get() << "'" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 			throw ExPJLerror();
 		}
 	} else {
@@ -633,7 +634,7 @@
 		fsi=fsi.token('=',1);
 #ifdef _DEBUG
 		//cout << "DEBUG: expected size: " << expsize << ", reported: " << atoi(fsi.get()) << endl;
-#endif _DEBUG
+#endif // _DEBUG
 
 		// timeout depends on size (of course) ;)
 		connection.recvatleast((unsigned int)atoi(fsi.get()),
@@ -658,7 +659,7 @@
 	if ((fd=open(filename,_O_WRONLY | _O_CREAT | _O_TRUNC | _O_BINARY))<0) {
 #ifdef _DEBUG
 		cerr << "PJLsession::recv_file(): Could not open local file "<<filename<<endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExInvalid();
 	}
 #else
@@ -666,10 +667,10 @@
 	if ((fd=open(filename,O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP))<0) {
 #ifdef _DEBUG
 		cerr << "PJLsession::recv_file(): Could not open local file "<<filename<<endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExInvalid();
 	}
-#endif UNIX
+#endif // UNIX
 	
 	connection.clear();
 	connection.sendbuf.set(PJL_START);
@@ -692,7 +693,7 @@
 	if (ts.findstr("@PJL FSUPLOAD")==NULL) {
 #ifdef _DEBUG
 		cerr << "PJLsession::recv_file(): did not receive command echo" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExPJLerror();
 	}
 	if (ts.findstr("SIZE=")==NULL) {
@@ -704,13 +705,13 @@
 		if (ts.findstr("FILEERROR")!=NULL) {
 #ifdef _DEBUG
 			cerr << "PJLsession::recv_file(): Filesystem error " << ts.token('=',1) << endl;
-#endif _DEBUG
+#endif // _DEBUG
 			throw ExPJLerror();
 		} else {
 #ifdef _DEBUG
 			cerr << "PJLsession::recv_file(): strange answer: '"
 				<< ts.get() << "'" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 			throw ExPJLerror();
 		}
 	} else {
@@ -723,7 +724,7 @@
 		fsi=fsi.token('=',1);
 #ifdef _DEBUG
 		//cout << "DEBUG: expected size: " << expsize << ", reported: " << atoi(fsi.get()) << endl;
-#endif _DEBUG
+#endif // _DEBUG
 
 
 		for (unsigned int i=0;i<expsize;i++) {
@@ -735,7 +736,7 @@
 				if ((bw=_write(fd,connection.recvbuf.get(),connection.recvbuf.length()))<0) {
 #ifdef _DEBUG
 					cerr << "PJLsession::recv_file(): _write() to local file failed" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 					throw ExInvalid();
 				}
 			} catch (TCPcon::ExTimeout) {
@@ -746,14 +747,14 @@
 				if ((bw=write(fd,connection.recvbuf.get(),connection.recvbuf.length()))<0) {
 #ifdef _DEBUG
 					cerr << "PJLsession::recv_file(): _write() to local file failed" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 					throw ExInvalid();
 				}
 			} catch (TCPcon::ExTimeout) {
-				std::close(fd);
+				::close(fd);
 			}
 		}
-#endif UNIX
+#endif // UNIX
 		
 		connection.recvbuf.clear();
 		// recv the final <FF> (\x0c) from device and discard it
@@ -771,7 +772,7 @@
 	_snprintf(numb,49,"%u",filebuffer.length());
 #else
 	snprintf(numb,49,"%u",filebuffer.length());
-#endif UNIX
+#endif // UNIX
 
 	connection.clear();
 	connection.sendbuf.set(PJL_START);
@@ -808,7 +809,7 @@
 #ifdef _DEBUG
 		cerr << "PJLsession::send_file(2): could not stat file "
 			<< filename << endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExInvalid();
 	}
 
@@ -817,7 +818,7 @@
 #ifdef _DEBUG
 		cerr << "PJLsession::send_file(2) Could not open local file "
 			<< filename <<endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExInvalid();
 	} else {
 		_snprintf(numb,49,"%u",statbuf.st_size);
@@ -854,11 +855,11 @@
 	int			fd,br=0;
 	char			rb[1025];
 	
-	if (std::stat(filename,&statbuf)!=0) {
+	if (::stat(filename,&statbuf)!=0) {
 #ifdef _DEBUG
 		cerr << "PJLsession::send_file(2): could not stat file "
 			<< filename << endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExInvalid();
 	}
 	
@@ -866,10 +867,10 @@
 #ifdef _DEBUG
 		cerr << "PJLsession::send_file(2) Could not open local file "
 			<< filename <<endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExInvalid();
 	} else {
-		snprintf(numb,49,"%lu",statbuf.st_size);
+		snprintf(numb,49,"%lu",(long int)statbuf.st_size);
 		connection.clear();
 		connection.sendbuf.set(PJL_START);
 		connection.sendbuf.append(PJL_FSDOWNLOAD);
@@ -885,12 +886,12 @@
 			connection.sendbuf.set(rb,br);
 			connection.senddata();
 		}
-		std::close(fd);
+		::close(fd);
 	}
 	connection.clear();
 }
 
-#endif UNIX
+#endif // UNIX
 
 
 void PJLsession::append_file(char *str) {
@@ -900,7 +901,7 @@
 	_snprintf(numb,49,"%u",filebuffer.length());
 #else
 	snprintf(numb,49,"%u",filebuffer.length());
-#endif UNIX
+#endif // UNIX
 
 	connection.clear();
 	connection.sendbuf.set(PJL_START);
@@ -942,7 +943,7 @@
 #ifdef _DEBUG
 		cerr << "PJLsession::upload_RFU_firmware() Could not open local file "
 			<< rfu_file <<endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExInvalid();
 	} else {
 		while ((br=_read(fd,rb,1024))>0) {
@@ -960,7 +961,7 @@
 #ifdef _DEBUG
 		cerr << "PJLsession::upload_RFU_firmware() Could not open local file "
 			<< rfu_file <<endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExInvalid();
 	} else {
 		while ((br=read(fd,rb,1024))>0) {
@@ -968,10 +969,10 @@
 			connection.sendbuf.set(rb,br);
 			connection.senddata();
 		}
-		std::close(fd);
+		::close(fd);
 	}
 
-#endif UNIX
+#endif // UNIX
 
 	connection.clear();
 }
@@ -1016,7 +1017,7 @@
 	if ((sttype==0)||(sttype>7)) {
 #ifdef _DEBUG
 		cerr << "PJLsession::print_selftest(): out of range" << endl;
-#endif _DEBUG
+#endif // _DEBUG
 		throw ExInvalid();
 	}
 
