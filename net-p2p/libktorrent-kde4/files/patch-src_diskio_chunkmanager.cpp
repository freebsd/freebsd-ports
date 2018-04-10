error: case value evaluates to -1, which cannot be narrowed to type 'unsigned int'
    [-Wc++11-narrowing]
                                case -1:

--- src/diskio/chunkmanager.cpp.orig	2018-01-07 15:40:05 UTC
+++ src/diskio/chunkmanager.cpp
@@ -528,7 +528,7 @@ namespace bt
 					tf.setPriority(EXCLUDED);
 					break;
 				case ONLY_SEED_PRIORITY:
-				case -1:
+				case static_cast<Uint32>(-1):
 					tf.setPriority(ONLY_SEED_PRIORITY);
 					break;
 				default:
