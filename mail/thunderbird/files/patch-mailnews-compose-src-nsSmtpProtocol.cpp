--- mailnews/compose/src/nsSmtpProtocol.cpp~
+++ mailnews/compose/src/nsSmtpProtocol.cpp
@@ -127,16 +127,16 @@ nsresult nsExplainErrorDetails(nsISmtpUr
 
   switch (code)
   {
-      case NS_ERROR_SMTP_SERVER_ERROR:
-      case NS_ERROR_TCP_READ_ERROR:
-      case NS_ERROR_SMTP_TEMP_SIZE_EXCEEDED:
-      case NS_ERROR_SMTP_PERM_SIZE_EXCEEDED_1:
-      case NS_ERROR_SMTP_PERM_SIZE_EXCEEDED_2:
-      case NS_ERROR_SENDING_FROM_COMMAND:
-      case NS_ERROR_SENDING_RCPT_COMMAND:
-      case NS_ERROR_SENDING_DATA_COMMAND:
-      case NS_ERROR_SENDING_MESSAGE:
-      case NS_ERROR_SMTP_GREETING:
+      case (int)NS_ERROR_SMTP_SERVER_ERROR:
+      case (int)NS_ERROR_TCP_READ_ERROR:
+      case (int)NS_ERROR_SMTP_TEMP_SIZE_EXCEEDED:
+      case (int)NS_ERROR_SMTP_PERM_SIZE_EXCEEDED_1:
+      case (int)NS_ERROR_SMTP_PERM_SIZE_EXCEEDED_2:
+      case (int)NS_ERROR_SENDING_FROM_COMMAND:
+      case (int)NS_ERROR_SENDING_RCPT_COMMAND:
+      case (int)NS_ERROR_SENDING_DATA_COMMAND:
+      case (int)NS_ERROR_SENDING_MESSAGE:
+      case (int)NS_ERROR_SMTP_GREETING:
          bundle->GetStringFromID(NS_ERROR_GET_CODE(code), getter_Copies(eMsg));
          msg = nsTextFormatter::vsmprintf(eMsg.get(), args);
          break;
