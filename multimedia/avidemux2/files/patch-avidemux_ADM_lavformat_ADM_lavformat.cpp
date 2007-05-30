--- avidemux/ADM_lavformat/ADM_lavformat.cpp.orig	Mon May 28 10:32:13 2007
+++ avidemux/ADM_lavformat/ADM_lavformat.cpp	Mon May 28 10:33:09 2007
@@ -260,10 +260,12 @@
     	switch(_fps1000)
 	{
 		case 25000:
+		{
 			 c->time_base= (AVRational){1001,25025};
 			//c->frame_rate = 25025;  
 			//c->frame_rate_base = 1001;	
 			break;
+		}
 		case 23976:
 /*
 			c->frame_rate = 24000;  
@@ -276,10 +278,12 @@
                                 break;
                         }
 		case  29970:
+		{
 			 c->time_base= (AVRational){1001,30000};
 			//c->frame_rate = 30000;  
 			//c->frame_rate_base = 1001;	
 			break;
+		}
 		default:
                         if(_type==MUXER_MP4 || _type==MUXER_PSP)
                         {
