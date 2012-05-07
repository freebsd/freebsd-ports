--- src/condor_utils/condor_config.cpp.orig	2012-04-07 14:37:20.000000000 -0500
+++ src/condor_utils/condor_config.cpp	2012-04-07 14:38:55.000000000 -0500
@@ -656,7 +656,7 @@
 		fprintf(stderr,"\nNeither the environment variable %s_CONFIG,\n",
 				myDistro->GetUc() );
 #	  if defined UNIX
-		fprintf(stderr,"/etc/%s/, nor ~%s/ contain a %s_config source.\n",
+		fprintf(stderr,"/usr/local/etc/%s/, nor ~%s/ contain a %s_config source.\n",
 				myDistro->Get(), myDistro->Get(), myDistro->Get() );
 #	  elif defined WIN32
 		fprintf(stderr,"nor the registry contains a %s_config source.\n", myDistro->Get() );
@@ -666,7 +666,7 @@
 		fprintf( stderr,"Either set %s_CONFIG to point to a valid config "
 				"source,\n", myDistro->GetUc() );
 #	  if defined UNIX
-		fprintf( stderr,"or put a \"%s_config\" file in /etc/%s or ~%s/\n",
+		fprintf( stderr,"or put a \"%s_config\" file in /usr/local/etc/%s or ~%s/\n",
 				 myDistro->Get(), myDistro->Get(), myDistro->Get() );
 #	  elif defined WIN32
 		fprintf( stderr,"or put a \"%s_config\" source in the registry at:\n"
