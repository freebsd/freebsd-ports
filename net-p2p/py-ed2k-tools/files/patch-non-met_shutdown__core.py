--- non-met/shutdown_core.py.orig	2003-05-06 11:53:14 UTC
+++ non-met/shutdown_core.py
@@ -13,7 +13,7 @@ def make_login_packet( username, password ):
 	"""Create a authentication packet."""
 	# This looks like so:
 	#	<length of username: 16bit><username><length of password: 16 bit><password>
-	packet = struct.pack( "<BH%isH%is" % ( len( username ), len( password ) ), OP_LOGIN, len( username ), username, len( password ), password );
+	packet = struct.pack("<BH%isH%is" % (len(username), len(password)), OP_LOGIN, len(username), username.encode(), len(password), password.encode())
 	# Hss hss.
 	return packet;
 
@@ -25,7 +25,7 @@ def make_shutdown_packet( ):
 def make_connection( hostname, port = 4663 ):
 	"""Make a socket to the core."""
 	connection = socket.socket();
-	connection.connect( ( hostname, port ) );
+	connection.connect((hostname, int(port)))
 	return connection;
 
 def send_packet( connection, packet ):
@@ -35,7 +35,7 @@ def send_packet( connection, packet ):
 
 if __name__ == '__main__':
 	if len( sys.argv ) < 4:
-		print "usage: %s <host[:port]> <uname> <pass>" % sys.argv[ 0 ];
+		print("usage: %s <host[:port]> <uname> <pass>" % sys.argv[0])
 		sys.exit( -1 );
 	
 	# Split out the hostname if necessary.
