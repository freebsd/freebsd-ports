--- src/db/main-db.cpp.orig	2026-03-21 15:38:51 UTC
+++ src/db/main-db.cpp
@@ -1884,11 +1884,14 @@ void MainDbPrivate::updateConferenceChatMessageEvent(c
 	if (state == ChatMessage::State::NotDelivered) {
 		const auto &meAddress = chatRoom->getMe()->getAddress();
 		long long meAddressId = insertSipAddress(meAddress);
+		// Materialize the IDs into local variables first
+		long long msgId = static_cast<long long>(chatMessage->getStorageId());
+		long long addrId = static_cast<long long>(meAddressId);
+
 		static const string query =
 		    "SELECT chat_message_participant.state FROM chat_message_participant WHERE event_id = :eventId AND "
 		    "chat_message_participant.participant_sip_address_id = :meAddressId";
-		soci::rowset<soci::row> rows =
-		    (session->prepare << query, soci::use(chatMessage->getStorageId()), soci::use(meAddressId));
+		soci::rowset<soci::row> rows = (session->prepare << query, soci::use(msgId), soci::use(addrId));
 		ChatMessage::State meParticipantState = ChatMessage::State::Idle;
 		for (const auto &row : rows) {
 			meParticipantState = static_cast<ChatMessage::State>(row.get<int>(0));
@@ -1911,7 +1914,8 @@ void MainDbPrivate::updateConferenceChatMessageEvent(c
 		                            " FROM sip_address, chat_message_participant"
 		                            " WHERE event_id = :eventId"
 		                            " AND sip_address.id = chat_message_participant.participant_sip_address_id";
-		soci::rowset<soci::row> rows = (session->prepare << query, soci::use(chatMessage->getStorageId()));
+		long long msgStorageId = static_cast<long long>(chatMessage->getStorageId());
+		soci::rowset<soci::row> rows = (session->prepare << query, soci::use(msgStorageId));
 
 		// Use list of participants the client is sure have received the message and not the actual list of participants
 		// being part of the chatroom
@@ -5068,10 +5072,11 @@ list<shared_ptr<ChatMessage>> MainDb::getEphemeralMess
 		L_D();
 		list<shared_ptr<ChatMessage>> chatMessages;
 		auto epoch = d->dbSession.getTimeWithSociIndicator(0);
+		int maxTasks = EPHEMERAL_MESSAGE_TASKS_MAX_NB;
 		soci::rowset<soci::row> rows =
 		    getBackend() == MainDb::Backend::Sqlite3
 		        ? (d->dbSession.getBackendSession()->prepare << query, soci::use(epoch.first),
-		           soci::use(EPHEMERAL_MESSAGE_TASKS_MAX_NB))
+		           soci::use(maxTasks))
 		        : (d->dbSession.getBackendSession()->prepare << query, soci::use(epoch.first));
 		for (const auto &row : rows) {
 			const long long &dbChatRoomId = d->dbSession.resolveId(row, (int)row.size() - 1);
@@ -5866,9 +5871,11 @@ list<shared_ptr<EventLog>> MainDb::getHistoryRangeNear
 			const EventLogPrivate *dEventLog = event->getPrivate();
 			MainDbKeyPrivate *dEventKey = static_cast<MainDbKey &>(dEventLog->dbKey).getPrivate();
 			const long long &dbEventId = dEventKey->storageId;
+			long long beforePlusOne = static_cast<long long>(before + 1);
+			long long afterPlusOne = static_cast<long long>(after + 1);
 
 			soci::rowset<soci::row> rows = (d->dbSession.getBackendSession()->prepare << query, soci::use(dbChatRoomId),
-			                                soci::use(dbEventId), soci::use(before + 1), soci::use(after + 1));
+			                                soci::use(dbEventId), soci::use(beforePlusOne), soci::use(afterPlusOne));
 
 			for (const auto &row : rows) {
 				shared_ptr<EventLog> event = d->selectGenericConferenceEvent(chatRoom, row);
