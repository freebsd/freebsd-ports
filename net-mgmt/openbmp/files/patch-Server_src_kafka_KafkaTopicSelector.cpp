--- Server/src/kafka/KafkaTopicSelector.cpp.orig	2017-09-14 09:36:00 UTC
+++ Server/src/kafka/KafkaTopicSelector.cpp
@@ -8,6 +8,7 @@
  */
 
 #include <arpa/inet.h>
+#include <sys/socket.h>
 #include <boost/algorithm/string/replace.hpp>
 
 #include "KafkaTopicSelector.h"
@@ -439,4 +440,4 @@ void KafkaTopicSelector::freeTopicMap() {
             it->second = NULL;
         }
     }
-}
\ No newline at end of file
+}
