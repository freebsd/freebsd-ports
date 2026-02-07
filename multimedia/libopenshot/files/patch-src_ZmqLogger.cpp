--- src/ZmqLogger.cpp.orig	2024-06-20 01:25:10 UTC
+++ src/ZmqLogger.cpp
@@ -44,7 +44,7 @@ ZmqLogger *ZmqLogger::Instance()
 		m_pInstance->connection = "";
 
 		// Default connection
-		m_pInstance->Connection("tcp://*:5556");
+		m_pInstance->Connection("tcp://localhost:5556");
 
 		// Init enabled to False (force user to call Enable())
 		m_pInstance->enabled = false;
@@ -92,7 +92,7 @@ void ZmqLogger::Connection(std::string new_connection)
 
 	} catch (zmq::error_t &e) {
 		std::cout << "ZmqLogger::Connection - Error binding to " << connection << ". Switching to an available port." << std::endl;
-		connection = "tcp://*:*";
+		connection = "tcp://localhost:*";
 		publisher->bind(connection.c_str());
 	}
 
