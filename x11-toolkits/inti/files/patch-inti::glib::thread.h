--- inti/glib/thread.h.orig	Sat Sep 18 21:08:25 2004
+++ inti/glib/thread.h	Sat Sep 18 21:09:00 2004
@@ -485,13 +485,13 @@
 
 	Private()
 	{
-		g_static_private_init(g_static_private());
+		g_static_private_init(this->g_static_private());
 	}
 	//!< Constructs and initializes a new private key.
 
 	~Private()
 	{
-		g_static_private_free(g_static_private());
+		g_static_private_free(this->g_static_private());
 	}
 	//!< Destructor. Frees the private key.
 
