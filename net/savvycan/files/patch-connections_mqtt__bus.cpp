--- connections/mqtt_bus.cpp.orig	2023-07-16 12:01:54 UTC
+++ connections/mqtt_bus.cpp
@@ -291,7 +291,7 @@ void MQTT_BUS::clientMessageReceived(const QMQTT::Mess
         uint32_t frameID = message.topic().split("/")[1].toInt();
 
         QByteArray timeStampBytes = message.payload().left(8);
-        uint64_t timeStamp = qFromLittleEndian<uint64_t>(timeStampBytes.data());
+        quint64 timeStamp = qFromLittleEndian<quint64>(timeStampBytes.data());
 
         int flags = message.payload()[8];
         frame_p->setPayload(message.payload().right(message.payload().count() - 9));
