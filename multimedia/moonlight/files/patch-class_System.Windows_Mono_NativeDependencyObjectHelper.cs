
$FreeBSD$

--- class/System.Windows/Mono/NativeDependencyObjectHelper.cs.orig
+++ class/System.Windows/Mono/NativeDependencyObjectHelper.cs
@@ -177,7 +177,6 @@
 					throw new ExecutionEngineException ("multiple mappings registered for the same unmanaged peer");
 	#endif
 					Console.WriteLine ("multiple mappings registered for the same unmanaged peer 0x{0:x}, type = {1}", native, wrapper.GetType());
-					Console.WriteLine (Environment.StackTrace);
 					return false;
 				}
 				
@@ -229,7 +228,6 @@
 			INativeEventObjectWrapper wrapper = CreateObject (k, ptr) as INativeEventObjectWrapper;
 			if (wrapper == null){
 				Report.Warning ("System.Windows: Returning a null object, did not know how to construct {0}", k);
-				Report.Warning (Environment.StackTrace);
 			}
 
 			return wrapper;
