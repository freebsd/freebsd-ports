--- src/audio_player_alsa.cpp.orig
+++ src/audio_player_alsa.cpp
@@ -192,7 +192,7 @@
 
 	snd_pcm_t *pcm = 0;
 	if (snd_pcm_open(&pcm, ps.device_name.c_str(), SND_PCM_STREAM_PLAYBACK, 0) != 0)
-		return "snd_pcm_open";
+		return (void*)"snd_pcm_open";
 	//printf("alsa_player: opened pcm\n");
 
 do_setup:
@@ -209,7 +209,7 @@
 		break;
 	default:
 		snd_pcm_close(pcm);
-		return "snd_pcm_format_t";
+		return (void*)"snd_pcm_format_t";
 	}
 	if (snd_pcm_set_params(pcm,
 	                       pcm_format,
@@ -219,7 +219,7 @@
 	                       1, // allow resample
 	                       100*1000 // 100 milliseconds latency
 	                      ) != 0)
-		return "snd_pcm_set_params";
+		return (void*)"snd_pcm_set_params";
 	//printf("alsa_player: set pcm params\n");
 
 	size_t framesize = ps.provider->GetChannels() * ps.provider->GetBytesPerSample();
@@ -261,7 +261,7 @@
 				delete[] buf;
 				snd_pcm_close(pcm);
 				//printf("alsa_player: error filling buffer\n");
-				return "snd_pcm_writei";
+				return (void*)"snd_pcm_writei";
 			}
 		}
 		delete[] buf;
@@ -319,7 +319,7 @@
 					delete[] buf;
 					snd_pcm_close(pcm);
 					//printf("alsa_player: error filling buffer, written=%d\n", written);
-					return "snd_pcm_writei";
+					return (void*)"snd_pcm_writei";
 				}
 			}
 			delete[] buf;
@@ -353,7 +353,7 @@
 		case SND_PCM_STATE_DISCONNECTED:
 			// lost device, close the handle and return error
 			snd_pcm_close(pcm);
-			return "SND_PCM_STATE_DISCONNECTED";
+			return (void*)"SND_PCM_STATE_DISCONNECTED";
 
 		default:
 			// everything else should either be fine or impossible (here)
