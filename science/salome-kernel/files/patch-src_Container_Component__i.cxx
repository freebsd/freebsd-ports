--- src/Container/Component_i.cxx.orig	2023-07-03 21:26:28 UTC
+++ src/Container/Component_i.cxx
@@ -401,14 +401,14 @@ bool Engines_Component_i::Kill_impl()
 
   bool RetVal = false ;
 #ifndef WIN32
-  if ( _ThreadId > 0 && pthread_self() != _ThreadId )
+  if ( _ThreadId && pthread_self() != _ThreadId )
     {
       RetVal = Killer( _ThreadId , SIGUSR2 ) ;
       _ThreadId = (pthread_t ) -1 ;
     }
 
 #else
-  if ( _ThreadId > 0 && pthread_self().p != _ThreadId->p )
+  if ( _ThreadId && pthread_self().p != _ThreadId->p )
     {
       RetVal = Killer( *_ThreadId , 0 ) ;
       _ThreadId = (pthread_t* ) 0 ;
@@ -443,13 +443,13 @@ bool Engines_Component_i::Stop_impl()
 
   bool RetVal = false ;
 #ifndef WIN32
-  if ( _ThreadId > 0 && pthread_self() != _ThreadId )
+  if ( _ThreadId && pthread_self() != _ThreadId )
     {
       RetVal = Killer( _ThreadId , 0 ) ;
       _ThreadId = (pthread_t ) -1 ;
     }
 #else
-  if ( _ThreadId > 0 && pthread_self().p != _ThreadId->p )
+  if ( _ThreadId && pthread_self().p != _ThreadId->p )
     {
       RetVal = Killer( *_ThreadId , 0 ) ;
       _ThreadId = (pthread_t* ) 0 ;
@@ -482,9 +482,9 @@ bool Engines_Component_i::Suspend_impl()
 
   bool RetVal = false ;
 #ifndef WIN32
-  if ( _ThreadId > 0 && pthread_self() != _ThreadId )
+  if ( _ThreadId && pthread_self() != _ThreadId )
 #else
-  if ( _ThreadId > 0 && pthread_self().p != _ThreadId->p )
+  if ( _ThreadId && pthread_self().p != _ThreadId->p )
 #endif
     {
       if ( _Sleeping )
@@ -528,9 +528,9 @@ bool Engines_Component_i::Resume_impl()
 #endif
   bool RetVal = false ;
 #ifndef WIN32
-  if ( _ThreadId > 0 && pthread_self() != _ThreadId )
+  if ( _ThreadId && pthread_self() != _ThreadId )
 #else
-  if ( _ThreadId > 0 && pthread_self().p != _ThreadId->p )
+  if ( _ThreadId && pthread_self().p != _ThreadId->p )
 #endif
     {
     if ( _Sleeping )
@@ -557,7 +557,7 @@ CORBA::Long Engines_Component_i::CpuUsed_impl()
   long cpu = 0 ;
   if ( _ThreadId || _Executed )
     {
-    if ( _ThreadId > 0 )
+    if ( _ThreadId )
       {
 #ifndef WIN32
       if ( pthread_self() != _ThreadId )
