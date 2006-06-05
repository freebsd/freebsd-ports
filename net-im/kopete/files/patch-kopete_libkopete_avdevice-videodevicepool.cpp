--- kopete/libkopete/avdevice/videodevicepool.cpp	2006/02/24 14:44:45	513116
+++ kopete/libkopete/avdevice/videodevicepool.cpp	2006/03/10 20:01:09	517367
@@ -683,7 +683,7 @@
 			const QString modelindex = QString::fromLocal8Bit ( "Model %1 Device %2")  .arg ((*vditerator).m_name ) .arg ((*vditerator).m_modelindex);
 			if(modelindex == currentdevice)
 			{
-				m_current_device = std::distance (m_videodevice.begin(), vditerator);
+				m_current_device = vditerator - m_videodevice.begin();
 //				kdDebug() << k_funcinfo << "This place will be used to set " << modelindex << " as the current device ( " << std::distance(m_videodevice.begin(), vditerator ) << " )." << endl;
 			}
 			const QString name                = config->readEntry((QString::fromLocal8Bit ( "Model %1 Device %2 Name")  .arg ((*vditerator).m_name ) .arg ((*vditerator).m_modelindex)), (*vditerator).m_model);
