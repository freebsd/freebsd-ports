--- Conn.h.orig	Sat Sep 18 15:42:16 2004
+++ Conn.h	Sat Sep 18 15:42:30 2004
@@ -223,6 +223,8 @@
 		return 1;
 		}
 
+	void DeleteTimer(double t);
+
 protected:
 	virtual void UpdateEndpointVal(RecordVal* endp, int is_orig) = 0;
 
@@ -235,8 +237,6 @@
 
 	friend class ConnectionTimer;
 	void RemoveTimer(Timer* t);
-
-	void DeleteTimer(double t);
 
 	void InactivityTimer(double t);
 
