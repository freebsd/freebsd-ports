./par2/par2fileformat.h:89:25: error: flexible array member 'entries' of non-POD element type 'FILEVERIFICATIONENTRY []'
  FILEVERIFICATIONENTRY entries[];

--- par2/par2fileformat.h.orig	2017-10-14 03:14:17 UTC
+++ par2/par2fileformat.h
@@ -86,7 +86,7 @@ struct FILEVERIFICATIONPACKET
   PACKET_HEADER         header;
   // Body
   MD5Hash               fileid;     // MD5hash of file_hash_16k, file_length, file_name
-  FILEVERIFICATIONENTRY entries[];
+  FILEVERIFICATIONENTRY entries[0];
 } PACKED;
 
 // The file description packet is used to record the name of the file,
