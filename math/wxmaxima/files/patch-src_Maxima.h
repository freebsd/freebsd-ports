--- src/Maxima.h.orig	2025-10-22 20:10:06 UTC
+++ src/Maxima.h
@@ -123,6 +123,12 @@ class Maxima : public wxEvtHandler (private)
 private:
   //! If this is set to true by XmlInspectorActive we send all data we get to the XML inspector
   bool m_xmlInspector = false;
+  /*! Send still-unsent data to wxMaxima
+   *
+   *     \todo As we tell wxWidgets to send all data in one go at the end of a write command
+   *         there should no more be unsent data.
+   */
+  void SendDataTowxMaxima();
   //! The configuration of our wxMaxima process
   Configuration *m_configuration;
   //! The thread handler for SendDataTowxMaxima, the thread that parses the data from maxima.
@@ -152,6 +158,12 @@ class Maxima : public wxEvtHandler (private)
     waits for the other to exit before writing new data to this variable.
    */
   wxString m_socketInputData;
+  /*! Data we didn't manage to send to wxMaxima until now
+   *
+   *     \todo Do we still need this variable? We tell wxWidgets to send all data in
+   *         one go, so there should be no data be left at the end of a write command.
+   */
+  wxMemoryBuffer m_socketOutputData;
 
   //! true = Maxima still has to send us its first prompt
   bool m_firstPrompt = true;
