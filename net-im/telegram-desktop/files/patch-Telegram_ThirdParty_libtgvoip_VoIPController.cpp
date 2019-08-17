--- Telegram/ThirdParty/libtgvoip/VoIPController.cpp.orig	2019-06-24 11:42:33 UTC
+++ Telegram/ThirdParty/libtgvoip/VoIPController.cpp
@@ -2389,8 +2389,8 @@ simpleAudioBlock random_id:long random_bytes:string ra
 					stm->decoder=NULL;
 				}else if(stm->type==STREAM_TYPE_VIDEO){
 					if(!stm->packetReassembler){
-						stm->packetReassembler=make_shared<PacketReassembler>();
-						stm->packetReassembler->SetCallback(bind(&VoIPController::ProcessIncomingVideoFrame, this, placeholders::_1, placeholders::_2, placeholders::_3));
+						//stm->packetReassembler=make_shared<PacketReassembler>();
+						//stm->packetReassembler->SetCallback(bind(&VoIPController::ProcessIncomingVideoFrame, this, placeholders::_1, placeholders::_2, placeholders::_3));
 					}
 				}else{
 					LOGW("Unknown incoming stream type: %d", stm->type);
@@ -3048,7 +3048,7 @@ static void initMachTimestart() {
 #endif
 
 double VoIPController::GetCurrentTime(){
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 	struct timespec ts;
 	clock_gettime(CLOCK_MONOTONIC, &ts);
 	return ts.tv_sec+(double)ts.tv_nsec/1000000000.0;
