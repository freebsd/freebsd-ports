Index: client/analog/cx88_analog_driver.cpp
===================================================================
--- client/analog/cx88_analog_driver.cpp	(revision 562)
+++ client/analog/cx88_analog_driver.cpp	(working copy)
@@ -133,10 +133,6 @@
          error = m_pip_driver->start(slave_pip_params);
       }
    }
-   if (m_slave_mode)
-   {
-      wait_for_event(0);
-   }
    if (m_mode == CX88_ANALOG_MODE_VIDEO)
    {
       error = (error ? error : capture_video(params));
