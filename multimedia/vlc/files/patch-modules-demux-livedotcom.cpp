--- modules/demux/livedotcom.cpp.orig	Thu Jul 22 01:54:30 2004
+++ modules/demux/livedotcom.cpp	Thu Jul 22 01:58:50 2004
@@ -39,6 +39,12 @@
 #include "GroupsockHelper.hh"
 #include "liveMedia.hh"
 
+#if (LIVEMEDIA_LIBRARY_VERSION_INT < 1089936000)
+#define RECLAIM_ENV(env) delete (env)
+#else
+#define RECLAIM_ENV(env) (env)->reclaim()
+#endif
+
 using namespace std;
 
 /*****************************************************************************
@@ -132,8 +138,7 @@
         }
         if( ( rtsp = RTSPClient::createNew(*env, 1/*verbose*/, "VLC Media Player" ) ) == NULL )
         {
-            delete env;
-            delete scheduler;
+            env->reclaim(); delete scheduler;
             msg_Err( p_input, "RTSPClient::createNew failed" );
             return VLC_EGENERIC;
         }
@@ -149,8 +154,7 @@
             msg_Err( p_input, "describeURL failed (%s)", env->getResultMsg() );
 
             free( psz_url );
-            delete env;
-            delete scheduler;
+            env->reclaim(); delete scheduler; 
             free( p_sys );
             return VLC_EGENERIC;
         }
@@ -160,8 +164,7 @@
 
         //fprintf( stderr, "sdp=%s\n", p_sys->p_sdp );
 
-        delete env;
-        delete scheduler;
+        env->reclaim(); delete scheduler;
 
         var_Create( p_input, "rtsp-tcp", VLC_VAR_BOOL|VLC_VAR_DOINHERIT );
         var_Get( p_input, "rtsp-tcp", &val );
@@ -670,11 +673,11 @@
     }
     if( p_sys->env )
     {
-        delete p_sys->env;
+        RECLAIM_ENV(p_sys->env);
     }
     if( p_sys->scheduler )
     {
-        delete p_sys->scheduler;
+       RECLAIM_ENV(p_sys->env);
     }
     if( p_sys->p_sdp )
     {
@@ -724,11 +727,11 @@
 
     if( p_sys->env )
     {
-        delete p_sys->env;
+        RECLAIM_ENV(p_sys->env); 
     }
     if( p_sys->scheduler )
     {
-        delete p_sys->scheduler;
+        RECLAIM_ENV(p_sys->env); 
     }
     if( p_sys->p_sdp )
     {
