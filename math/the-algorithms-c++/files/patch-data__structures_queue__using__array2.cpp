- workaround for https://github.com/TheAlgorithms/C-Plus-Plus/issues/2690

--- data_structures/queue_using_array2.cpp.orig	2024-04-15 23:52:35 UTC
+++ data_structures/queue_using_array2.cpp
@@ -1,6 +1,8 @@ using namespace std;
 #include <iostream>
 using namespace std;
 
+#define queue queue_
+
 int queue[10];
 int front = 0;
 int rear = 0;
