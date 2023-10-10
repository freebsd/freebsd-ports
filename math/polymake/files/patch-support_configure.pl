--- support/configure.pl.orig	2023-09-02 05:23:02 UTC
+++ support/configure.pl
@@ -501,7 +501,7 @@ sub parse_command_line {
       }
    }
 
-   $CXXOPT   =$vars{CXXOPT}   // "-O3";
+   $CXXOPT   =$vars{CXXOPT}   // "";
    $CXXDEBUG =$vars{CXXDEBUG} // "-g";
    $CFLAGS   =$vars{CFLAGS}   // "";
    $CXXFLAGS =$vars{CXXFLAGS} // $CFLAGS;
