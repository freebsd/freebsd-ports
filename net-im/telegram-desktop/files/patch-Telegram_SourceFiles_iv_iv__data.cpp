--- Telegram/SourceFiles/iv/iv_data.cpp.orig	2024-04-03 14:15:01 UTC
+++ Telegram/SourceFiles/iv/iv_data.cpp
@@ -25,7 +25,7 @@ QByteArray GeoPointId(Geo point) {
 	const auto lon = int(point.lon * 1000000);
 	const auto combined = (std::uint64_t(std::uint32_t(lat)) << 32)
 		| std::uint64_t(std::uint32_t(lon));
-	return QByteArray::number(combined)
+	return QByteArray::number(quint64(combined))
 		+ ','
 		+ QByteArray::number(point.access);
 }
