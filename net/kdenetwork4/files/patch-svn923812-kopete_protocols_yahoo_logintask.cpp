--- ../kopete/protocols/yahoo/libkyahoo/logintask.cpp	2009/01/06 17:13:38	906699
+++ ../kopete/protocols/yahoo/libkyahoo/logintask.cpp	2009/02/09 14:00:12	923817
@@ -66,6 +66,12 @@
 
 	YMSGTransfer *t = static_cast<YMSGTransfer *>(transfer);
 
+
+	if ( t->service() == Yahoo::ServicePing) {
+		emit buddyListReady();
+		return true;
+	}
+
 	switch (mState)
 	{
 		case (InitialState):
@@ -99,6 +105,9 @@
 	if (!t)
 		return false;
 
+	if ( t->service() == Yahoo::ServicePing)
+		return true;
+
 	switch (mState)
 	{
 		case (InitialState):
