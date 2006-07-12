--- src/option_parser.cc.orig	Wed Jul 12 10:31:59 2006
+++ src/option_parser.cc	Wed Jul 12 10:32:15 2006
@@ -77,9 +77,6 @@
   int c;
   std::string optString = create_optstring();
 
-  optind = 0;
-  opterr = 0;
-
   while ((c = getopt(argc, argv, optString.c_str())) != -1)
     if (c == '?')
       throw std::runtime_error("Invalid/unknown option flag \"-" + std::string(1, (char)optopt) + "\". See rtorrent -h for more information.");
