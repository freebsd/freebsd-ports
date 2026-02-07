--- spamass-milter.cpp
+++ spamass-milter.cpp
@@ -1206,7 +1206,23 @@ mlfi_header(SMFICTX* ctx, char* headerf,
     assassin->set_subject(headerv);
 
   // assemble header to be written to SpamAssassin
-  string header = string(headerf) + ": " + headerv + "\r\n";
+  string header = headerv;
+
+  // Replace all LF with CRLF
+  // As milter documentation says:
+  //     headerv    Header field value.  The content of the header may
+  //       include folded white space, i.e., multiple lines with following
+  //       white space where lines are separated by LF (not CR/LF).  The
+  //       trailing line terminator (CR/LF) is removed.
+  // Need to make sure folded header line breaks are sent to SA as CRLF
+  string::size_type idx = header.size();
+  while ( (idx = header.rfind("\n", idx)) != string::npos )
+  {
+     header.replace(idx,1,"\r\n");
+  }
+
+  // final assembly
+  header = string(headerf) + ": " + header + "\r\n";
  
   try {
     // write to SpamAssassin client
