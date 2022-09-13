--- libs/libmyth/audio/eldutils.cpp.orig	2022-08-13 16:59:56 UTC
+++ libs/libmyth/audio/eldutils.cpp
@@ -257,11 +257,11 @@ int eld::update_eld(const char *buf, int size)
     m_e.aud_synch_delay = GRAB_BITS(buf, 6, 0, 8) * 2;
     m_e.spk_alloc       = GRAB_BITS(buf, 7, 0, 7);
 
-    m_e.port_id         = qFromLittleEndian<uint64_t>(buf + 8);
+    m_e.port_id         = qFromLittleEndian<quint64>(buf + 8);
 
     /* not specified, but the spec's tendency is little endian */
-    m_e.manufacture_id  = qFromLittleEndian<uint16_t>(buf + 16);
-    m_e.product_id      = qFromLittleEndian<uint16_t>(buf + 18);
+    m_e.manufacture_id  = qFromLittleEndian<quint16>(buf + 16);
+    m_e.product_id      = qFromLittleEndian<quint16>(buf + 18);
 
     if (ELD_FIXED_BYTES + mnl > size)
     {
