--- ed2k_metutils.py.orig	2003-05-06 11:53:14 UTC
+++ ed2k_metutils.py
@@ -6,24 +6,24 @@
 #      tested on macosx 10.2.4, python 2.2
 
 import struct;
-import types;
 import sys;
 
 # Some defines.
 
 TAG_TYPE_STRING  = 2;
 TAG_TYPE_INTEGER = 3;
+TAG_TYPE_BLOB = 7
 
-TAG_HANDLE_FILENAME   = chr( 1 );
-TAG_HANDLE_FILESIZE   = chr( 2 );
-TAG_HANDLE_FILETYPE   = chr( 3 );
-TAG_HANDLE_FILEFORMAT = chr( 4 );
-TAG_HANDLE_SOFAR      = chr( 8 );
-TAG_HANDLE_GAP_START  = chr( 9 );
-TAG_HANDLE_GAP_END    = chr( 10 );
-TAG_HANDLE_TEMP_NAME  = chr( 18 );
-TAG_HANDLE_PAUSED     = chr( 20 );
-TAG_HANDLE_PRIORITY   = chr( 24 );
+TAG_HANDLE_FILENAME   = b'\x01'
+TAG_HANDLE_FILESIZE   = b'\x02'
+TAG_HANDLE_FILETYPE   = b'\x03'
+TAG_HANDLE_FILEFORMAT = b'\x04'
+TAG_HANDLE_SOFAR      = b'\x08'
+TAG_HANDLE_GAP_START  = b'\x09'
+TAG_HANDLE_GAP_END    = b'\x0a'
+TAG_HANDLE_TEMP_NAME  = b'\x12'
+TAG_HANDLE_PAUSED     = b'\x14'
+TAG_HANDLE_PRIORITY   = b'\x18'
 
 class MetFile:
 	"""Class designed to hold the data of a .part.met file."""
@@ -39,7 +39,7 @@ class MetFile:
 			# a .part file must exist, even if it's empty.  The same doesn't apply for new overnet.
 			self.version = 225;
 			self.modDate = 0;
-			self.fileID = '\0' * 16; 
+			self.fileID = b'\0' * 16
 			return;
 			
 		header_struct = "<BI16sH";
@@ -58,7 +58,7 @@ class MetFile:
 		dstore = dstore[ 4 : ];
 		
 		for meta in range( n_meta ):
-			t_type, = struct.unpack( "<B", dstore[ 0 ] );
+			t_type, = struct.unpack("<B", dstore[0:1])
 			dstore = dstore[ 1 : ];
 			
 			name_len, = struct.unpack( "<H", dstore[ : 2 ] );
@@ -69,11 +69,16 @@ class MetFile:
 			if t_type == TAG_TYPE_INTEGER:
 				value, = struct.unpack( "<I", dstore[ : 4 ] );
 				dstore = dstore[ 4 : ];
-			else:
+			elif t_type == TAG_TYPE_STRING:
 				value_len, = struct.unpack( "<H", dstore[ : 2 ] );
 				dstore = dstore[ 2 : ];
 				value, = struct.unpack( "<%is" % value_len, dstore[ : value_len ] );
 				dstore = dstore[ value_len : ];
+			elif t_type == TAG_TYPE_BLOB:
+				blen, = struct.unpack("<I", dstore[:4])
+				# XXX: for now, just skip (ignore) the payload
+				dstore = dstore[4 + blen:]
+				continue
 			
 			self.AddTag( MetaTag( name, value, t_type ) );
 			
@@ -81,14 +86,14 @@ class MetFile:
 		"""Return a string representation of the file MD4."""
 		data = "";
 		for i in range( len( self.fileID )  ):
-			data += "%02x" % ord( self.fileID[ i ] );
+			data += "%02x" % self.fileID[i]
 		return data.upper();
 	
 	def getEd2K( self ):
 		"""Return the ed2k:// link associated with this met file."""
 		size = self.FindTags( TAG_HANDLE_FILESIZE )[ 0 ].value;
 		name = self.FindTags( TAG_HANDLE_FILENAME )[ 0 ].value;
-		return "ed2k://|file|%s|%s|%s|" % ( name, size, self.getMD4() );
+		return "ed2k://|file|%s|%s|%s|" % (name.decode(), size, self.getMD4())
 		
 	def ReduceToData( self ):
 		"""Reduce a class instance back into a stream suitable for writing to disk."""
@@ -109,13 +114,13 @@ class MetFile:
 		"""Return an array of tags matching the supplied handle.
 		   Tags relating to gaps do no obey the usual 'special tag' 
 		   semantics, so set the flag to 1 if you are dealing with them."""
-		if gaptags: return [ x for x in self.m_tags if x.name[ 0 ] == tagHandle ];
+		if gaptags: return [ x for x in self.m_tags if x.name[0:1] == tagHandle ]
 		else: return [ x for x in self.m_tags if x.name == tagHandle ];
 			
 	def PurgeTags( self, tagHandle, gaptags = 0 ):
 		"""This is the same as FindTags, except it removes the 
 		   matching tags from the meta-tag store."""
-		if gaptags: self.m_tags = [ x for x in self.m_tags if x.name[ 0 ] != tagHandle ];
+		if gaptags: self.m_tags = [ x for x in self.m_tags if x.name[0:1] != tagHandle ]
 		else: self.m_tags = [ x for x in self.m_tags if x.name != tagHandle ];
 		
 class MetaTag:
@@ -127,7 +132,7 @@ class MetaTag:
 		self.value = value;
 		if t_type == None:
 			# Rudiments of Autodetection...
-			if type( value ) == types.IntType:
+			if isinstance(value, int):
 				self.tag_type = TAG_TYPE_INTEGER;
 			else:
 				self.tag_type = TAG_TYPE_STRING;
