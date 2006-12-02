--- Exceptions.cpp.orig	Tue Mar 28 02:00:12 2000
+++ Exceptions.cpp	Fri Dec  1 22:24:08 2006
@@ -29,8 +29,8 @@
 
 ///////////////////////////////////////////////////////////////////////////////////
 
-Basic::Basic(	const string& location = "Unknown",
-				const string& condition = "Unknown"	)
+Basic::Basic(	const string& location,
+				const string& condition	)
 	: abort(false), loc( location ), cond( condition )	
 {
 }
@@ -65,8 +65,8 @@
 
 ////////////////////////////////////////////////////////////////////////////////////
 
-Fatal::Fatal( 	const string& location = "Unknown",
-				const string& condition = "Fatal Error"	)
+Fatal::Fatal( 	const string& location,
+				const string& condition	)
 	: Basic( location, condition )
 {
 }
@@ -81,7 +81,7 @@
 
 ////////////////////////////////////////////////////////////////////////////////////
 
-NullPointer::NullPointer( const string& location = "Unknown" )
+NullPointer::NullPointer( const string& location )
 	: Fatal( location, "Attempted to dereference or access a null pointer." )
 {}
 
@@ -94,8 +94,8 @@
 }
 
 ////////////////////////////////////////////////////////////////////////////////////
-FileAccess::FileAccess( const string& location = "Unknown",
-						const string& filename = "Filename Not Specified" )
+FileAccess::FileAccess( const string& location,
+						const string& filename )
 	: Basic( location, "File Not Found or Access Denied" ), fname( filename )
 {}
 
@@ -160,7 +160,7 @@
 ////////////////////////////////////////////////////////////////////////////////////
 
 TimeOut::TimeOut( 	const string& location, HtmlGenerator *htmlgen,
-					const string& pending_io = "(Err During Read)"	)
+					const string& pending_io	)
 		: Basic( location, "Socket I/O Timed Out" ), pend_io( pending_io ),
 		p_htgen( htmlgen )
 {}
