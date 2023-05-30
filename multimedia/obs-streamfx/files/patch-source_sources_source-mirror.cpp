--- source/sources/source-mirror.cpp.orig	2023-05-29 23:51:47 UTC
+++ source/sources/source-mirror.cpp
@@ -116,7 +116,8 @@ void mirror_instance::migrate(obs_data_t* data, uint64
 	case 0:
 		obs_data_set_int(data, ST_KEY_SOURCE_AUDIO_LAYOUT, obs_data_get_int(data, "Source.Mirror.Audio.Layout"));
 		obs_data_unset_user_value(data, "Source.Mirror.Audio.Layout");
-	case STREAMFX_VERSION:
+	//case STREAMFX_VERSION:
+	default: // STREAMFX_VERSION is 0 so the above breaks the compiler, and upstream doesn't accept issues
 		break;
 	}
 }
