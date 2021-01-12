Emulate the behavior of the USG UXIX daylight variable implemented in glibc.
It is supposed to be 0 if the time zone does not have any daylight saving time
rules and non-zero if there is a time during the year when daylight saving
time applies. [1]

In FreeBSD, tzname[1] should be set to "   " (three spaces) if DST is never
observed. [2]

[1] https://www.gnu.org/software/libc/manual/html_node/Time-Zone-Functions.html#Time-Zone-Functions
[2] https://svnweb.freebsd.org/base/head/contrib/tzcode/stdtime/localtime.c?revision=313774&view=markup#l84

--- lib/FXSystemTime.cpp.orig	2020-11-28 04:52:31 UTC
+++ lib/FXSystemTime.cpp
@@ -278,6 +278,10 @@ FXTime FXSystem::daylightSavingsOffset(){
 #if defined(_WIN32)
   return minutes*tzi.DaylightBias;      // Or difference between standard and daylight bias.
 #else
+# if defined(__FreeBSD__)
+   tzset();
+   int daylight = ((tzname[1][0] == ' ') ? 0 : 1);
+# endif
   return -hours*daylight;
 #endif
   }
