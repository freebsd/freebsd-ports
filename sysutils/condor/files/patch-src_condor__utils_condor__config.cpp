--- src/condor_utils/condor_config.cpp.orig	2015-04-07 15:10:11 UTC
+++ src/condor_utils/condor_config.cpp
@@ -910,7 +910,7 @@ real_config(const char* host, int wantsQ
 		fprintf(stderr,"\nNeither the environment variable %s_CONFIG,\n",
 				myDistro->GetUc() );
 #	  if defined UNIX
-		fprintf(stderr,"/etc/%s/, nor ~%s/ contain a %s_config source.\n",
+		fprintf(stderr,"/etc/%s/, /usr/local/etc/, nor ~%s/ contain a %s_config source.\n",
 				myDistro->Get(), myDistro->Get(), myDistro->Get() );
 #	  elif defined WIN32
 		fprintf(stderr,"nor the registry contains a %s_config source.\n", myDistro->Get() );
@@ -920,7 +920,7 @@ real_config(const char* host, int wantsQ
 		fprintf( stderr,"Either set %s_CONFIG to point to a valid config "
 				"source,\n", myDistro->GetUc() );
 #	  if defined UNIX
-		fprintf( stderr,"or put a \"%s_config\" file in /etc/%s or ~%s/\n",
+		fprintf( stderr,"or put a \"%s_config\" file in /etc/%s/ /usr/local/etc/ or ~%s/\n",
 				 myDistro->Get(), myDistro->Get(), myDistro->Get() );
 #	  elif defined WIN32
 		fprintf( stderr,"or put a \"%s_config\" source in the registry at:\n"
