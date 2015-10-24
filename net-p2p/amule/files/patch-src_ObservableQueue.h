--- src/ObservableQueue.h.orig	2011-06-13 08:50:25 UTC
+++ src/ObservableQueue.h
@@ -331,14 +331,14 @@ CObservableQueue<ValueType>::~CObservabl
 template <typename ValueType>
 void CObservableQueue<ValueType>::ObserverAdded( ObserverType* o )
 {
-	NotifyObservers( EventType( EventType::STARTING ), o );
+	this->NotifyObservers( EventType( EventType::STARTING ), o );
 }
 
 
 template <typename ValueType>
 void CObservableQueue<ValueType>::ObserverRemoved( ObserverType* o )
 {
-	NotifyObservers( EventType( EventType::STOPPING ), o );
+	this->NotifyObservers( EventType( EventType::STOPPING ), o );
 }
 
 
