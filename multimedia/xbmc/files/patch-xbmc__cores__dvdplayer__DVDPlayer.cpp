--- ./xbmc/cores/dvdplayer/DVDPlayer.cpp.orig	2010-10-27 19:02:14.000000000 +0200
+++ ./xbmc/cores/dvdplayer/DVDPlayer.cpp	2010-12-01 12:17:34.204563658 +0100
@@ -2868,7 +2868,7 @@
           m_dvd.state = DVDSTATE_STILL;
           CLog::Log(LOGDEBUG,
                     "DVDNAV_STILL_FRAME - waiting %i sec, with delay of %d sec",
-                    still_event->length, time / 1000);
+                    still_event->length, (int)(time / 1000));
         }
         return NAVRESULT_HOLD;
       }
