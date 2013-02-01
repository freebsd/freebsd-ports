--- src/ObservableQueue.h~
+++ src/ObservableQueue.h
@@ -331,7 +331,7 @@ CObservableQueue<ValueType>::~CObservabl
 template <typename ValueType>
 void CObservableQueue<ValueType>::ObserverAdded( ObserverType* o )
 {
-	NotifyObservers( EventType( EventType::STARTING ), o );
+	this->NotifyObservers( EventType( EventType::STARTING ), o );
 }
 
 
@@ -338,7 +338,7 @@ void CObservableQueue<ValueType>::Observ
 template <typename ValueType>
 void CObservableQueue<ValueType>::ObserverRemoved( ObserverType* o )
 {
-	NotifyObservers( EventType( EventType::STOPPING ), o );
+	this->NotifyObservers( EventType( EventType::STOPPING ), o );
 }
 
 
