--- ./libs/libmythupnp/eventing.h	(revision 23038)
+++ ./libs/libmythupnp/eventing.h	(revision 26434)
@@ -174,4 +174,9 @@
 //////////////////////////////////////////////////////////////////////////////
 
+template<typename T>
+inline T state_var_init(const T*) { return (T)(0); }
+template<>
+inline QString state_var_init(const QString*) { return QString(); }
+
 class UPNP_PUBLIC StateVariables
 {   
@@ -232,7 +237,8 @@
         T GetValue( const QString &sName )
         {
+            T *dummy = NULL;
             SVMap::iterator it = m_map.find(sName);
             if (it == m_map.end())
-                return T(0);
+                return state_var_init(dummy);
 
             StateVariable< T > *pVariable =
@@ -242,5 +248,5 @@
                 return pVariable->GetValue();
 
-            return T(0);
+            return state_var_init(dummy);
         }
 
