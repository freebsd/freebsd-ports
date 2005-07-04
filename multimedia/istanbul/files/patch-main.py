--- istanbul/main/main.py
+++ istanbul/main/main.py	2005-07-02 19:39:02.000000000 +0200
@@ -114,7 +114,7 @@
         mainpipeline = 'ximagesrc ! ffmpegcolorspace ! videoscale ! video/x-raw-yuv,width=%d,height=%d,framerate=%f' % (width, height, framerate)
 
         save_pipeline = ''
-        encode_pipeline = ''
+        encode_pipeline = 'theoraenc ! oggmux'
         icecast_pipeline = ''
 
         if self.settingsdialog.xml.get_widget('save').get_active():
@@ -122,7 +122,6 @@
                 encode_pipeline = 'smokeenc ! multipartmux'
                 filename = '%s.tmp' % self.settingsdialog.xml.get_widget('filenameEntry').get_text()
             else:
-                encode_pipeline = 'theoraenc ! oggmux'
                 filename = self.settingsdialog.xml.get_widget('filenameEntry').get_text()
 
             save_pipeline = 'filesink location=%s' % filename
@@ -130,6 +129,7 @@
             ip = self.settingsdialog.xml.get_widget('shout_ip').get_text()
             port = self.settingsdialog.xml.get_widget('shout_port').get_value_as_int()
             mountpoint = self.settingsdialog.xml.get_widget('shout_mount').get_text()
+            password = self.settingsdialog.xml.get_widget('shout_password').get_text()
             icecast_pipeline = 'shout2send ip=%s port=%s mount=%s password=%s' % (ip, port, mountpoint, password)
         if save_pipeline != '' and icecast_pipeline != '':
             final_pipeline = '%s ! %s ! tee name=t ! %s t. ! { queue ! %s }' % (mainpipeline, encode_pipeline, save_pipeline, icecast_pipeline)
