--- src/lastfm.cc.orig	2007-08-13 11:41:28.000000000 +0200
+++ src/lastfm.cc	2007-08-13 11:41:17.000000000 +0200
@@ -607,7 +607,7 @@
     Radio::get_xspf_playlist ()
     {
       XSPF::Playlist playlist;
-      std::string uri ((boost::format ("http://%s/%s/xspf.php?sk=%s&discovery=%d&desktop=1.3.0.58") 
+      std::string uri ((boost::format ("http://%s%s/xspf.php?sk=%s&discovery=%d&desktop=1.3.0.58") 
                         % m_session.base_url
                         % m_session.base_path 
                         % m_session.session 
@@ -618,6 +618,8 @@
 
       if (code == 401)
       {
+          m_connected = false;
+          signal_disconnected_.emit ();
           throw LastFMStreamTuningError (_( "Invalid Session, please re-handshake." ));
       }
     
@@ -1023,6 +1025,12 @@
     void
     Scrobbler::scrobble_request_run ()
     {
+      if (!Network::check_connected())
+      {
+        save_lqm (m_queue_filename);
+        return;
+      }
+
       static boost::format
         f_queue_head ("s=%s&");
       static boost::format
