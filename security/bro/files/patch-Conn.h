--- Conn.h.orig	Sun Aug 31 02:39:01 2003
+++ Conn.h	Thu Dec 21 13:27:24 2006
@@ -59,7 +59,7 @@
 	// dst_port just have to reflect the two different sides of the
 	// connection, neither has to be the particular source/destination
 	// or originator/responder.
-	HashKey* ConnID::BuildConnKey() const;
+	HashKey* BuildConnKey() const;
 };
 
 static inline int addr_port_canon_lt(const uint32* a1, uint32 p1,
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
 
