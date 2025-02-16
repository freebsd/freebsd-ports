--- Telegram/SourceFiles/platform/linux/current_geo_location_linux.cpp.orig	2025-02-13 17:24:40 UTC
+++ Telegram/SourceFiles/platform/linux/current_geo_location_linux.cpp
@@ -118,7 +118,7 @@ void ResolveCurrentExactLocation(Fn<void(Core::GeoLoca
 				.accuracy = Core::GeoLocationAccuracy::Exact,
 			});
 		}),
-		new Fn(callback));
+		new std::function(callback));
 }
 
 void ResolveLocationAddress(
@@ -193,7 +193,7 @@ void ResolveLocationAddress(
 
 			(*callback)({ .name = checked.join(u", "_q) });
 		}),
-		new Fn(callback));
+		new std::function(callback));
 }
 
 } // namespace Platform
