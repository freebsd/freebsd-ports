--- include/easysoap/SOAPDispatchHandler.h.orig	Thu Jun 26 10:06:51 2003
+++ include/easysoap/SOAPDispatchHandler.h	Thu Jun 26 10:07:35 2003
@@ -56,7 +56,7 @@
 	bool ExecuteMethod(const SOAPEnvelope& request, SOAPMethod& response)
 	{
 		const SOAPMethod& method = request.GetBody().GetMethod();
-		DispatchMap::Iterator i = m_dispatchMap.Find(method.GetName());
+		typename DispatchMap::Iterator i = m_dispatchMap.Find(method.GetName());
 		if (i)
 		{
 			T *target= GetTarget(request);
@@ -100,7 +100,7 @@
 
 	bool HandleHeader(const SOAPParameter& header, SOAPEnvelope& request, SOAPEnvelope& response)
 	{
-		DispatchMap::Iterator i = m_dispatchMap.Find(header.GetName());
+		typename DispatchMap::Iterator i = m_dispatchMap.Find(header.GetName());
 
 		if (i)
 		{
