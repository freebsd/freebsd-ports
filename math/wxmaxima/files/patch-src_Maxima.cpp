--- src/Maxima.cpp.orig	2025-10-22 20:06:30 UTC
+++ src/Maxima.cpp
@@ -115,8 +115,18 @@ Maxima::~Maxima() {
   wxEvtHandler::DeletePendingEvents();
 }
 
+
+// revert https://github.com/wxMaxima-developers/wxmaxima/commit/5d8dff1564c4d8e0d07e6fdb262b476cad0cb643
+// as per https://github.com/wxMaxima-developers/wxmaxima/issues/2028
+// NOTE: this is temporary solution until wx 3.3.2
 bool Maxima::Write(const void *buffer, std::size_t length) {
-  if(!buffer)
+ if (!m_socketOutputData.IsEmpty()) {
+    if (buffer && length)
+      m_socketOutputData.AppendData(buffer, length);
+    buffer = m_socketOutputData.GetData();
+    length = m_socketOutputData.GetDataLen();
+  }
+  if (!length)
     return false;
   if (length == 0)
     return false;
@@ -125,8 +135,21 @@ bool Maxima::Write(const void *buffer, std::size_t len
     wxThreadEvent *sendevent = new wxThreadEvent(EVT_MAXIMA);
     sendevent->SetInt(WRITE_ERROR);
     QueueEvent(sendevent);
-    return false;
+    m_socketOutputData.Clear();
+    return true;
   }
+  auto const wrote = m_socket->LastWriteCount();
+  if (wrote < length) {
+    auto *const source = reinterpret_cast<const char *>(buffer);
+    auto const leftToWrite = length - wrote;
+    if (m_socketOutputData.IsEmpty())
+      m_socketOutputData.AppendData(source + wrote, leftToWrite);
+    else {
+      memmove(m_socketOutputData.GetData(), source + wrote, leftToWrite);
+      m_socketOutputData.SetDataLen(leftToWrite);
+    }
+  } else
+    m_socketOutputData.Clear();
   return true;
 }
 
