--- src/JackPlaybackCore.cxx.orig	Fri Oct  5 01:19:48 2007
+++ src/JackPlaybackCore.cxx	Fri Oct  5 01:20:24 2007
@@ -291,7 +291,7 @@
 		 * possibly resulting in a backwards seek.
 		 */
 		int spin = 1000000;
-		while (abs(jack_poll_frame()-m_currentFrame) > 2 && spin-- > 0 );
+		while (::llabs(jack_poll_frame()-m_currentFrame) > 2 && spin-- > 0 );
 	}
 	if (g_use_jack_transport) jack_play();
 
