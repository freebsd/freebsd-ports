diff -ur steghide-0.5.1-orig/src/AuData.h steghide-0.5.1/src/AuData.h
--- steghide-0.5.1-orig/src/AuData.h	2006-03-10 02:17:19.000000000 -0500
+++ src/AuData.h	2006-03-10 02:19:01.000000000 -0500
@@ -26,22 +26,30 @@
 
 // AuMuLawAudioData
 typedef AudioDataImpl<AuMuLaw,BYTE> AuMuLawAudioData ;
+template<>
 inline BYTE AuMuLawAudioData::readValue (BinaryIO* io) const { return (io->read8()) ; }
+template<>
 inline void AuMuLawAudioData::writeValue (BinaryIO* io, BYTE v) const { io->write8(v) ; }
 
 // AuPCM8AudioData
 typedef AudioDataImpl<AuPCM8,SBYTE> AuPCM8AudioData ;
+template<>
 inline SBYTE AuPCM8AudioData::readValue (BinaryIO* io) const { return ((SBYTE) io->read8()) ; }
+template<>
 inline void AuPCM8AudioData::writeValue (BinaryIO* io, SBYTE v) const { io->write8((BYTE) v) ; }
 
 // AuPCM16AudioData
 typedef AudioDataImpl<AuPCM16,SWORD16> AuPCM16AudioData ;
+template<>
 inline SWORD16 AuPCM16AudioData::readValue (BinaryIO* io) const { return ((SWORD16) io->read16_be()) ; }
+template<>
 inline void AuPCM16AudioData::writeValue (BinaryIO* io, SWORD16 v) const { io->write16_be((UWORD16) v) ; }
 
 // AuPCM32AudioData
 typedef AudioDataImpl<AuPCM32,SWORD32> AuPCM32AudioData ;
+template<>
 inline SWORD32 AuPCM32AudioData::readValue (BinaryIO* io) const { return ((SWORD32) io->read32_be()) ; }
+template<>
 inline void AuPCM32AudioData::writeValue (BinaryIO* io, SWORD32 v) const { io->write32_be((UWORD32) v) ; }
 
 #endif // ndef SH_AUDATA_H
