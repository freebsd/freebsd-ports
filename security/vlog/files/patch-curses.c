--- curses.c.orig	Fri Feb  8 16:13:22 2002
+++ curses.c	Fri Aug 20 16:26:00 2004
@@ -221,31 +221,31 @@
   char * t;
   int    row;
 
-  sprintf(helpbuf, "
-    %s-%s (%s)
-    Logfile viewer for IP-Filter       ----- JUMP KEYS ---------------------    
-    %-32s     g   go to a given line
-                                         G   goto end or return to prev. pos
---------- MOVEMENT KEYS ------------     T   goto top
- arrows   move the window one line       0   scroll window to leftmost
- h,j,k,l  in either direction.         
- H,J,K,L  Caps move faster.             /,?  search a regexp forward/backward
- b,space  back, forward 1 page          n,N  goto next/previous occurence
-PgUp/Down these work on XFree only      >,<  goto next/previous day boundary
-                                        ],[  goto next/previous marked line
---------- MISC KEYS ----------------     
-    a     toggle AutoScroll mode        s,S  switch to another logfile
-    r     toggle raw/formatted  mode     &   display hostname/logfile
-    i     ip address display style       !   spawn a subshell
-    m     mark (reverse) bottom line   
-    M     clear all marks                
-   ^L     redraw screen
-%s
-    Q     quit
+  sprintf(helpbuf, "\n\
+    %s-%s (%s)\n\
+    Logfile viewer for IP-Filter       ----- JUMP KEYS ---------------------    \n\
+    %-32s     g   go to a given line\n\
+                                         G   goto end or return to prev. pos\n\
+--------- MOVEMENT KEYS ------------     T   goto top\n\
+ arrows   move the window one line       0   scroll window to leftmost\n\
+ h,j,k,l  in either direction.         \n\
+ H,J,K,L  Caps move faster.             /,?  search a regexp forward/backward\n\
+ b,space  back, forward 1 page          n,N  goto next/previous occurence\n\
+PgUp/Down these work on XFree only      >,<  goto next/previous day boundary\n\
+                                        ],[  goto next/previous marked line\n\
+--------- MISC KEYS ----------------     \n\
+    a     toggle AutoScroll mode        s,S  switch to another logfile\n\
+    r     toggle raw/formatted  mode     &   display hostname/logfile\n\
+    i     ip address display style       !   spawn a subshell\n\
+    m     mark (reverse) bottom line   \n\
+    M     clear all marks                \n\
+   ^L     redraw screen\n\
+%s\n\
+    Q     quit\n\
 ",
 MYNAME, VERSION, DATE, CREDIT,
   (mode_ipmon
-  ? "    o     toggle display options  (d=date, t=time, u=microsec, h=hostname,
+  ? "    o     toggle display options  (d=date, t=time, u=microsec, h=hostname,\n\
           f=intf, r=ipf rule numbers, i=isba rule numbers, l=ip header length)"
   : (mode_httpd_access
      ? "    o     toggle display options (d=date, t=time, c=client IP, u=user)"
@@ -1372,6 +1372,7 @@
 
     default:
       // fprintf(stderr, "-- KEY = 0x%x --", (int) c);
+      break;
     }
   }
 
