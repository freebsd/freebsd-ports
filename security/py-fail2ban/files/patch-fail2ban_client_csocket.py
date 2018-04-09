--- fail2ban/client/csocket.py.orig	2018-04-08 10:28:39.135695000 +0200
+++ fail2ban/client/csocket.py	2018-04-08 10:35:39.403548000 +0200
@@ -43,7 +43,7 @@
 		self.__csock.connect(sock)
 
 	def __del__(self):
-		self.close(False)
+		self.close()
 	
 	def send(self, msg, nonblocking=False, timeout=None):
 		# Convert every list member to string
@@ -56,13 +56,18 @@
 	def settimeout(self, timeout):
 		self.__csock.settimeout(timeout if timeout != -1 else self.__deftout)
 
-	def close(self, sendEnd=True):
+	def close(self):
 		if not self.__csock:
 			return
-		if sendEnd:
+		try:
 			self.__csock.sendall(CSPROTO.CLOSE + CSPROTO.END)
-		self.__csock.shutdown(socket.SHUT_RDWR)
-		self.__csock.close()
+			self.__csock.shutdown(socket.SHUT_RDWR)
+		except socket.error: # pragma: no cover - normally unreachable
+			pass
+		try:
+			self.__csock.close()
+		except socket.error: # pragma: no cover - normally unreachable
+			pass
 		self.__csock = None
 	
 	@staticmethod
