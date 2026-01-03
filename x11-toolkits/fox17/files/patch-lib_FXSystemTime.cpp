Emulate the behavior of the USG UNIX 'daylight' and 'timezone' variables
where not implemented.

int daylight: Zero if the time zone does not have any daylight saving time
rules and non-zero if there is a time during the year when daylight saving
time applies. [1] On FreeBSD, tzname[1] should be set to "   " (three spaces)
if DST is never observed. [2]

long int timezone: contains the difference between UTC and the latest local
standard time, in seconds west of UTC. For example, in the U.S. Eastern time
zone, the value is 5*60*60. Unlike the tm_gmtoff member of the broken-down
time structure, this value is not adjusted for daylight saving, and its sign
is reversed. [1]

After [3], use the base implementations of 'daylight' and 'timezone'.

OpenBSD really shouldn't need this hack after 5.8, either. [4]

[1] https://www.gnu.org/software/libc/manual/html_node/Time-Zone-Functions.html#Time-Zone-Functions
[2] https://cgit.freebsd.org/src/tree/contrib/tzcode/stdtime/localtime.c?id=9436aa0e668b147c9a5bf1898ef091934c676434#n84
[3] https://cgit.freebsd.org/src/commit/?id=a34940a9756ac8edce36fec176949ee82e9235b4
[4] https://github.com/openbsd/src/commit/c9da469ac9133c60159589ec32d42d777401961c (official CVS is awful for the big picture)

--- lib/FXSystemTime.cpp.orig	2025-11-16 21:25:35 UTC
+++ lib/FXSystemTime.cpp
@@ -268,8 +268,11 @@ FXTime FXSystem::localTimeZoneOffset(){
   setuplocaltimezone();
 #if defined(WIN32)
   return minutes*tzi.Bias;              // +minutes*tzi.StandardBias;
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
-  return 0;     // FIXME
+#elif defined(__FreeBSD__) && __FreeBSD_version < 1500015
+  struct tm tmresult;
+  time_t tmp=time(&tmp);
+  struct tm* ptm=localtime_r(&tmp,&tmresult);
+  return seconds*(-ptm->tm_gmtoff + ptm->tm_isdst*3600);
 #else
   return seconds*timezone;
 #endif
@@ -281,8 +284,8 @@ FXTime FXSystem::daylightSavingsOffset(){
   setuplocaltimezone();
 #if defined(WIN32)
   return minutes*tzi.DaylightBias;      // Or difference between standard and daylight bias.
-#elif defined(__FreeBSD__) || defined(__OpenBSD__)
-  return 0;     // FIXME
+#elif defined(__FreeBSD__) && __FreeBSD_version < 1500015
+  return -hours*((tzname[1][0] == ' ') ? 0 : 1);
 #else
   return -hours*daylight;
 #endif
