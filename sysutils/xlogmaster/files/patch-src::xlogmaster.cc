--- src/xlogmaster.cc.orig	Thu Apr  1 01:00:29 1999
+++ src/xlogmaster.cc	Thu Feb  5 22:09:28 2004
@@ -41,6 +41,8 @@
 
 #include "../graphics/logo.xpm"
 #include "../graphics/logo_small.xpm"
+#include <iostream>
+using namespace std;
 
 /*}}}*/
 
@@ -996,7 +998,7 @@
  int gtkrc = FALSE;
  terse = FALSE;
  
- x = getopt_long_only(argc, argv, "", options, &opt_index);
+ x = getopt_long(argc, argv, "", options, &opt_index);
  while ( x != -1 && x != '?' ){
    const gchar* opt = options[opt_index].name;
    
@@ -1183,7 +1185,7 @@
 	 }
      }
    
-   x = getopt_long_only(argc, argv, "", options, &opt_index);
+   x = getopt_long(argc, argv, "", options, &opt_index);
  };
  
  if ( optind < argc || x == '?' )
