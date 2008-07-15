--- ./avidemux/ADM_libraries/ADM_lavformat/ADM_lavformat.cpp.orig	2008-07-05 15:51:54.000000000 +0200
+++ ./avidemux/ADM_libraries/ADM_lavformat/ADM_lavformat.cpp	2008-07-10 17:16:26.000000000 +0200
@@ -365,8 +365,10 @@
                                 break;
                         }
 		case  29970:
-			 c->time_base=fps30;
+		{
+			c->time_base=fps30;
 			break;
+		}
 		default:
                       {
                             if(_type==MUXER_MP4 || _type==MUXER_PSP || _type==MUXER_FLV || _type==MUXER_MATROSKA)
