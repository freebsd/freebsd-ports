Index: libkdenetwork/kmime_util.cpp
===================================================================
RCS file: /home/kde/kdenetwork/libkdenetwork/Attic/kmime_util.cpp,v
retrieving revision 1.16.2.1
diff -u -5 -p -d -r1.16.2.1 kmime_util.cpp
--- libkdenetwork/kmime_util.cpp	13 Dec 2002 09:31:38 -0000	1.16.2.1
+++ libkdenetwork/kmime_util.cpp	25 Jun 2003 19:42:06 -0000
@@ -646,17 +646,13 @@ DateFormatter::zone(time_t otime) const
   int secs = abs( local->tm_gmtoff );
   int neg  = (local->tm_gmtoff<0)?1:0; //no, I don't know why it's backwards :o
   int hours = secs/3600;
   int mins  = (secs - hours*3600)/60;
 
-  if ( local->tm_isdst > 0 ) {
+  if ( local->tm_isdst > 0 )
       mDaylight = 1;
-      if ( neg )
-        --hours;
-      else
-        ++hours;
-  } else
+  else
       mDaylight = 0;
 
   ret.sprintf("%c%.2d%.2d",(neg)?'-':'+', hours, mins);
 
 #else
