--- kmix/mixer_oss.cpp	Fri Sep 14 18:02:58 2007
+++ kmix/mixer_oss.cpp	Fri Sep 14 19:45:27 2007
@@ -243,6 +243,18 @@
   if (ioctl(m_fd, SOUND_MIXER_READ_RECSRC, &i_recsrc) == -1)
     errormsg(Mixer::ERR_READ);
 
+  // If the record source is supposed to be on, but wasn't set, explicitly
+  // set the record source. Not all cards support multiple record sources.
+  // As a result, we also need to do the read & write again.
+  if (((i_recsrc & ( 1<<devnum)) == 0) && on)
+  {
+     oldrecsrc = i_recsrc = 1 << devnum;
+     if (ioctl(m_fd, SOUND_MIXER_WRITE_RECSRC, &i_recsrc) == -1)
+       errormsg (Mixer::ERR_WRITE);
+     if (ioctl(m_fd, SOUND_MIXER_READ_RECSRC, &i_recsrc) == -1)
+       errormsg(Mixer::ERR_READ);
+  }
+
   // PORTING: Hint: Do not forget to set i_recsrc to the new valid
   //                record source mask.
 
