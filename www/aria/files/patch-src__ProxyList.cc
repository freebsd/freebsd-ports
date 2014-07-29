--- src/ProxyList.cc.orig	Sun Nov  4 19:18:08 2001
+++ src/ProxyList.cc	Thu Apr  8 22:41:14 2004
@@ -130,12 +130,12 @@
 bool ProxyList::Read_proxy_list(const string& file_proxy_list)
 {
   ifstream infile(file_proxy_list.c_str(), ios::in);//ios::skipws|ios::in);
-  if(infile.bad() || infile.eof()) return false;
+  if(!infile.is_open() || infile.bad() || infile.eof()) return false;
 
   while(!infile.eof()) {
     string line;
     getline(infile, line, '\n');
-    if(infile.bad()) return false;
+    if(!infile.is_open() || infile.bad()) return false;
     line = Remove_white(line);
     if(line.empty() || line.at(0) == '#') continue;
     string server_name = Token_splitter(line, ": \t");
