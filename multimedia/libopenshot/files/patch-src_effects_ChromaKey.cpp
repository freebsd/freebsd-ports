--- src/effects/ChromaKey.cpp.orig	2026-04-02 23:34:37 UTC
+++ src/effects/ChromaKey.cpp
@@ -167,6 +167,7 @@ std::shared_ptr<openshot::Frame> ChromaKey::GetFrame(s
 
 		case CHROMAKEY_BASIC:
 			break;
+		default: ;
 		}
 
 		pixelbuf.resize(rowwidth * height);
@@ -504,6 +505,7 @@ std::shared_ptr<openshot::Frame> ChromaKey::GetFrame(s
 					}
 				}
 				break;
+			default: ;
 			}
 
 			return frame;
